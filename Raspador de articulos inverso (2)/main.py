import validators
from asana_utils import *
from google.cloud import vision
import os
from config import *
from logging import critical, info, error, warning, debug
import logging
import io
import datetime
import time

os.environ["GOOGLE_APPLICATION_CREDENTIALS"] = JSON_CREDENTIALS
LOG_FORMAT = "%(levelname)s|%(asctime)s|%(message)s"

client = asana.Client.access_token(ASANA_API_KEY)
client.headers = {'asana-disable': "new_user_task_lists,new_project_templates"}

banned_words_file = open('banned_words.txt', 'r')
banned_words = banned_words_file.read().splitlines()

def create_directory_if_not_exists(path: str):
    if not os.path.exists(path):
        os.makedirs(path)

def annotate(path):
    """Devuelve imagenes que ha encontrado en otros sitios que son iguales"""
    client = vision.ImageAnnotatorClient()

    if path.startswith('http') or path.startswith('gs:'):
        image = vision.Image()
        image.source.image_uri = path

    else:
        with io.open(path, 'rb') as image_file:
            content = image_file.read()

        image = vision.Image(content=content)

    web_detection = client.web_detection(
        image=image, max_results=50).web_detection

    return web_detection

def get_cloud_urls(annotations):
    """Busca enlaces en annotations"""
    image_web_urls = []
    for page in annotations.pages_with_matching_images: # -> and if page not in urls
        if not any(banned_word in page.url for banned_word in banned_words):
            image_web_urls.append(page.url)
    return image_web_urls


def get_urls_from_desc(desc):
    """Saca descripciones de la tarea de asana"""
    # Buscamos si alguna vez se intentaron coger enlaces
    desc_split = [d.strip() for d in desc.split("\n")]
    try:
        ini = desc_split.index('Pages with matching images:')
    except ValueError:
        # print("First time extracting urls")
        debug("First time extracting urls")
        return []
        # Busca si hay asteriscos
    try:
        fin = desc_split.index(f"{'*'*100}")
    except ValueError:

        fin = None
    urls = desc_split[ini + 1:fin]  # Rango entre Pages with matching images y ******
    urls = [url for url in urls if validators.url(url)]
    debug(f"{len(urls)} links found in the description")
    return urls


def report_desc(urls):
    """Crea un str con los enlaces que se le dan"""
    return "\n\nPages with matching images:\n" + "\n".join(urls)


def embed_desc(desc, final_links):
    """Mete una descripción a mitad de la tarea, entre Pages with matching images y la primera ralla de asteriscos (inicio artículos extraidos) si la encuentra"""
    # Encontrar parte inicial header
    desc_split = [d.strip() for d in desc.split("\n")]
    try:
        ini = desc_split.index('Pages with matching images:')
    except ValueError:
        ini = None
    header = "\n".join([a for a in desc_split[:ini] if a.strip() != ''])
    # print(header)
    # Encontrar parte final footer
    try:
        fin = desc_split.index(f"{'*'*100}")
        footer = "\n".join(desc_split[fin:])
    except ValueError:
        footer = ""
    return f"{header}{report_desc(set(final_links))}\n{footer}"

def main():
    create_directory_if_not_exists("Logs")
    logging.basicConfig(filename=os.path.join("Logs", f"logfile {time.strftime('%Y%m%d-%H%M%S')}.log"),
                        filemode="w",
                        format=LOG_FORMAT,
                        level=logging.DEBUG)
    tasks = get_pending_tasks(client)
    count_tasks = 0
    img_count = 0
    final_number_links = 0
    for task in tasks:
        print(f"Working on {task['name']}")
        info(f"Working on {task['name']}")

        imgs = get_attachments(client, task['gid'])  # enlaces de imagenes
        print(f"Attachments to analyse: {len(imgs)}")
        info(f"Attachments to analyse: {len(imgs)}")
        desc = task['notes']
        task_urls = get_urls_from_desc(desc)  # Enlaces de las tareas si las hubiera

        # Objetivo acumular enlaces de las imagenes que haya adjuntas
        final_links = []
        for img in imgs:
            img_count += 1
            # try:
            # Try to get image
            att_number = imgs.index(img) + 1
            annotations = annotate(img)
            if annotations.pages_with_matching_images:
                matching_urls = get_cloud_urls(annotations)  # Lista de urls
                # Comprobar que no haya duplicados con las otras urls
                # urls = list(set(matching_urls).symmetric_difference(set(task_urls))) # Lo que necesito es juntarlo con los task_urls
                print(f"Images found for attachment {att_number}: {len(matching_urls)}")
                info(f"Images found for attachment {att_number}: {len(matching_urls)}")
                [final_links.append(url) for url in matching_urls]
            else:
                print(f"No images found for attachment number {att_number}")
                info(f"No images found for attachment number {att_number}")

        # Trabajar en la descripción:
        # Es la primera vez, no hay url, simplemente añade las urls a la descripción que haya
        if not task_urls and final_links:
            client.tasks.update_task(task['gid'], {'notes': f"LAST UPDATE: {datetime.datetime.now():%Y-%m-%d %H:%M}. Total links: {len(set(final_links))}.\n{desc}\n{report_desc(set(final_links))}"})
            # print("First update for this task")
            debug("First update for this task")
        # Hay enlaces, los sustituimos por la unión de los antiguos y los nuevos
        elif task_urls and final_links:
            print("Updating description...")
            debug("Updating description")
            debug(f"Google links: {len(set(final_links))}. Previous task links: {len(set(task_urls))}")
            print(f"Google links: {len(set(final_links))}. Previous task links: {len(set(task_urls))}") # fuera
            [final_links.append(url) for url in task_urls]  # Juntamos todos los enlaces
            client.tasks.update_task(task['gid'], {'notes': f"LAST UPDATE: {datetime.datetime.now():%Y-%m-%d %H:%M}. Total links: {len(set(final_links))}.\n{embed_desc(desc, set(final_links))}"})
        else:
            client.tasks.update_task(task['gid'], {'notes': f"LAST UPDATE: {datetime.datetime.now():%Y-%m-%d %H:%M}. Total links: {len(set(final_links))}.\n{desc}"})
        print(f"UPDATED with {len(set(final_links))} links")
        info(f"UPDATED with {len(set(final_links))} links")
        count_tasks += 1
        final_number_links += len(set(final_links))
        print(f"Tasks remaining: {len(tasks)-count_tasks}")

    print(f"Proccess finisehd! Total images requests: {img_count}. Total links found: {final_number_links}")
    info(f"Proccess finisehd! Total images requests: {img_count}. Total links found: {final_number_links}")

if __name__ == '__main__':
    main()
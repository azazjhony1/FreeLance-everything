from config import PROJECT_ID
import asana
# ASANA UTILS
def get_pending_tasks(client):
  result = client.tasks.find_by_project(PROJECT_ID,opt_fields=['completed','notes','name'])
  return [task for task in result if task['completed'] == False]

def get_attachments(client,gid):
  img_url = []
  att = client.attachments.find_by_task(gid)
  for a in att:
    details = client.attachments.get_attachment(a['gid'])
    img_url.append(details['download_url'])

  return img_url
def append_task_desc(client, gid, new_desc, sep="*" * 100):
    """Appends new description to a given task"""
    desc = client.tasks.get_task(gid)['notes']
    final_desc = f"{desc}\n{sep}\n{new_desc}"
    return client.tasks.update_task(gid, {'notes': final_desc})
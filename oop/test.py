import csv
import datetime


current_time_step = ""
with open("data.csv", "r") as file:
        reader = csv.reader(file)
        for row in reader:
            time = row[0]
            if time > current_time_step:
                current_time_step = time    
                break   
        print(current_time_step)
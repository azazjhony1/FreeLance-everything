import datetime
import csv
class Investor:
    def __init__(self):
        self.balance = 0.0
        self.portfolio = {}

    def buy(self, product, price, quantity):
        # Update the investor's balance and portfolio
        self.balance -= price * quantity
        if product in self.portfolio:
            self.portfolio[product] += quantity
        else:
            self.portfolio[product] = quantity

    def sell(self, product, price, quantity):
        # Update the investor's balance and portfolio
        self.balance += price * quantity
        self.portfolio[product] -= quantity


class Exchange:

    products = ['ETH/BTC','DOGE/BTC']

    def __init__(self):
        self.products = []
        self.time = datetime.datetime.now()

    def add_product(self, product):
        self.products.append(product)

    def get_average_price(self, product, bid_ask, timesteps):
        # Compute the average price for the given product over the given number of time steps
        avg_price = 0.0
        return avg_price

    def get_max_price(self, product, bid_ask):
    # Initialize the maximum price to a very small value
     max_price = float("-inf")

    # Retrieve the current price data for the product
    #  price_data = get_current_price_data(product)
     price_data = 500.654

    # Iterate through the price data and find the maximum bid or ask price
     for data in price_data:
        if bid_ask == "bid":
            # Update the maximum bid price if the current bid price is higher
            max_price = max(max_price, data["bid"])
        elif bid_ask == "ask":
            # Update the maximum ask price if the current ask price is higher
            max_price = max(max_price, data["ask"])

     return max_price


    def get_products(self):
        # Return a list of all the products available on the exchange
        return self.products

    def get_min_price(self, product, bid_ask):
    # Initialize the minimum price to a very large value
     min_price = float("inf")

    # Retrieve the current price data for the product
    #  price_data = get_current_price_data(product)
     price_data = 500.54


    # Iterate through the price data and find the minimum bid or ask price
     for data in price_data:
        if bid_ask == "bid":
            # Update the minimum bid price if the current bid price is lower
            min_price = min(min_price, data["bid"])
        elif bid_ask == "ask":
            # Update the minimum ask price if the current ask price is lower
            min_price = min(min_price, data["ask"])

     return min_price



    def step(self):
        # Move to the next time step
        self.time += datetime.timedelta(seconds=6)


class Command:
    def __init__(self, name, func, num_args, help_text):
        self.name = name
        self.func = func
        self.num_args = num_args
        self.help_text = help_text

    def execute(self, exchange, investor, *args):
        # Check if the correct number of arguments was provided
        #print(args)
        if len(args) != self.num_args:
            return f"Invalid number of arguments for {self.name} command. Expected {self.num_args}, got {len(args)}."

        # Execute the command function with the exchange, investor, and additional arguments
        return self.func(exchange, investor, *args)

def execute_help(exchange, investor, *args):
    if args:
        # Get the command name and any additional arguments
        command_name = args[0]
        command = commands.get(command_name)
        if command is None:
            return f"Invalid command: {command_name}"
        return command.help_text
    else:
        # Return a list of all available commands
        return "The available commands are:\n" + "\n".join(f"{command.name}: {command.help_text}" for command in commands.values())

def execute_prod(exchange, investor, *args):
    


    with open( "data.csv", "r") as file:
        reader = csv.reader(file)
        header = next(reader)
        data = []
        for row in reader:
            for i in range(len(header)):
                str = row[1]
            if(data.__contains__(str)):
                continue  
            else:
                data.append(str)
        
    return data

def execute_min(exchange, investor, *args):
    product, bid_ask = args
    with open("data.csv", "r") as file:
        reader = csv.reader(file)
        header = next(reader)
        min=9999999
        
    
        for row in reader:
            for i in range(len(header)):
                str3 = row[1]
                str4 = row[2]

                if(str3 == product and str4 == bid_ask):
                    str2=float(row[3])
                    if(str2<min):
                        min=str2


    return f"The min {bid_ask} for {product} is {min}."

def execute_max(exchange, investor, *args):
    product, bid_ask = args
    with open("data.csv", "r") as file:
        reader = csv.reader(file)
        header = next(reader)
        max= -9999999
        
        #print(time)
        for row in reader:
            for i in range(len(header)):
                str3 = row[1]
                str4 = row[2]

                if(str3 == product and str4 == bid_ask):
                    str2=float(row[4])
                    if(str2>max):
                        max=str2
    return f"The max {bid_ask} for {product} is {max}."

def execute_avg(exchange, investor, *args):
    product, bid_ask, timesteps = args

    with open("data.csv", "r") as file:
        reader = csv.reader(file)
        header = next(reader)
        sum=0
        num=1
        
        for row in reader:
                str1 = row[1]
                str2 = row[2]
                str0 = row[0]
                time = str0[11:13]
                #print(time,str1,str2)
                if(time.__eq__(timesteps) and str1.__eq__(product) and str2.__eq__(bid_ask)):
                    sum+=float(row[4])
                    num+=1
        avg = sum/num
        #print(avg)
                    
                    
    return f"The average {product} {bid_ask} price over the last {timesteps} timesteps was {avg}."

def execute_predict(exchange, investor, *args):
    max_min, product, bid_ask = args
    # Use a moving average or another prediction algorithm to predict the max or min ask or bid for the sent product for the next time step
    with open("data.csv", "r") as file:
        with open("data.csv", "r") as file:
            reader = csv.reader(file)
            header = next(reader)
            maxsum1=[]
            minsum1=[]
            window = 10
            for row in reader:
                    str1 = row[1]
                    str2 = row[2]
                    #print(time,str1,str2)
                    if(str1.__eq__(product) and str2.__eq__(bid_ask) and max_min.__eq__("max")):
                        maxsum1.append(float(row[4]))
                    if(str1.__eq__(product) and str2.__eq__(bid_ask) and max_min.__eq__("min")):
                        minsum1.append(float(row[3]))                    
            maxsum2=maxsum1[-window:]
            minsum2=minsum1[-window:]
            maxsum2 = sum(maxsum2)
            minsum2 = sum(minsum2)

            mov_avg1 = maxsum2/window
            mov_avg2 = minsum2/window
    if(max_min.__eq__("max")):
        return f"The {max_min} {bid_ask} for {product} might be {mov_avg1}."
    if(max_min.__eq__("min")):
        return f"The {max_min} {bid_ask} for {product} might be {mov_avg2}."

def execute_time(exchange, investor, *args):
    current_time = datetime.datetime.now()
    return f"The current time is {current_time}."

current_time_step = ""
def execute_step(exchange, investor, *args):
    with open("data.csv", "r") as file:
            reader = csv.reader(file)
            global current_time_step
            for row in reader:
                time = row[0]
                if time > current_time_step:
                    current_time_step = time    
                    break
    return f"Moved to the next time step. The current time is {current_time_step}."

def execute_exit(exchange, investor, *args):
    print("Exiting...")
    exit()

def execute_help_specific(args):
    s = args
    #print(s)
    if(s=="prod"):
        return f"List all available products on the exchange. Usage: prod"
    if(s=="min"):
        return f"Find the minimum bid or ask for a product in the current time step. Usage: min product bid/ask"
    if(s=="max"):
        return f"Find the maximum bid or ask for a product in the current time step. Usage: max product bid/ask"
    if(s=="avg"):
        return f"Compute the average ask or bid for a product over the last n timesteps. Usage: avg product bid/ask n"
    if(s=="predict"):
        return f"Use a moving average or another prediction algorithm to predict the max or min ask or bid for the sent product for the next time step. Usage: predict max/min product bid/ask"
    if(s=="time"):
        return f"Display the current time. Usage: time"
    if(s=="step"):
        return f"Move to the next time step. Usage: step"
    if(s=="help"):
        return f"List all available commands or display help for a specific command. Usage: help [command]"
    if(s=="exit"):
        return f"Exit the program. Usage: exit"
    else:
        return "Command not found."
# Create a dictionary of all available commands
commands = {
    "help": Command("help", execute_help, 0, "List all available commands or display help for a specific command. Usage: help [command]"), 
    "prod": Command("prod", execute_prod, 0, "List all available products on the exchange. Usage: prod"),
    "min": Command("min", execute_min, 2, "Find the minimum bid or ask for a product in the current time step. Usage: min product bid/ask"),
    "max": Command("max", execute_max, 2, "Find the maximum bid or ask for a product in the current time step. Usage: max product bid/ask"),
    "avg": Command("avg", execute_avg, 3, "Compute the average ask or bid for a product over a specified number of time steps. Usage: avg product ask/bid timesteps"),
    "predict": Command("predict", execute_predict, 3, "Predict the max or min ask or bid for a product for the next time step. Usage: predict max/min product ask/bid"),
    "time": Command("time", execute_time, 0, "Display the current time in the dataset. Usage: time"),
    "step": Command("step", execute_step, 0, "Move to the next time step. Usage: step"),
    "exit": Command("exit", execute_exit, 0, "Exit the program. Usage: exit")
}

class CommandProcessor:
    def __init__(self):
        self.exchange = Exchange()
        self.investor = Investor()

    def execute_command(self, tokens):
        # Get the command name and any additional arguments
        command_name = tokens[0]
        command = commands.get(command_name)
        if(command_name=="help"):
            if(len(tokens)==2):
                return execute_help_specific(tokens[1])
        if command is None:
            return f"Invalid command: {command_name}"
        return command.execute(self.exchange, self.investor, *tokens[1:])

def tokenize(input_str):
    # Split the input string into a list of tokens
    tokens = input_str.strip().split()
    return tokens

def main():
    command_processor = CommandProcessor()

    while True:
        # Read input from the user
        input_str = input("Enter a command: ")

        # Check if the user entered the "exit" command
        if input_str == "exit":
            break

        # Tokenize the input string
        tokens = tokenize(input_str)

        # Process the input and produce the output
        try:
            output = command_processor.execute_command(tokens)
        except Exception as e:
            output = f"An error occurred while processing the command: {e}"

        # Print the output
        print(output)

if __name__ == "__main__":
    main()

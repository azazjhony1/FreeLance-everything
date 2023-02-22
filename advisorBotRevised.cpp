#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include<iostream>
#include <iomanip>
#include <vector>
#include <string>



using namespace std;

string printMenu() { // prints introduction to the advisorbot when the program first initializes
	string s="";
	cout << "Welcome to Advisorbot. Advisorbot is a command line program that can carry out various" << endl;
	cout << "tasks to help a cryptocurrency investor analyse the data available on an exchange." << endl;
	cout << "======================================================================================" << endl;
	cout << "To begin, please enter a command, or type 'help' for a list of commands" << endl;
	getline(cin, s);


	return s;
}

vector<string> userOptionTokenise(string userOption) { // tokenise user's input into a vector
	vector<string> userOptionLine;
	signed int start, end;
	string token;
	start = userOption.find_first_not_of(" ", 0);
	do {
		end = userOption.find_first_of(" ", start);
		if (start == userOption.length() || start == end) break;
		if (end >= 0) token = userOption.substr(start, end - start);
		else token = userOption.substr(start, userOption.length() - start);
		userOptionLine.push_back(token);
		start = end + 1;
	} while (end > 0);
	return userOptionLine;
}


void printHelp(string userOption) { //print help function, when prints all available commands, and also prints each command's use and purpose
	if (userOption == "help prod") {
		 cout << "Command: prod" <<  endl;
		 cout << "Purpose: List all available products." <<  endl;
		 cout << "Example: user> help prod" <<  endl;
		 cout << "         advisorbot> ETH/BTC, DOGE/BTC etc." <<  endl;
	} else if (userOption == "help min") {
		 cout << "Command: min product bid/ask" <<  endl;
		 cout << "Purpose: Find the minimum bid or ask for product in current time step" <<  endl;
		 cout << "Example: user> min ETH/BTC ask" <<  endl;
		 cout << "         advisorbot> The min ask for ETH/BTC is 0.0248261" <<  endl;
	} else if (userOption == "help max") {
		 cout << "Command: max product bid/ask" <<  endl;
		 cout << "Purpose: Find the maximum bid or ask for product in current time step" <<  endl;
		 cout << "Example: user> max ETH/BTC ask" <<  endl;
		 cout << "         advisorbot> The max ask for ETH/BTC is 0.0251581" <<  endl;
	} else if (userOption == "help avg") {
		 cout << "Command: avg product ask/bid timesteps" <<  endl;
		 cout << "Purpose: Compute the average ask or bid for the sent product over the sent number of time steps" <<  endl;
		 cout << "Example: user> avg ETH/BTC ask 10" <<  endl;
		 cout << "         advisorbot> The average ETH/BTC ask price over the last 10 timesteps was 0.0249612" <<  endl;
	} else if (userOption == "help predict") {
		 cout << "Command: predict max/min product ask/bid" <<  endl;
		 cout << "Purpose: Predict the max or min ask or bid for the sent product for the next time step, requires user to be at minimum the 5th timestamp" <<  endl;
		 cout << "Example: user> predict max BTC/USDT bid" <<  endl;
		 cout << "         advisorbot> The predicted max ask price for ETH/BTC is 0.0222814 for the next time frame" <<  endl;
	} else if (userOption == "help liquidity") {
		 cout << "Command: liquidity product" <<  endl;
		 cout << "Purpose: Averages the liquidity of product for the past 10 timesteps, uses bid-ask spread as the measure" <<  endl;
		 cout << "Example: user> liquidity DOGE/BTC" <<  endl;
		 cout << "         advisorbot> The average liquidity of DOGE/BTC for the previous 10 steps is 4.07%" <<  endl;
	} else if (userOption == "help time") {
		 cout << "Command: time" <<  endl;
		 cout << "Purpose: State current time in dataset, i.e. which timeframe are we looking at" <<  endl;
		 cout << "Example: user> time" <<  endl;
		 cout << "         advisorbot> Current time is 2020/03/17 17:01:24, timestamp: 5" <<  endl;
	} else if (userOption == "help step") {
		 cout << "Command: step <no.>" <<  endl;
		 cout << "Purpose: Moves to the next specified amount of timesteps, defaults to 1" <<  endl;
		 cout << "Example: user> step" <<  endl;
		 cout << "         advisorbot> Now at 2020/03/17 17:01:30" <<  endl;
	}else if (userOption == "help") {
		cout << "The available commands are: help, help <cmd>, prod, min, max, avg, predict, liquidity, time, step <no>" << endl;
		 cout << "======================================================================================================" << endl;
	} else  
	 { // if none of the above was matched, returns invalid input statement and tells user to type help for all valid commands
		 cout << "Invalid input. Type 'help' to display all valid commands" <<  endl;
	}
}


int read(int i) {
    // Open the file
    ifstream file("Book1.csv");
    vector<string> date;
    vector<string> products;
	vector<string> bid_ask;
	vector<float> low_price;
	vector<float> high_price;
	
    // Read each line of the file
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, field, ',')
        date
        cout << endl;
    }

    return 0;
}


int main(){
	
	string str = printMenu();
	cout<<str;
	
		printHelp(str);
	
	
	
}

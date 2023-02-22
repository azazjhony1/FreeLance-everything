#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<vector>
using namespace std;

int main() {
    // Open the file
    ifstream file("Book1.csv");
	vector<string> date;
    vector<string> products;
	vector<string> bid_ask;
	vector<float> low_price;
	vector<float> high_price;
	
    
    string line;
    while (getline(file, line)) {
       string s="";
       for(int i=0;i<7;i++)
        s=s+line[i];
    	date.push_back(s);
    	
    	s="";
    	
       for(int i=8;i<15;i++)
        s=s+line[i];
    	products.push_back(s);
    	
    	s="";
    	
       for(int i=16;i<19;i++)
        s=s+line[i];
    	bid_ask.push_back(s);
    	
    		s="";
    	
       for(int i=20;i<19;i++)
        s=s+line[i];
    	bid_ask.push_back(s);
    	
        
    }
    for(int i=0;i<bid_ask.size();i++){
    	cout<<bid_ask.at(i)<<endl;
	}
	return 0;
}


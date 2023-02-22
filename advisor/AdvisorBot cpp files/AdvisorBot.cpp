// Merkelrex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "OrderBookEntry.h"
#include "AdvisorMain.h"
#include "CSVReader.h"


int main() {
	AdvisorMain a{"Book1.csv"};
	a.init();
	
}




#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "PrintObjects.h"

/*
Description:
	Default constructor
*/
PrintObjects::PrintObjects() {
	vectorItemsHolder = {};
}

/*
Description:
	Iterates through and prints a vector<string>
*/
void PrintObjects::Execute_Print(std::vector<std::string> printVector) {
	for (int i = 0; i < printVector.size(); i++) { // for statement iterates as many times as the size of the vector
		std::cout << "   " << printVector.at(i) << std::endl; // prints the vector item at position i
	}

	return;
}

/*
Description:
	Function that reads line by line and stores it in a vector
*/
void PrintObjects::Set_File_Vector_Items(std::string fileName) {
	std::ifstream inFS; // creates ifstream object for dealing with files
	std::string fileLine; // a string to hold a line from the file one at a time

	inFS.open(fileName); // opens file for reading
	
	if (!inFS.is_open()) { // ensures that the file opens properly
		std::cout << "Could not get file items." << std::endl;
		return;
	}

	while (getline(inFS, fileLine)) { // while loop runs and builds the vector from the file's lines so long as there are lines to get
		vectorItemsHolder.push_back(fileLine); // adds the next line to the next vector index
	}

	if (!inFS.eof()) { // check to ensure the end of file is reached
		std::cout << "Could not get file items." << std::endl;
		return;
	}

	inFS.close(); // close file

	return;
}

/*
Description:
	Retrieves vectorItemsHolder
*/
std::vector<std::string> PrintObjects::Get_Item_Holder_Vector() {
	return vectorItemsHolder;
}

/*
Description:
	Clears vectorItemsHolder by setting it to an empty vector
*/
void PrintObjects::Reset_Items_Holder_Vector() {
	vectorItemsHolder = {};

	return;
}

/*
Description:
	Prints a histogram from a file's lines using a custom character.
	File must be set up with an item name -- space -- number
	such as:
	
	Computers 4
	Knives 2
	Collared Shirt 12

	etc.
*/
void PrintObjects::Print_Histogram(std::string fileName, char symbol) {
	std::ifstream inFS; // creates ifstream object to interact with files
	std::string tempHolder; // holds each line of the file as it iterates through
	std::string tempItem; // string used to divide tempHolder into a string and an int
	size_t tempIndex; // holds the string index of the last space character for substring creation
	int tempNum; // int used to divide tempHolder into a string and an int 

	inFS.open(fileName); // opens the file

	if (!inFS.is_open()) { // checks that the file opened
		std::cout << "Could not get file items." << std::endl;
		return;
	}

	std::cout << std::endl; // a newline for aesthetic reason

	while (getline(inFS, tempHolder)) { // while loop that iterates through the file line by line until there is no more lines. Stores each line in tempHolder one by one
		std::string tempHistogram; // string used to store an items histogram graphic until it's ready to be printed (Declaring here resets with each loop iteration)
		tempIndex = tempHolder.find_last_of(' '); // sets tempIndex to the last instance of a space character
		tempItem = tempHolder.substr(0, tempIndex); // sets tempItem to the beginning of tempHolder until tempIndex (the item without the quantity at the end)
		tempNum = stoi(tempHolder.substr(tempIndex)); // sets tempNum to the number at the end of tempHolder
		
		for (int i = 0; i < tempNum; i++) { // for loop that builds the histogram for printing
			tempHistogram += symbol; // concatonates the histogram for the quantity of tempHolder
		}
		std::cout << std::setw(17); // sets with to 17, an arbitrary number I liked the look of
		std::cout << std::right << tempItem << "|" << tempHistogram << std::endl; // prints the item, a |, and the histogram. Such as: Potatos|######
	}

	if (!inFS.eof()) { // checks if we reached end of file
		std::cout << "Could not get file items." << std::endl;
		return;
	}

	inFS.close(); // closes file

	return;
}

/*
Description:
	Prints a single line to a custom length with a custom character
*/
void PrintObjects::Print_Border(int length, char symbol) {
	for (int i = 0; i < length; i++) { // for loop that runs and prints as many time as the provided length
		std::cout << symbol; // prints the custom character
	}
	
	std::cout << std::endl; // prints a newline once the border line is printed

	return;
}

/*
Description:
	Function that prints an item and a quantity. Specific for the single item sold aspect of Corner Grocer's program. 
Example:
	Print_Single+Item_Sold(searchItem, 12); (where searchItem = "Lettuce")
Output:
	C++ will print on the screen:
		Lettuce sold: 12
Output for quantity of 0:
	C++ will print on the screen:
		No Lettuce sold.
*/
void PrintObjects::Print_Single_Item_Sold(std::string purchasedItem, int quantity) {
	if (quantity == 0) { // checks for quantity of 0. Not needed, but I feel it's cleaner to display a custom statement for 0
		std::cout << "No " << purchasedItem << " sold." << std::endl; // prints message
	}
	else { // handles any quantity other than 0
		std::cout << std::endl << purchasedItem << " sold: " << quantity << std::endl; // prints message
	}

	return;
}
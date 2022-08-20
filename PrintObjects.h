#ifndef CORNERGROCERITEMTRACKER_PRINTOBJECTS_H
#define CORNERGROCERITEMTRACKER_PRINTOBJECTS_H
#include <vector>
#include <string>

/*
	This class is intended to be modular for many types of printing. Parts of it are specific to printing menus. 
	It could arguably be split into seperate classes, but that seemed overkill for this project
*/
class PrintObjects {
public:
	PrintObjects(); // default constructor
	void Execute_Print(std::vector<std::string>); // iterates and prints through a vector<string>
	void Set_File_Vector_Items(std::string); // builds a vector from a file, line by line
	void Reset_Items_Holder_Vector(); // empties vector
	std::vector<std::string> Get_Item_Holder_Vector(); // getter for vectorItemsHolder
	void Print_Histogram(std::string, char); // prints a histogram from a file using a custom character
	void Print_Border(int, char); // prints a line of a set length with a custom character
	void Print_Single_Item_Sold(std::string, int); // prints a line formatted for this specific program

private:
	std::vector<std::string> vectorItemsHolder; // holds lines to be printed from a file
};

#endif
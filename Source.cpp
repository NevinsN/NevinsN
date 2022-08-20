#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <vector>
#include "PrintObjects.h"
#include "InputControllers.h"

using namespace std;

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

int main() {	
	PrintObjects programPrints; // object for menu printing
	InputControllers userInput; // object for handling user input

	while (userInput.Get_User_Int() != 4) { // while loop that holds the program and will run until the user enters 4
		programPrints.Reset_Items_Holder_Vector(); // empties the menu vector. Necessary or else the menu will keep duplicating itself in the vector
		programPrints.Set_File_Vector_Items("menuItems.txt"); // sets vectorItemHolder to any file's contents, intended for customizing menus via .txt files
		cout << endl; // newline for aesthetic purposes
		programPrints.Print_Border(37, '*'); // prints a border line
		programPrints.Execute_Print(programPrints.Get_Item_Holder_Vector()); // Prints out the contents of vectorItemHolder, in this case the menu options
		programPrints.Print_Border(37, '*'); // prints a border line
		
		userInput.Set_User_Int(userInput.User_Input_Int()); // prompts user for an integer and sets it to userInt

		switch (userInput.Get_User_Int()) { // switch statement using userInput's userInt as a parameter
		case 1:
			system("cls"); // clears the screen
			callIntFunc("PrintAllItemFrequencies", "dailyPurchases.txt"); // calls Python code to print every item and their frequency in a list
			break;
		case 2:
			userInput.Set_User_String(userInput.User_Input_String()); // prompts a string from the user and stores it as userInput's userString
			// this line calls Print_Single_Item_Sold using userInput's userString and a python call to get the quantity. Python requires a fileName%searchTerm format to work properly
			programPrints.Print_Single_Item_Sold(userInput.Get_User_String(), callIntFunc("SingleItemFrequency", "dailyPurchases.txt%" + userInput.Get_User_String()));
			break;
		case 3:
			callIntFunc("CreateFrequencyDat", "dailyPurchases.txt"); // calls Python program CreateFrequencyDat to create frequency.dat with the daily sales text file as the second parameter
			programPrints.Print_Histogram("frequency.dat", '#'); // prints the histogram with a custom character
			break;
		case 4:
			system("cls"); // clears screen to keep it all tidy
			break;
			// validates that input was an int between 1 and 4. 
			//Recall that if a non-integer was entered, it flags the user and passes through 0, thus triggering the default statement
		default: 
			system("cls"); // clears screen to keep it all tidy
			cout << "Invalid menu options. Try again." << endl;
			break;
		}
	}
		
	return 0;
}
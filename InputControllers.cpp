#include <iostream>
#include <Windows.h>
#include <string>
#include "InputControllers.h"

/*
Description:
	Default constructor
*/
InputControllers::InputControllers() {
	userInt = 0;
	userString = "";
}

/*
Description:
	Function used to get and validate user input so an integer can be returned. Will return 0 if a non-integer is entered
*/
int InputControllers::User_Input_Int() {
	int userInput; // holds user input

	// prompts and gets user input
	std::cout << "Enter Menu Selection: ";
	std::cin >> userInput;
	system("cls"); // clears the screen to keep everything tidy

	if (std::cin.fail()) { // if statement validates input. if cin.fail() is true, then a non-integer was input
		// these two will clear out the input buffer and prep for the next cin
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		system("cls"); // clears the screen to keep everything tidy

		return 0; // 0 means an integer wasn't entered. Invalid entries are not dealt with in this function, but passed to the switch statement in main
	}
	else {
		system("cls"); // clears the screen to keep everything tidy

		return userInput; // if an integer was input, returns userInput for use
	}
}

/*
Description:
	Function is used to get a string from the user
*/
std::string InputControllers::User_Input_String() {
	std::string userInput; // variable holds user input

	system("cls"); // clears the screen to keep everything tidy

	// prompts and gets user input
	std::cin.ignore(); // clears newline from the cin buffer
	std::cout << "Enter desired search term: ";
	std::getline(std::cin, userInput);

	system("cls"); // clears the screen to keep everything tidy

	return userInput;
}

/*
Description:
	Takes in an integer--inputInt--and sets userInt to it.
*/
void InputControllers::Set_User_Int(int inputInt) {
	userInt = inputInt;
	return;
}

/*
Description:
	Retrieves userInt
*/
int InputControllers::Get_User_Int() {
	return userInt;
}

/*
Description:
	Takes in a string--inputString--and sets userString to it.
*/
void InputControllers::Set_User_String(std::string inputString) {
	userString = inputString;
	return;
}

/*
Description:
	Retrieves userString
*/
std::string InputControllers::Get_User_String() {
	return userString;
}
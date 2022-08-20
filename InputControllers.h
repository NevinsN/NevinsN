#ifndef CORNERGROCERITEMTRACKER_INPUTCONTROLLERS_H
#define CORNERGROCERITEMTRACKER_INPUTCONTROLLERS_H
#include <string>

class InputControllers {
public:
	InputControllers(); // default constructor
	int User_Input_Int(); // prompts user for an integer
	std::string User_Input_String(); // prompts user for a string
	void Set_User_Int(int inputInt); // setter for userInt
	int Get_User_Int(); // getter for userInt
	void Set_User_String(std::string inputString); // setter for userString
	std::string Get_User_String(); // getter for userString

private:
	int userInt; // holds a user's integer
	std::string userString; // holds a user's string
};

#endif

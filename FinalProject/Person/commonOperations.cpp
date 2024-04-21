/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 4
Date Assigned: 04/05/2024
Due Date: 04/20/2024
Description:
constains function definition for the commonOperations.h file
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)
*/
#include "commonOperations.h"


/*Pre: none
* Post: console cleared
* Purpose: To clear the console
*/
void clearScreen()
{
	system("cls");
}

/*Pre: none
* Post: none
* Purpose: To pause the program
*/
void pause()
{
	std::cout << "Press any key to continue" << std::endl;
	getch();//value returned does not matter
	clearScreen();
}//getch method found here https://stackoverflow.com/questions/65255313/how-can-i-replace-the-input-character-with-the-character

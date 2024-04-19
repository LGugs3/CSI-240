
#include "commonOperations.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>

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
}

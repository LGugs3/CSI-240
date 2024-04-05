/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Lab7
Date Assigned: 04/02/2024
Due Date: 04/06/2024
Description:
Contains definitions for the Method2 class
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
#include "method2.h"

/*Pre: none
* Post: initialized Method2 variable
* Purpose: to initilize Method1 variable with default constructor
*/
Method2::Method2() : Encryption()
{
}

/*Pre: none
* Post: initialized Method2 variable
* Purpose: to initilize Method1 variable with custom constructor
*/
Method2::Method2(string inputFile, string outputFile) : Encryption(inputFile, outputFile, 0)
{
}

/*Pre: none
* Post: initialized Method2 variable
* Purpose: to initilize Method2 variable with copy constructor
*/
Method2::Method2(Method2& obj) : Encryption(obj)
{
}

/*Pre: none
* Post: Method2 type variable destroyed
* Purpose: To safely destory variable
*/
Method2::~Method2()
{
}

/*Pre: plaintext charater
* Post: cipehrtext character
* Purpose: To translate plaintext character to ciphertext
*/
char Method2::transform(char ch)
{
	return static_cast<char>(ch ^ mKey);
}


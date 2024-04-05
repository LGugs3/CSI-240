/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Lab7
Date Assigned: 04/02/2024
Due Date: 04/06/2024
Description:
fxn definitions for Method1 class
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
#include "method1.h"

/*Pre: none
* Post: initialized Method1 variable
* Purpose: to initilize Method1 variable with default constructor
*/
Method1::Method1() : Encryption()
{
}

/*Pre: none
* Post: initialized Method1 variable
* Purpose: to initilize Method1 variable with custom constructor
*/
Method1::Method1(string inputFile, string outputFile) : Encryption(inputFile, outputFile, 0)
{
}

/*Pre: none
* Post: initialized Method1 variable
* Purpose: to initilize Method1 variable with copy constructor
*/
Method1::Method1(Method1& obj) : Encryption(obj)
{
}

/*Pre: none
* Post: Method1 type variable destroyed
* Purpose: To safely destory variable
*/
Method1::~Method1()
{
}

/*Pre: plaintext charater
* Post: cipehrtext character
* Purpose: To translate plaintext character to ciphertext
*/
char Method1::transform(char ch)
{
	return ch + mKey;
}

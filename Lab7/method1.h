/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Lab7
Date Assigned: 04/02/2024
Due Date: 04/06/2024
Description:
header file for Method1 class
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
#include "encryption.h"

class Method1 : public Encryption
{
	public:
		Method1();
		Method1(string inputFile, string outputFile);
		Method1(Method1& obj);
		~Method1();

		virtual char transform(char ch);
};
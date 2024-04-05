/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Lab7
Date Assigned: 04/02/2024
Due Date: 04/06/2024
Description:
The main for Lab7
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

int main()
{
	string inputFileName, outputFileName;
	int key;

	cout << "Input file name: ";
	getline(cin, inputFileName);

	cout << "Output file name: ";
	getline(cin, outputFileName);

	do
	{
		cout << "Enter key: ";
		cin >> key;
	} while (key > 26);

	Method1 test = Method1(inputFileName, outputFileName);
	test.setKey(key);
	test.encrypt();

	Method2 test2 = Method2(inputFileName, outputFileName);
	test.encrypt();

	return 0;
}
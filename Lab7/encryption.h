
#include <iostream>
/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Lab7
Date Assigned: 04/02/2024
Due Date: 04/06/2024
Description:
header file for Encryption class
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
#include <fstream>
#include <string>

using namespace std;

class Encryption
{
	protected:
		string mIfName;
		string mOfName;
		int mKey;
	public:
		Encryption();
		Encryption(string inputFile, string outputFile, int key);
		Encryption(Encryption& obj);
		~Encryption();

		int getKey();

		void setKey(int key);

		void encrypt();

		virtual char transform(char ch) = 0;

};
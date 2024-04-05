/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Lab7
Date Assigned: 04/02/2024
Due Date: 04/06/2024
Description:
fxn definition for Encryption class
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

/*Pre: none
* Post: initialized Encryption class
* Purpose: to initilize an Encryption type variable with default constructor
*/
Encryption::Encryption()
{
	mIfName = "unset File";
	mOfName = "unset File";
	mKey = 0;
}

/*Pre: input & output file name, key
* Post: initialized Encryption class with given inputs
* Purpose: Initialize Encryption type variable with custom constructor
*/
Encryption::Encryption(string inputFile, string outputFile, int key)
{
	mIfName = inputFile;
	mOfName = outputFile;
	mKey = key;
}

/*Pre: Encryption object
* Post: Initialized Encryption class
* Purpose: Initialize Encryption type variable with copy constructor
*/
Encryption::Encryption(Encryption& obj)
{
	mIfName = obj.mIfName;
	mOfName = obj.mOfName;
	mKey = obj.mKey;
}

/*Pre: none
* Post: Encryption type variable destroyed
* Purpose: To safely destory variable
*/
Encryption::~Encryption()
{
}

/*Pre: none
* Post: the current key
* Purpose: to return the current key
*/
int Encryption::getKey()
{
	return mKey;
}

/*Pre: new key
* Post: set the key to the new key
* Purpose: To set the key to the input
*/
void Encryption::setKey(int key)
{
	mKey = key;
}

/*Pre: none
* Post: ciphertext
* Purpose: To encrypt given plaintext
*/
void Encryption::encrypt()
{
	ifstream fin;
	ofstream out;

	fin.open(mIfName);
	if (fin.fail())
	{
		cout << "fin failed to open" << endl;
		return;
	}


	string plainText, cipherText;
	//gets plaintext
	getline(fin, plainText);
	fin.close();
	if (plainText.length() == 0)
	{
		cout << "fin file is empty" << endl;
		return;
	}

	int i;
	for (i = 0; i < plainText.length(); i++)
	{
		cipherText += transform(plainText[i]);
	}

	out.open(mOfName);
	out << cipherText << endl;
	out.close();
}

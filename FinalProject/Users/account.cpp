/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part1
Date Assigned: 04/05/2024
Due Date: 04/09/2024
Description:
Contains the Member and friend functions of the Account class
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
#include "account.h"

/**********************************************************************************************
* Member Functions
***********************************************************************************************/

/*Pre: None
* Post: Initialized Account object
* Purpose: Initialize Account object with default constructor
*/
Account::Account()
{
	mId = "";
	mPassword = "";
}

/*Pre: two strings with id and password
* Post: Initialized Account object
* Purpose: To initialize Account object with custom constructor
*/
Account::Account(std::string id, std::string password)
{
	mId = id;
	mPassword = password;
}

/*Pre: Account object
* Post: Initialized Account object
* Purpose: To initialize Accout object with copy constructor
*/
Account::Account(const Account& obj)
{
	mId = obj.mId;
	mPassword = obj.mPassword;
}

/**********************************************************************************************
* Operator Overloads
***********************************************************************************************/


/*Pre: Account object
* Post: bool if the two Account objects are the same
* Purpose: To compare two Account object to see if they are the same
*/
Account Account::operator=(Account rhs)
{
	mId = rhs.mId;
	mPassword = rhs.mPassword;

	return *this;
}
bool Account::operator==(Account rhs)
{
	return (mId == rhs.mId && mPassword == rhs.mPassword);
}

/*Pre: Account object
* Post: bool if the two Account objects are not the same
* Purpose: To compare two Account objects to see if they are different
*/
bool Account::operator!=(Account rhs)
{
	return (mId != rhs.mId && mPassword != rhs.mPassword);
}

/*Pre: istream on left and Account object on right
* Post: Account object's variables set to user's input
* Purpose: To set an Account object's variables to the user's input
*/
std::istream& operator>>(std::istream& input, Account& obj)
{
	std::cout << "Enter ID: ";
	getline(input, obj.mId);
	std::cout << "Enter Password: ";
	getline(input, obj.mPassword);

	return input;
}

/*Pre: ostream on the left and Account object on the right
* Post: Account object mId and mPassword printed to the console
* Purpose: To print mId and mPassword to the console
*/
std::ostream& operator<<(std::ostream& output, Account& obj)
{
	output << "ID: " << obj.mId << std::endl
		   << "Password: " << obj.mPassword << std::endl;

	return output;
}

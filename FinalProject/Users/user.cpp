/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part1
Date Assigned: 04/05/2024
Due Date: 04/09/2024
Description:
Contains the Member and friend functions of the USer class
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
#include "user.h"

/*Pre: none
* Post: Initialized User object
* Purpose: To initialize User object with default constructor
*/
User::User()
{
	mAccounts = nullptr;
	mAccountInUse = 0;
}

/*Pre: User object
* Post: initialized User object
* Purpose: To initialize User object using the copy constructor
*/
User::User(const User& obj)
{
	if (mAccounts != nullptr) { delete[] mAccounts; }

	mAccountInUse = obj.mAccountInUse;

	int i;
	mAccounts = new Account[mAccountInUse];

	for (i = 0; i < mAccountInUse; i++)
	{
		mAccounts[i] = obj.mAccounts[i];
	}
	
}

User::~User()
{
	if (mAccounts != nullptr) { delete[] mAccounts; }
	mAccounts = nullptr;

	mAccountInUse = 0;
}



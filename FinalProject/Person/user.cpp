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

/************************************************************************************************************************
* Constructors & Deconstructors
************************************************************************************************************************/


/*Pre: none
* Post: Initialized User object
* Purpose: To initialize User object with default constructor
*/
User::User()
{
	mAccounts = nullptr;
	mAccountsInUse = 0;
}

/*Pre: User object
* Post: initialized User object
* Purpose: To initialize User object using the copy constructor
*/
User::User(const User& obj)
{
	if (mAccounts != nullptr) { delete[] mAccounts; }

	mAccountsInUse = obj.mAccountsInUse;

	int i;
	mAccounts = new Account[mAccountsInUse];

	for (i = 0; i < mAccountsInUse; i++)
	{
		mAccounts[i] = obj.mAccounts[i];
	}
	
}

/*Pre: none
* Post: Account object destroyed
* Purpose: To safely destroy the Account object, including removing dynamically allocated memory
*/
User::~User()
{
	if (mAccounts != nullptr) { delete[] mAccounts; }
	mAccounts = nullptr;

	mAccountsInUse = 0;
}

/************************************************************************************************************************
* Accessors
************************************************************************************************************************/

/*Pre: integer for index
* Post: Account object at given index
* Purpose: Accessor for the mAccounts member variable
*/
Account User::getAccount(int index)
{
	if (!(index >= 0 && index < mAccountsInUse)) { std::cout << "Index given is out of range." << std::endl; }
	return mAccounts[index];
}

/*Pre: none
* Post: mAccountsInUse returned
* Purpose: Accessor for mAccountsInUse member variable
*/
int User::getAccountInUse()
{
	return mAccountsInUse;
}

/*Pre: index for array
* Post: mId at given index
* Purpose: Accessor for mId in the dynamically allocated array
*/
std::string User::getID(int index)
{
	return mAccounts[index].mId;
}

/*Pre: index for array
* Post: mPassword at given index
* Purpose: Accessor for mPassword in the dynamically allocated array
*/
std::string User::getPassword(int index)
{
	return mAccounts[index].mPassword;
}

/************************************************************************************************************************
* Mutators
************************************************************************************************************************/

/*Pre: index for array and a new Account object
* Post: sets object at index to the given object
* Purpose: Mutates array at given index to given object
*/
void User::setAccount(int index, Account obj)
{
	mAccounts[index] = obj;
}

/*Pre: index for array and a new id
* Post: sets mId at given index to given string
* Purpose: Mutates id in the array at given index to given id
*/
void User::setID(int index, std::string id)
{
	mAccounts[index].mId = id;
}

/*Pre: index for array and new password
* Post: sets mPaddword at given index to the given string
* Purpose: Mutates password in the aray at given index to the given password
*/
void User::setPassword(int index, std::string password)
{
	mAccounts[index].mPassword = password;
}

/************************************************************************************************************************
* Other
************************************************************************************************************************/

/*Pre: Account object
* Post: bool if the Account given exists in the array
* Purpose: to check to see if the given object is in the dynamic array
*/
bool User::isUserExist(Account obj)
{
	int i;
	for (i = 0; i < mAccountsInUse; i++)
	{
		if (mAccounts[i] == obj) { return true; }
	}
	return false;
}

/*Pre: input file name
* Post: data from input file loaded into mAccounts
* Purpose: To load data from input file into dynamic array
*/
void User::loadData(std::string dataFileName)
{
	std::ifstream fin;

	fin.open(dataFileName);
	if (fin.fail())
	{
		std::cout << "Fin failed to open" << std::endl;
		return;
	}

	std::string line;
	int numUsers;

	//sets the number of users
	getline(fin, line);
	numUsers = stoi(line);
	mAccountsInUse = numUsers;

	//creates a new dynamic array
	mAccounts = new Account[mAccountsInUse];

	int i;
	Account tmpAcc;
	std::stringstream ss;
	std::string id, pass;
	for (i = 0; i < numUsers; i++)
	{
		getline(fin, line);
		ss.clear(); //id & pass does not update w/o this line for some reason
		ss.str(line);
		ss >> id >> pass;

		tmpAcc = Account(id, pass);
		mAccounts[i] = tmpAcc;
	}
	fin.close();

}

/*Pre: none
* Post: bool if logged in or not
* Purpose: to log in
*/
bool User::login()
{
	bool wantContinue = true, validCred = false;
	while (wantContinue)
	{
		std::string id, pass, answer;

		std::cout << "Username: ";
		getline(std::cin, id);

		char ch;
		std::cout << "Pass: ";
		while ((ch = getch()) != 13)
		{
			if (ch == 8)//backspace key
			{
				if (pass.length() == 0) { continue; }

				pass.erase(pass.end() - 1);//erases last character
				std::cout << '\b' << " " << '\b';
			}
			else if (ch == 127)//delete key
			{
				continue;
			}
			else
			{
				pass += ch;
				std::cout << "*";
			}
		}
		std::cout << std::endl;

		Account tmpAcc(id, pass);
		if (validateLogin(tmpAcc))
		{
			validCred = true;
			std::cout << "Login Successful" << std::endl;
			return true;
		}
		std::cout << "Invalid Login" << std::endl << "Do you want to continue?";
		getline(std::cin, answer);
		if (answer != "yes") { wantContinue = false; }
	}
	return false;
}

/*Pre: output file name
* Post: data from mAccounts printed to output file
* Purpose: To save data from dynamic array to output file
*/
void User::storeData(std::string dataFileName)
{
	//removes old file if it exists
	if (std::filesystem::exists(dataFileName))
	{
		remove(dataFileName.c_str());
	}

	std::ofstream out;
	int i;
	out.open(dataFileName);

	out << mAccountsInUse << std::endl;
	for (i = 0; i < mAccountsInUse; i++)
	{
		out << mAccounts[i].mId << " " << mAccounts[i].mPassword << std::endl;
	}
	out.close();
}

/*Pre: Accout object
* Post: bool if given object exists in mAccounts array
* Purpose: To see if obj exists in mAccounts array
*/
bool User::validateLogin(Account obj) const
{
	int i;
	for (i = 0; i < mAccountsInUse; i++)
	{
		if (mAccounts[i] == obj) { return true; }
	}
	return false;
}



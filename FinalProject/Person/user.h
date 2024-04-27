/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part1
Date Assigned: 04/05/2024
Due Date: 04/09/2024
Description:
The header file for the User class
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
#include <sstream>
#include <filesystem>
#include <conio.h>
#include "account.h"

class User
{
	private:
		Account* mAccounts;
		int mAccountsInUse;
	public:
		//Constructors
		User();
		User(const User& obj);
		~User();

		//Accessors
		Account getAccount(int index);
		int getAccountInUse();
		std::string getID(int index);
		std::string getPassword(int index);
		
		//mutators
		void setAccount(int index, Account obj);
		void setID(int index, std::string id);
		void setPassword(int index, std::string password);
		
		//other
		bool isUserExist(Account obj);
		void loadData(std::string dataFileName);
		bool login();
		void storeData(std::string dataFileName);
		bool validateLogin(Account obj) const;
};
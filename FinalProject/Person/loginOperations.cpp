/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 5
Date Assigned: 04/05/2024
Due Date: 04/26/2024
Description:
Contains function definitions for Login operations
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
#include "loginOperations.h"

/*Pre: users object
* Post: ID changed
* Purpose: to change the id of an account
*/
void changeID(User& users)
{
	std::string ID, pass;
	std::cout << "Enter ID to change: ";
	getline(std::cin, ID);
	
	std::cout << "Enter password: ";
	getline(std::cin, pass);

	if (!users.isUserExist(Account(ID, pass)))
	{
		std::cout << "user not found" << std::endl;
		return;
	}

	std::string newID;
	std::cout << "Enter new ID: ";
	getline(std::cin, newID);

	int i;
	for (i = 0; i < users.getAccountInUse(); i++)
	{
		if (users.getAccount(i).mId == ID)
		{
			break;
		}
	}
	users.setID(i, newID);

}

/*Pre: users object
* Post: password changed
* Purpose: To change the password of an account
*/
void changePass(User& users)
{
	std::string ID, pass;
	std::cout << "Enter ID: ";
	getline(std::cin, ID);

	char ch;
	std::cout << "Enter password to change: ";
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

	if (!users.isUserExist(Account(ID, pass)))
	{
		std::cout << "user not found" << std::endl;
		return;
	}

	std::string newPass;
	std::cout << "Enter new pass: ";
	while ((ch = getch()) != 13)
	{
		if (ch == 8)//backspace key
		{
			if (newPass.length() == 0) { continue; }

			newPass.erase(newPass.end() - 1);//erases last character
			std::cout << '\b' << " " << '\b';
		}
		else if (ch == 127)//delete key
		{
			continue;
		}
		else
		{
			newPass += ch;
			std::cout << "*";
		}
	}
	std::cout << std::endl;

	int i;
	for (i = 0; i < users.getAccountInUse(); i++)
	{
		if (users.getAccount(i).mPassword == pass)
		{
			break;
		}
	}
	users.setPassword(i, newPass);
}

/*Pre: users object
* Post: operation executed
* Purpose: anchor point for all login operations
*/
void loginOperations(User& users)
{
	int opNum = loginMenu();
	
	switch (opNum)
	{
		case 1:
			changeID(users);
			break;
		case 2:
			changePass(users);
			break;
		default:
			std::cerr << "operation number out of range" << std::endl;
	}
}

/*Pre: none
* Post: operation number to execute
* Purpose: To get the operation to execute
*/
int loginMenu()
{
	int ans = 0;
	std::cout << "1. Change ID" << std::endl
		 << "2. Change Password"
		 << std::endl;

	while (!(ans > 0 && ans < 3))
	{
		std::cout << "Enter operation Number: ";
		std::cin >> ans;
		std::cin.ignore();
	}
	return ans;
}

/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part1
Date Assigned: 04/05/2024
Due Date: 04/09/2024
Description:
The header file for the Account class
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

#include <iostream>
#include <string>

class Account
{
	public:
		//class variables
		std::string mId, mPassword;

		//Constructors
		Account();
		Account(std::string id, std::string password);
		Account(const Account& obj);

		//Operator overloads
		Account operator=(Account rhs);
		bool operator==(Account rhs);
		bool operator!=(Account rhs);
		friend std::istream& operator>>(std::istream& input, Account& obj);
		friend std::ostream& operator<<(std::ostream& output, Account& obj);
};
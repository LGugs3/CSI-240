/*
Author: Ellis Harris
Class: CSI-240-04
Assignment: Final Project - Part 1
Date Assigned: April 5, 2024
Due Date: 13:00 EST, April 9, 2024
Description:

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

#include <string>
#include <fstream>
#include "person.h"

using namespace std;

#pragma once

class Doctor : public Person
{
private:
	int mIndex;
	int mNumberOfPatient;
		
public:
	Doctor();
	Doctor(string id, string name, string address, string phoneNumber, int index, int numberOfPatient);
	Doctor(const Doctor& obj);
	~Doctor();

	int getIndex();
	int getNumberOfPatient();

	void setIndex(int index);
	void setNumberOfPatient(int numberOfPatient);

	virtual void display();

	Doctor operator++(int);
	Doctor operator--(int);
	friend istream& operator>>(istream& input, Doctor& obj);
	friend ostream& operator<<(ostream& output, Doctor obj);
};
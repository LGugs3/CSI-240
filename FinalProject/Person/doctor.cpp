/*
Author: Ellis Harris
Class: CSI-240-04
Assignment: Final Project - Part 2
Date Assigned: April 5, 2024
Due Date: 13:00 EST, April 12, 2024
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

#include "doctor.h"

using namespace std;

//Pre: Doctor object instantiated
//Post: Doctor object initialized
//Purpose: default constructor
Doctor::Doctor()
	:Person()
{
	mIndex = 0;
	mNumberOfPatient = 0;
}

//Pre: Doctor object instantiated with data to pass in
//Post: Doctor object initialized and populated with set data
//Purpose: constructor for set values
Doctor::Doctor(string id, string name, string address, string phoneNumber, int index, int numberOfPatient)
	:Person(id, name, address, phoneNumber)
{
	mIndex = index;
	mNumberOfPatient = numberOfPatient;
}

//Pre: An instance of Doctor class exsists
//Post: A new instance of Doctor class created to copy the intial one
//Purpose: copy constructor
Doctor::Doctor(const Doctor& obj)
	:Person(obj)
{
	mIndex = obj.mIndex;
	mNumberOfPatient = obj.mNumberOfPatient;
}

//Pre: Doctor class constructed/initiated
//Post: Doctor class destroyed
//Purpose: destructor
Doctor::~Doctor()
{

}

//Pre: mIndex exsits
//Post: mIndex returned
//Purpose: returns index
int Doctor::getIndex()
{
	return mIndex;
}

//Pre: mNumberOfPatient exists
//Post: mNumberOfPatient returned
//Purpose: returns number of patients
int Doctor::getNumberOfPatient()
{
	return mNumberOfPatient;
}

//Pre: am index value
//Post: mIndex updated
//Purpose: mIndex set to a specific value
void Doctor::setIndex(int index)
{
	mIndex = index;
}

//Pre: numberOfPatient value
//Post: mNumberOfPatient updated
//Purpose: mNumnerOfPatient set to a specific value
void Doctor::setNumberOfPatient(int numberOfPatient)
{
	mNumberOfPatient = numberOfPatient;
}

//Pre: Doctor object intitilized
//Post: doctor name, ID, index, and number of patients displayed to the screen
//Purpose: display Doctor information to the screen
void Doctor::display()
{
	Person::display();
	cout << "Doctor name: " << mName << endl;
	string ID = getId();
	cout << "Doctor ID: " << ID << endl;
	cout << "Index: " << mIndex << endl;
	cout << "Number of patients: " << mNumberOfPatient << endl;
}

//Pre: mNumnerOfPatient initialized
//Post: mNumberOfPatient increased by 1
//Purpose: increase mNumberOfPatient by 1
Doctor Doctor::operator++(int)
{
	mNumberOfPatient++;
	return *this;
}

//Pre: mNumnerOfPatient initialized
//Post: mNumberOfPatient decreased by 1
//Purpose: decrease mNumberOfPatient by 1 
Doctor Doctor::operator--(int)
{
	mNumberOfPatient--;
	return *this;
}

//Pre: file opened
//Post: information stored in Doctor obj
//Purpose: load information from file to Doctor obj
istream& operator>>(istream& input, Doctor& obj)
{
	getline(input, obj.mName);
	string ID;
	getline(input, ID);
	obj.setId(ID);
	input >> obj.mIndex;
	input >> obj.mNumberOfPatient >> ws;

	return input;
}

//Pre: file opened
//Post: information writen in file
//Purpose: load information from Doctor obj to a file
ostream& operator<<(ostream& output, Doctor obj)
{
	output << obj.mName << endl;
	output << obj.getId() << endl;
	output << obj.mIndex << " ";
	output << obj.mNumberOfPatient << endl;

	return output;
}

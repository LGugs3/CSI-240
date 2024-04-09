/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 2
Date Assigned: 04/05/2024
Due Date: 04/12/2024
Description:
Contains member function definitions for Patient class 
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
#include "patient.h"

/*Pre: none
* Post: initialized Patient object
* Purpose: Initialize Patient object with default constructor
*/
Patient::Patient() : Person()
{
	mDoctorId = "unknown";
}

/*Pre: 5 strings for id, name, address, phone number and doctor id
* Post: initialized Patient object with custom constructor
* Purpose: to initialize Patient object with custom constructor
*/
Patient::Patient(string id, string name, string address, string phoneNumber, string doctorId) : Person(id, name, address, phoneNumber)
{
	mDoctorId = doctorId;
}

/*Pre: Patient object
* Post: initialized patient object
* Purpose: to initialize patient object with copy constructor
*/
Patient::Patient(const Patient& obj) : Person(obj)
{
	mDoctorId = obj.mDoctorId;
}

/*Pre: none
* Post: destroyed Patient object
* Purpose: To safely destroy Patient object
*/
Patient::~Patient()
{
}

/*Pre: none
* Post: Doctor id
* Purpose: Accessor for mDoctorId
*/
string Patient::getDoctorId()
{
	return mDoctorId;
}

/*Pre: string for mDoctorId id
* Post: new mDoctorId
* Purpose: mutator for mDoctorId
*/
void Patient::setDoctorId(string id)
{
	mDoctorId = id;
}

/*Pre: none
* Post: Patient data printed to console
* Purpose: to print patient data to console
*/
void Patient::display()
{
	cout << *this;
}

/*Pre: istream for input and patient object
* Post: data from file set to Patient object
* Purpose: to read data from file into Patient object
*/
istream& operator>>(istream& input, Patient& obj)
{
	string id;
	getline(input, id);
	obj.setId(id);
	getline(input, obj.mName);
	getline(input, obj.mAddress);
	getline(input, obj.mPhoneNumber);
	getline(input, obj.mDoctorId);

	return input;
}

/*Pre: ostream for output and Patient object
* Post: object data printed to console
* Purpose: overload insertion operator for Patient class
*/
ostream& operator<<(ostream& output, Patient obj)
{
	output << static_cast<Person&>(obj) << obj.mDoctorId << endl;

	return output;
}
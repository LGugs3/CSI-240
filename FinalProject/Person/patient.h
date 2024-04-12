/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 2
Date Assigned: 04/05/2024
Due Date: 04/12/2024
Description:
Header file for Patient class
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
#ifndef _PATIENT_H
#define _PATIENT_H

#include "person.h"

class Patient : public Person
{
	private:
		string mDoctorId;

	public:
		//Constructors and Destructor
		Patient();
		Patient(string id, string name, string address, string phoneNumber, string doctorId);
		Patient(const Patient& obj);
		~Patient();

		//Accessors
		string getDoctorId();

		//mutators
		void setDoctorId(string id);

		//other
		virtual void display();

		//operator overloads
		friend istream& operator>>(istream& input, Patient& obj);
		friend ostream& operator<<(ostream& output, Patient obj);
		bool operator==(Patient& obj);
		bool operator!=(Patient& obj);
};

#endif // !_PATIENT_H
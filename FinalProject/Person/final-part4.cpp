/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 4
Date Assigned: 04/05/2024
Due Date: 04/20/2024
Description:
Driver file for part 4 of the final project
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
#include "patientOperations.h"

int main()
{
	Doctor* doctors;

	loadDoctor(doctors);

	ifstream fin;
	fin.open("../../../doctors.txt");
	int numDoctors;
	fin >> numDoctors;
	fin.close();

	Patient** patients;
	patients = new Patient * [numDoctors];
	int i, j;
	for (i = 0; i < numDoctors; i++)
	{
		loadPatient(patients[i], doctors[i]);
	}

	for (i = 0; i < numDoctors; i++)
	{
		for (j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			patients[i][j].display();
			cout << endl << endl;
		}
	}
	//pause();
	
	//cout << "Patient to add:" << endl;
	//addPatient(patients, doctors, numDoctors);

	//searchPatient(patients, doctors, numDoctors);

	//cout << "patient to remove" << endl;
	//removePatient(patients, doctors, numDoctors);

	//cout << "Remaning a patient" << endl;
	//updatePatient(patients, doctors, numDoctors);

	patientOperations(patients, doctors, numDoctors);




	//deleting dynamic arrays

	delete[] doctors;

	for (i = 0; i < numDoctors; i++)
	{
		delete[] patients[i];
	}
	delete[] patients;
}
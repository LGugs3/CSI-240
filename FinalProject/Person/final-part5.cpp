/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 5
Date Assigned: 04/05/2024
Due Date: 04/26/2024
Description:
driver file for final part 5
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

#include "schedulerOperations.h"

int main()//dont run delete statements dont work
{
	Patient*** scheduler;
	Doctor* doctors;
	loadDoctor(doctors);//creating and loading doctors array
	int numberOfDoctor, i, j, k;

	//getting number of doctors
	ifstream fin;
	fin.open("../../../doctors.txt");
	fin >> numberOfDoctor;
	fin.close();

	//creating patients array and loading array
	Patient** patients;
	patients = new Patient * [numberOfDoctor];
	for (i = 0; i < numberOfDoctor; i++)
	{
		loadPatient(patients[i], doctors[i]);
	}
	
	
	
	
	
	//loading schedule
	loadSchedule(scheduler, doctors, numberOfDoctor);
	//viewSchedule(doctors, numDoctors, scheduler);

	schedulerOperations(patients, doctors, numberOfDoctor, scheduler);










	storeSchedule(scheduler, numberOfDoctor);

	//deleting dynamic arrays
	for (i = 0; i < numberOfDoctor; i++)
	{
		for (j = 0; j < NUM_TIMESLOTS_IN_DAY; j++)
		{
			delete[] scheduler[i][j];
		}
	}

	for (i = 0; i < numberOfDoctor; i++)
	{
		delete[] scheduler[i];
	}

	delete[] scheduler;

	delete[] doctors;


	return 0;
}
/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 5
Date Assigned: 04/05/2024
Due Date: 04/26/2024
Description:
Contains function defintions for schedulerOperations.h
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

void loadSchedule(Patient***& scheduler, Doctor doctor[], int numberOfDoctor)
{
	ifstream fin;
	fin.open("../../../" + SCHEDULER_FLIE_NAME);
	if (fin.fail())
	{
		cerr << "schedule file failed to open" << endl;
		return;
	}

	int i, j, k;
	string SSN, name, addr, phoneNum, docID;

	scheduler = new Patient * *[numberOfDoctor];

	//doctor to doctor
	for (i = 0; i < numberOfDoctor; i++)
	{
		//timeslot to timeslot
		scheduler[i] = new Patient * [NUM_TIMESLOTS_IN_DAY];
		for (j = 0; j < NUM_TIMESLOTS_IN_DAY; j++)
		{
			//day to day
			scheduler[i][j] = new Patient[NUM_DAYS_IN_WEEK];
			for (k = 0; k < NUM_DAYS_IN_WEEK; k++)
			{
				//getting patient data from file
				getline(fin, SSN);
				getline(fin, name);
				getline(fin, addr);
				getline(fin, phoneNum);
				getline(fin, docID);

				scheduler[i][j][k] = Patient(SSN, name, addr, phoneNum, docID);
			}
		}
	}
}

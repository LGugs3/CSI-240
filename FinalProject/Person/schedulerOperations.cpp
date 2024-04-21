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

/*Pre: index of doctor's patients to print, scheduler array
* Post: patient's in doctor's schedule printed to console
* Purpose: To display <doctorIndex>'s patients to console
*/
void displaySchedule(int doctorIndex, Patient***& scheduler)
{
	const string WEEKDAY_NAMES[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"},
				 APPOINT_SUFFIX = " Appointment";
	int i, j,
		hour, minute;

	for (j = 0; j < NUM_DAYS_IN_WEEK; j++)
	{
		cout << WEEKDAY_NAMES[j] + APPOINT_SUFFIX << endl;
		//reset time
		hour = 9;
		minute = 00;

		for (i = 0; i < NUM_TIMESLOTS_IN_DAY; i++)
		{
			//setfill() found here: https://cplusplus.com/forum/beginner/13082/
			cout << hour << ":" << setw(2) << setfill('0') << minute << ": "
				 << scheduler[doctorIndex][i][j].getName() << endl;

			//update time for next iteration
			minute += 15;
			if (minute >= 60)
			{
				hour++;
				minute = 0;
			}
			if (hour > 12)
			{
				hour = 1;
			}
		}
		//space between last appointment and next day
		cout << endl;
	}
}

/*
* Pre: scheduler array as reference, doctor array, and number of doctors
* Post: schedule.txt loaded into scheduler array
* Purpose: To load data from file to array
*/
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

/*Pre: scheduler array and number of doctors
* Post: scheduler data stored in file
* Purpose: To store data file array to file
*/
void storeSchedule(Patient ***& scheduler, int numberOfDoctor)
{
	ofstream ofs;
	//check if file exists already before creating it
	if (std::filesystem::exists("../../../" + SCHEDULER_FLIE_NAME))
	{
		remove(("../../../" + SCHEDULER_FLIE_NAME).c_str());
	}
	ofs.open("../../../" + SCHEDULER_FLIE_NAME);

	int i, j, k;
	for (i = 0; i < numberOfDoctor; i++)
	{
		for (j = 0; j < NUM_TIMESLOTS_IN_DAY; j++)
		{
			for (k = 0; k < NUM_DAYS_IN_WEEK; k++)
			{
				ofs << scheduler[i][j][k];
			}
		}
	}
	ofs.close();
}

/*Pre: array of doctors, number of doctors and scheduler array
* Post: all appointments for all doctors printed to console
* Purpose: To print all appointments to the console
*/
void viewSchedule(Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	int i;
	for (i = 0; i < numberOfDoctor; i++)
	{
		cout << "Doctor: " << doctors[i].getName() << endl;
		displaySchedule(i, scheduler);
	}
}

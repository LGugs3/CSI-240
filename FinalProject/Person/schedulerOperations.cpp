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

/*Pre: array of patients and the doctor they belong to, doctor array, number of doctors and scheduler array
* Post: appointment added to scheduler array
* Purpose: to add an appointment to the scheduler array
*/
void addAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	//get doctor name and check if exists
	string docName;
	cout << "Enter doctor name to add appointment under: ";
	getline(cin, docName);
	
	bool docFound = false;
	int i, docIndex;
	for (i = 0; i < numberOfDoctor; i++)
	{
		if (doctors[i].getName() == docName)
		{
			docFound = true;
			docIndex = i;
			break;
		}
	}

	if (!docFound)
	{
		cout << "Doctor name not found" << endl;
		return;
	}

	//Get patient name and check if exists
	bool patFound = false;
	string patName;
	int patIndex;
	cout << "Enter patient name: ";
	getline(cin, patName);

	for (i = 0; i < doctors[docIndex].getNumberOfPatient(); i++)
	{
		if (patients[docIndex][i].getName() == patName)
		{
			patIndex = i;
			patFound = true;
			break;
		}
	}

	if (!patFound)
	{
		cout << "Patient name not found" << endl;
		return;
	}

	//if all appointments are filled for the week
	if (printOpenAppsForDoc(scheduler, docIndex) == 0)
	{
		cout << "All appointments for the week are full." << endl;
		return;
	}

	string day;
	int dayIndex = -1;
	cout << "Enter Day for new Appointment: ";
	getline(cin, day);

	for (i = 0; i < 5; i++)
	{
		if (WEEKDAY_NAMES[i] == day)
		{
			dayIndex = i;
			break;
		}
	}

	if (dayIndex == -1)
	{
		cout << "Day not found" << endl;
		return;
	}

	//enter new appointment time
	int hr = 0, min = 1;
	cout << "Enter hour for appointment: ";
	if (!isdigit(cin.peek()))
	{
		cout << "not a number" << endl;
		while (hr == 0)
		{
			cin >> hr;
			cin.ignore();
		}
	}
	else
	{
		cin >> hr;
		cin.ignore();
	}

	cout << "Enter minute for appointment: ";
	if (!isdigit(cin.peek()))
	{
		cout << "not a number" << endl;
		while (min == 1)
		{
			cin >> min;
			cin.ignore();
		}
	}
	else
	{
		cin >> min;
		cin.ignore();
	}


	//if app avail
	if (min % 15 != 0)
	{
		cout << "Appointment time is not available" << endl;
	}
	else
	{
		min %= 15;
		if (hr < 5) // hrs 1 - 4
		{
			hr += 4;

			if (((hr * 4) - 4 + min) > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}

			scheduler[docIndex][(hr * 4) - 4 + min][dayIndex] = patients[docIndex][patIndex];
		}
		else //hrs 9 - 12
		{
			hr -= 9;

			if (((hr * 4) + min) > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}

			scheduler[docIndex][(hr * 4) + min][dayIndex] = patients[docIndex][patIndex];
		}

		cout << "Appointment set" << endl;
	}
}

/*Pre: index of doctor's patients to print, scheduler array
* Post: patient's in doctor's schedule printed to console
* Purpose: To display <doctorIndex>'s patients to console
*/
void displaySchedule(int doctorIndex, Patient***& scheduler)
{
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

/*Pre: scheduler array and doctor index to print
* Post: all open appointments for doctor at <docIndex> printed to console]
* Purpose: To print all available appointments for <docIndex> to console
*/
int printOpenAppsForDoc(Patient***& scheduler, int docIndex)
{
	int i, j, hour, min, appAvail, daysAvail = 5;
	cout << "Appointments available:" << endl;
	for (i = 0; i < NUM_DAYS_IN_WEEK; i++)
	{
		hour = 9;
		min = 0;
		appAvail = 0;
		cout << WEEKDAY_NAMES[i] << APPOINT_SUFFIX << endl;
		for (j = 0; j < NUM_TIMESLOTS_IN_DAY; j++)
		{
			if (scheduler[docIndex][j][i].getName() == "empty")
			{
				cout << hour << ":" << setw(2) << setfill('0') << min << endl;
				appAvail++;
			}

			//update time for next iteration
			min += 15;
			if (min >= 60)
			{
				hour++;
				min = 0;
			}
			if (hour > 12)
			{
				hour = 1;
			}
		}

		if (appAvail == 0)
		{
			cout << "All appointments for this day are filled" << endl;
			daysAvail--;
		}
		cout << endl;//spacing between days
	}
	return daysAvail;
}

void removeAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{

}

/*Pre: none
* Post: int for operation to perform
* Purpose: To get the operation to perform
*/
int schedulerMenu()
{
	int ans = 0;
	cout << "Enter number for operation:" << endl
		 << "1. Add Appointment" << endl
		 << "2. Delete Appointment" << endl
		 << "3. Modify Appointment" << endl
		 << "4. Display Appointments" << endl
		 << "5. Find Appointment"
		 << endl;

	while (!(ans > 0 && ans < 6))
	{
		cout << "Enter number: ";
		cin >> ans;
		cin.ignore();
	}
	return ans;
}

void schedulerOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient ***& scheduler)
{
	int opNum;
	opNum = schedulerMenu();

	switch (opNum)
	{
		case 1:
			addAppointment(patients, doctors, numberOfDoctor, scheduler);
			break;
		case 2:
			removeAppointment(patients, doctors, numberOfDoctor, scheduler);
			break;
		case 3:
			//modify appointment
			break;
		case 4:
			viewSchedule(doctors, numberOfDoctor, scheduler);
			break;
		case 5:
			//search for apointment
			break;
		default:
			cerr << "operation number out of range" << endl;
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

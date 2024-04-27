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
	int i, docIndex;
	docName = searchDoctor(doctors, numberOfDoctor);
	if (docName == "empty")
	{
		cout << "Doctor does not exist" << endl;
		return;
	}
	docIndex = getDoctorIndex(doctors, numberOfDoctor, docName);


	//Get patient name and check if exists
	string patName, patID;
	int patIndex;
	patID = searchPatient(patients, doctors, numberOfDoctor, docIndex);
	getPatientIndex(patients, doctors, numberOfDoctor, patID, patIndex, docIndex);
	if (isPatientExist(patients, doctors, numberOfDoctor, patID))
	{
		patName = patients[docIndex][patIndex].getName();

	}
	else
	{
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
		int index;

		min /= 15;
		if (min < 0 || min > 3)
		{
			cout << "Minute time not available" << endl;
			return;
		}

		if (hr < 5 && hr > 0) // hrs 1 - 4
		{
			hr += 4;
			index = (hr * 4) - 4 + min;

			if (index > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}
			if (scheduler[docIndex][index][dayIndex].getName() != "empty")
			{
				cout << "Appointment time is already filled" << endl;
				return;
			}

			scheduler[docIndex][index][dayIndex] = patients[docIndex][patIndex];
		}
		else //hrs 9 - 12
		{
			if (hr > 12)
			{
				cout << "Hour not available" << endl;
				return;
			}

			hr -= 9;
			index = (hr * 4) + min;

			if (index > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}
			if (scheduler[docIndex][index][dayIndex].getName() != "empty")
			{
				cout << "Appointment time is already filled" << endl;
				return;
			}

			scheduler[docIndex][index][dayIndex] = patients[docIndex][patIndex];
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

/*Pre: scheduler array, patient name, doctor index
* Post: all appointments for patient printed to console
* Purpose: To print patient appointments to console
*/
int displayPatientAppointments(Patient***& scheduler, string patientName, int doctorIndex)
{
	int i, j, hr, min, daysAvail = NUM_DAYS_IN_WEEK, appsAvail;

	for (j = 0; j < NUM_DAYS_IN_WEEK; j++)
	{
		cout << WEEKDAY_NAMES[j] + APPOINT_SUFFIX << endl;
		//reset time
		hr = 9;
		min = 00;
		appsAvail = 0;

		for (i = 0; i < NUM_TIMESLOTS_IN_DAY; i++)
		{
			if (scheduler[doctorIndex][i][j].getName() == patientName)
			{
				cout << hr << ":" << setw(2) << setfill('0') << min << endl;
				appsAvail++;
			}

			//update time for next iteration
			min += 15;
			if (min >= 60)
			{
				hr++;
				min = 0;
			}
			if (hr > 12)
			{
				hr = 1;
			}
		}
		cout << endl;
		if (appsAvail == 0)
		{
			daysAvail--;
		}
	}
	return daysAvail;
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

/*Pre: arrays for the schedule, patients, and doctors. number of doctor as int
* Post: one appointment moved to a different time and/or day
* Purpose: to move appointments to different timeslots and/or days
*/
void modifyAppointment(Patient***& scheduler, Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	//get doctor name
	string docName;
	int docIndex;

	docName = searchDoctor(doctors, numberOfDoctor);
	if (docName == "empty")
	{
		cout << "Doctor does not exist" << endl;
		return;
	}
	docIndex = getDoctorIndex(doctors, numberOfDoctor, docName);

	//getting patient name
	string patName, patID;
	int patIndex;

	patID = searchPatient(patients, doctors, numberOfDoctor, docIndex);
	getPatientIndex(patients, doctors, numberOfDoctor, patID, patIndex, docIndex);
	if (isPatientExist(patients, doctors, numberOfDoctor, patID))
	{
		patName = patients[docIndex][patIndex].getName();

	}
	else
	{
		return;
	}

	if (displayPatientAppointments(scheduler, patName, docIndex) == 0)
	{
		cout << "Patient does not have any appointments" << endl;
		return;
	}


	/*****************************************************************************************************************
	old appointment
	******************************************************************************************************************/
	string day;
	int oldDayIndex = -1, i, oldIndex;
	cout << "Enter appointment to move:" << endl << "Enter Day for new Appointment: ";
	getline(cin, day);

	for (i = 0; i < 5; i++)
	{
		if (WEEKDAY_NAMES[i] == day)
		{
			oldDayIndex = i;
			break;
		}
	}

	if (oldDayIndex == -1)
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
		Patient emptyPatient = Patient("empty", "empty", "empty", "empty", "empty");

		min /= 15;
		if (hr < 5) // hrs 1 - 4
		{
			hr += 4;

			oldIndex = (hr * 4) - 4 + min;
			if (oldIndex > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}

			if (scheduler[docIndex][oldIndex][oldDayIndex] != patients[docIndex][patIndex])
			{
				cout << "Appointment you are attempting to move does not belong to " << patName << endl;
				return;
			}

			scheduler[docIndex][oldIndex][oldDayIndex] = emptyPatient;
		}
		else //hrs 9 - 12
		{
			hr -= 9;

			oldIndex = (hr * 4) + min;

			if (oldIndex > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}

			if (scheduler[docIndex][oldIndex][oldDayIndex] != patients[docIndex][patIndex])
			{
				cout << "Appointment you are attempting to move does not belong to " << patName << endl;
				return;
			}

			scheduler[docIndex][oldIndex][oldDayIndex] = emptyPatient;
		}
	}

	/*****************************************************************************************************************
	new appointment
	******************************************************************************************************************/
	int newDayIndex = -1;
	cout << endl <<"Enter new Appointment time:" << endl << "Enter Day for new Appointment: ";
	getline(cin, day);

	for (i = 0; i < NUM_DAYS_IN_WEEK; i++)
	{
		if (WEEKDAY_NAMES[i] == day)
		{
			newDayIndex = i;
			break;
		}
	}

	if (newDayIndex == -1)
	{
		cout << "Day not found" << endl;
		//resetting old appointment before exit
		scheduler[docIndex][oldIndex][oldDayIndex] = patients[docIndex][patIndex];
		return;
	}

	//enter new appointment time
	hr = 0, min = 1;
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
		int newIndex;
		Patient emptyPatient = Patient("empty", "empty", "empty", "empty", "empty");

		min /= 15;
		if (hr < 5) // hrs 1 - 4
		{
			hr += 4;

			newIndex = (hr * 4) - 4 + min;
			if (newIndex > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				//resetting old appointment before exit
				scheduler[docIndex][oldIndex][oldDayIndex] = patients[docIndex][patIndex];
				return;
			}

			if (scheduler[docIndex][newIndex][newDayIndex].getName() != "empty")
			{
				cout << "Appointment you are attempting to move does not belong to " << patName << endl;
				//resetting old appointment before exit
				scheduler[docIndex][oldIndex][oldDayIndex] = patients[docIndex][patIndex];
				return;
			}

			scheduler[docIndex][newIndex][newDayIndex] = patients[docIndex][patIndex];
		}
		else //hrs 9 - 12
		{
			hr -= 9;

			newIndex = (hr * 4) + min;

			if (newIndex > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				//resetting old appointment before exit
				scheduler[docIndex][oldIndex][oldDayIndex] = patients[docIndex][patIndex];
				return;
			}

			if (scheduler[docIndex][newIndex][newDayIndex].getName() != "empty")
			{
				cout << "Appointment you are attempting to move does not belong to " << patName << endl;
				//resetting old appointment before exit
				scheduler[docIndex][oldIndex][oldDayIndex] = patients[docIndex][patIndex];
				return;
			}

			scheduler[docIndex][newIndex][newDayIndex] = patients[docIndex][patIndex];
		}

		cout << "Patient moved successfully" << endl;
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

/*Pre: patients array, array of doctors, number of doctors, and scheduler array
* Post: appointment specified is removed
* Purpose: To remove appointments specified by user
*/
void removeAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler)
{
	//get doctor name and check if exists
	string docName;
	int i, docIndex;
	docName = searchDoctor(doctors, numberOfDoctor);
	if (docName == "empty")
	{
		cout << "Doctor does not exist" << endl;
		return;
	}
	docIndex = getDoctorIndex(doctors, numberOfDoctor, docName);


	//Get patient name and check if exists
	string patName, patID;
	int patIndex;
	patID = searchPatient(patients, doctors, numberOfDoctor, docIndex);
	getPatientIndex(patients, doctors, numberOfDoctor, patID, patIndex, docIndex);
	patName = patients[docIndex][patIndex].getName();

	//checks to make sure there is at least one appointment to delete
	if (displayPatientAppointments(scheduler, patName, docIndex) == 0)
	{
		cout << "This patient has no appointments scheduled" << endl;
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
		Patient emptyPatient = Patient("empty", "empty", "empty", "empty", "empty");
		int index;

		min /= 15;
		if (hr < 5) // hrs 1 - 4
		{
			hr += 4;

			index = (hr * 4) - 4 + min;
			if (index > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}

			if (scheduler[docIndex][index][dayIndex] != patients[docIndex][patIndex])
			{
				cout << "Appointment you are attempting to delete does not belong to " << patName << endl;
				return;
			}

			scheduler[docIndex][index][dayIndex] = emptyPatient;
		}
		else //hrs 9 - 12
		{
			hr -= 9;

			index = (hr * 4) + min;

			if (index > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}

			if (scheduler[docIndex][index][dayIndex] != patients[docIndex][patIndex])
			{
				cout << "Appointment you are attempting to delete does not belong to " << patName << endl;
				return;
			}

			scheduler[docIndex][index][dayIndex] = emptyPatient;
		}

		cout << "Appointment removed" << endl;
	}

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

/*Pre: arrays for scheduler, patients, and doctors. number of doctors as int
* Post: fxn user inputted is ran
* Purpose: Holds all possible scheduler fxns user can use and makes user choose which to run
*/
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
			modifyAppointment(scheduler, patients, doctors, numberOfDoctor);
			break;
		case 4:
			viewSchedule(doctors, numberOfDoctor, scheduler);
			break;
		case 5:
			searchForAppointment(scheduler, patients, doctors, numberOfDoctor);
			break;
		case 6:
			//logout
			break;
		default:
			cerr << "operation number out of range" << endl;
	}
}

/*Pre: arrays for scheduler, patients, and doctors. number of doctors as int
* Post: patient at day and time printed to console
* Purpose: to search for an appointment
*/
void searchForAppointment(Patient ***& scheduler, Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	//get doctor name and check if exists
	string docName;
	int i, docIndex;
	docName = searchDoctor(doctors, numberOfDoctor);
	if (docName == "empty")
	{
		cout << "Doctor does not exist" << endl;
		return;
	}
	docIndex = getDoctorIndex(doctors, numberOfDoctor, docName);

	string day;
	int dayIndex = -1;
	cout << "Enter Day of Appointment: ";
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
	cout << "Enter hour of appointment: ";
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

	cout << "Enter minute of appointment: ";
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
		int index;

		min /= 15;
		if (min < 0 || min > 3)
		{
			cout << "Minute time not available" << endl;
			return;
		}

		if (hr < 5 && hr > 0) // hrs 1 - 4
		{
			hr += 4;
			index = (hr * 4) - 4 + min;

			if (index > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}
			if (scheduler[docIndex][index][dayIndex].getName() == "empty")
			{
				cout << "No appointment set at this time and day" << endl;
				return;
			}

			cout << "Patient scheduled at " << hr - 4 << ":" << setw(2) << setfill('0') << min * 15 << endl
				 << scheduler[docIndex][index][dayIndex] << endl;
		}
		else //hrs 9 - 12
		{
			if (hr > 12)
			{
				cout << "Hour not available" << endl;
				return;
			}

			hr -= 9;
			index = (hr * 4) + min;

			if (index > NUM_TIMESLOTS_IN_DAY)
			{
				cout << "Time slot unavailable" << endl;
				return;
			}
			if (scheduler[docIndex][index][dayIndex].getName() == "empty")
			{
				cout << "No appointment set at this time and day" << endl;
				return;
			}

			cout << "Patient scheduled at " << hr + 9 << ":" << setw(2) << setfill('0') << min * 15 << endl
				 << scheduler[docIndex][index][dayIndex] << endl;
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

/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 5
Date Assigned: 04/05/2024
Due Date: 04/26/2024
Description:
Header file for Scheduler Operations
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

#ifndef _SCHEDULEROPERATIONS_H
#define _SCHEDULEROPERATIONS_H

#include "patientOperations.h"
#include <iomanip>

const string SCHEDULER_FLIE_NAME = "schedule.txt";
const int NUM_TIMESLOTS_IN_DAY = 32;
const int NUM_DAYS_IN_WEEK = 5;
const string WEEKDAY_NAMES[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" },
			 APPOINT_SUFFIX = " Appointments";

void addAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler);
void displaySchedule(int doctorIndex, Patient***& scheduler);
void loadSchedule(Patient***& scheduler, Doctor doctor[], int numberOfDoctor);
int printOpenAppsForDoc(Patient***& scheduler, int docIndex);
void removeAppointment(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient***& scheduler);
int schedulerMenu();
void schedulerOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor, Patient ***& scheduler);
void storeSchedule(Patient ***& scheduler, int numberOfDoctor);
void viewSchedule(Doctor doctors[], int numberOfDoctor, Patient***& scheduler);




#endif
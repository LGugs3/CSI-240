/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 4
Date Assigned: 04/05/2024
Due Date: 04/20/2024
Description:
Contains function declarations for operations related to manipulating patient data
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

#ifndef _PATIENTOPERATIONS_H
#define _PATIENTOPERATIONS_H

#include "doctorOperations.h"
#include "commonOperations.h"



void patientOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor);
void addPatient(Patient**& patients, Doctor doctors[], int numberOfDoctor);
void searchPatient(Patient** patients, Doctor doctors[], int numberOfDoctor);
void getPatientIndex(Patient** patients, Doctor doctors[], int numberOfDoctor, string id, int& patientIndex, int& doctorIndex);
bool isPatientExist(Patient** patients, Doctor doctors[], int numberOfDoctor, string id);
void loadPatient(Patient*& patients, Doctor doctor);
void removePatient(Patient**& patients, Doctor doctors[], int numberOfDoctor);
void storePatient(Patient patients[], Doctor doctors);
void updatePatient(Patient** patients, Doctor doctors[], int numberOfDoctor);



#endif // !_DOCTOROPERATIONS_H

/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 4
Date Assigned: 04/05/2024
Due Date: 04/20/2024
Description:
Contains function declarations for the functions manipulating Doctor data
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

#ifndef _DOCTOROPERATIONS_H
#define _DOCTOROPERATIONS_H

#include "patient.h"
#include "doctor.h"
#include "commonOperations.h"
#include <filesystem>
#include <sstream>
#include <conio.h>



const string DOCTOR_FILE_NAME = "../../../doctors.txt";


void displayClosestDoctors(Doctor doctors[], string partialName, int numberOfDoctor);
int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName);
bool isDoctorExist(Doctor doctors[], int numberOfDoctor, string doctorName);
int loadDoctor(Doctor*& doctors);
string searchDoctor(Doctor doctors[], int numberOfDoctor);
void storeDoctor(Doctor doctors[], int numberOfDoctor);


#endif // !_DOCTOROPERATIONS_H
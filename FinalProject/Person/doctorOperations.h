

#ifndef _DOCTOROPERATIONS_H
#define _DOCTOROPERATIONS_H



#include "patient.h"
#include "doctor.h"
#include <filesystem>
#include <sstream>


const string DOCTOR_FILE_NAME = "../../../doctors.txt";



int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName);
bool isDoctorExist(Doctor doctors[], int numberOfDoctor, string doctorName);
int loadDoctor(Doctor*& doctors);
void storeDoctor(Doctor doctors[], int numberOfDoctor);
void doctorOperations(Patient**& patients, Doctor doctors[], int numberOfDoctors);


#endif // !_DOCTOROPERATIONS_H
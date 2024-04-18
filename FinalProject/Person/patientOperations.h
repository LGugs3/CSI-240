
#ifndef _PATIENTOPERATIONS_H
#define _PATIENTOPERATIONS_H

#include "doctorOperations.h"



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

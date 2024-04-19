/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 4
Date Assigned: 04/05/2024
Due Date: 04/20/2024
Description:
Contains function definitions for patientOperations.h
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

#include "patientOperations.h"

/*
* Pre: dynamic Patient matrix, doctor array, number of doctors
* Post: operation executed
* Purpose: This is an "anchor point" for all other patient operations
*/
void patientOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	cout << "Enter a number to match the request." << endl << endl
		 << "1. Add Patient" << endl
		 << "2. Remove Patient" << endl
		 << "3. Update Patient" << endl
		 << "4. Search Patient" << endl
		 << "5. Exit" << endl
		 << endl
		 << "Enter Command: ";
	int ans = 0;
	string junk;
	while (!(ans > 0 && ans << 6))
	{
		cin >> ans;
		cin.ignore();
	}

	switch (ans)
	{
		case 1:
			addPatient(patients, doctors, numberOfDoctor);
			break;
		case 2:
			removePatient(patients, doctors, numberOfDoctor);
			break;
		case 3:
			updatePatient(patients, doctors, numberOfDoctor);
			break;
		case 4:
			searchPatient(patients, doctors, numberOfDoctor);
			break;
		case 5:
			return;
		default:
			cerr << "switch statement out of range" << endl;
	}
	clearScreen();
}

/*Pre: dynamic Patient matrix, doctor array, number of doctors
* Post: new patient added if patient is unique and doctor exists
* Purpose: to add a new patient to Patient matrix
*/
void addPatient(Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	string SSN, name, address, phoneNum, docID;

	cout << "Enter Patient SSN: ";
	getline(cin, SSN);
	cout << "Enter Patient name: ";
	getline(cin, name);
	cout << "Enter Patient address: ";
	getline(cin, address);
	cout << "Enter Patient Phone Number: ";
	getline(cin, phoneNum);

	if (isPatientExist(patients, doctors, numberOfDoctor, SSN))
	{
		cout << "Patient SSN already exists" << endl;
	}
	//if new patient, create new array and add patient
	else
	{
		int i, j;
		string docName;
		int docIndex;
		cout << "Enter doctor name to put patient under: ";
		getline(cin, docName);

		//checks if the doctor name inputted exists already
		if (!isDoctorExist(doctors, numberOfDoctor, docName))
		{
			cout << "Doctor name not found" << endl;
		}
		else
		{
			docIndex = getDoctorIndex(doctors, numberOfDoctor, docName);
			docID = doctors[docIndex].getId();

			Patient* tempArr; //holds old data
			Patient tempPatient; //holds one object in array
			for (i = 0; i < numberOfDoctor; i++) //loops through patients[][] matrix to find the doctor to add the patient to
			{
				//only copy and delete array if it needs to be changed
				if (i == docIndex)
				{
					tempArr = new Patient[doctors[i].getNumberOfPatient()];
					for (j = 0; j < doctors[i].getNumberOfPatient(); j++)
					{
						tempPatient = patients[i][j];
						tempArr[j] = tempPatient;
					}
					//delete old array before moving on to next array
					delete[] patients[i];


					//creating new array to fit another patient
					doctors[i]++; //incrementing the number of patients for this doctor
					patients[i] = new Patient[doctors[i].getNumberOfPatient()];
					for (j = 0; j < doctors[i].getNumberOfPatient(); j++)
					{
						if (j == doctors[i].getNumberOfPatient() - 1)//newest entry
						{
							patients[i][j] = Patient(SSN, name, address, phoneNum, docID);
						}
						else
						{
							patients[i][j] = tempArr[j];
						}
					}

					//after adding a patient it is stored back into the file
					storePatient(patients[i], doctors[i]);
					storeDoctor(doctors, numberOfDoctor);

					//delete temp array after done using it
					delete[] tempArr;
					break;
				}
			}
		}
	}
}

/*Pre: <patients> and <doctors> arrays and number of doctors
* Post: patient data and doctor name printed to console if it exists
* Purpose: To get the user the patient's data and the doctor they belong to
*/
void searchPatient(Patient** patients, Doctor doctors[], int numberOfDoctor)
{
	string patientID;
	cout << "Enter SSN: ";
	getline(cin, patientID);

	if (isPatientExist(patients, doctors, numberOfDoctor, patientID))
	{
		int docIndex, patIndex;

		//patIndex and docIndex is pass by reference so we get the value that way
		getPatientIndex(patients, doctors, numberOfDoctor, patientID, patIndex, docIndex);

		cout << endl;
		patients[docIndex][patIndex].display();
		cout << endl << "Patient belongs to Dr. " << doctors[docIndex].getName() << endl;
	}
	else
	{
		cout << "Patient does not exist in the system" << endl;
	}
}

/*Pre: patients and doctors arrays, number of doctors, patient index(unset), and doctor index
* Post: <patientIndex> is set to the index of the value in the <patients> matrix
* Purpose: To get the index of the patient with <id>
*/
void getPatientIndex(Patient** patients, Doctor doctors[], int numberOfDoctor, string id, int& patientIndex, int& doctorIndex)
{
	int i, j;
	for (i = 0; i < numberOfDoctor; i++)
	{
		for (j = 0; j < doctors[i].getNumberOfPatient(); j ++)
			if (patients[i][j].getId() == id)
			{
				doctorIndex = i;
				patientIndex = j;
				return;
			}
	}
}

/*Pre: <patients> matrix, <doctors> array, number of doctors and the string of the patient to find
* Post: bool if the patient exists in the system or not
* Purpose: To check if a patient exists within the current <patients> matrix
*/
bool isPatientExist(Patient** patients, Doctor doctors[], int numberOfDoctor, string id)
{
	int i, j;
	for (i = 0; i < numberOfDoctor; i++)
	{
		for (j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			if (patients[i][j].getId() == id) { return true; }
		}
	}

	return false;
}

/*Pre: <patients> array belonging to <doctor>
* Post: patients loaded from <doctor> file into <patients> array
* Purpose: To load all patients into doctor array
*/
void loadPatient(Patient*& patients, Doctor doctor)
{
	string docId = doctor.getId();
	int docIndex = doctor.getIndex(), numPatients = doctor.getNumberOfPatient();

	ifstream fin;
	patients = new Patient[numPatients];
	
	fin.open("../../../" + docId + ".txt");
	if (fin.fail())
	{
		cerr << docId << " fin failed to open" << endl;
	}

	string patID, patName, patAddr, patPhoneNum, patDocID;
	int i;
	for (i = 0; i < numPatients; i++)
	{
		getline(fin, patID);
		getline(fin, patName);
		getline(fin, patAddr);
		getline(fin, patPhoneNum);
		getline(fin, patDocID);

		patients[i] = Patient(patID, patName, patAddr, patPhoneNum, patDocID);

	}
}

/*Pre: patients and doctors array as well as number of doctors
* Post: patient specified removed from array
* Purpose: to remove a patient from a doctor
*/
void removePatient(Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
	string patientID;
	cout << "Enter SSN: ";
	getline(cin, patientID);

	if (isPatientExist(patients, doctors, numberOfDoctor, patientID))
	{
		int docIndex, delPatIndex, i, oldNumPat;

		//patIndex and docIndex is pass by reference so we get the value that way
		getPatientIndex(patients, doctors, numberOfDoctor, patientID, delPatIndex, docIndex);

		oldNumPat = doctors[docIndex].getNumberOfPatient();
		Patient* tempArr = new Patient[oldNumPat];
		for (i = 0; i < oldNumPat; i++)
		{
			tempArr[i] = patients[docIndex][i];
		}
		delete[] patients[docIndex];

		doctors[docIndex]--;
		patients[docIndex] = new Patient[doctors[docIndex].getNumberOfPatient()];

		for (i = 0; i < oldNumPat; i++)
		{
			if (i == delPatIndex) { continue; }//Patient to delete
			if (i > delPatIndex) //after passing the deleted value move everything else over one
			{
				patients[docIndex][i - 1] = tempArr[i];
			}
			else
			{
				patients[docIndex][i] = tempArr[i];
			}
		}
		delete[] tempArr;

		storePatient(patients[docIndex], doctors[docIndex]);
		storeDoctor(doctors, numberOfDoctor);
		cout << "Patient removed" << endl;
	}
	else
	{
		cout << "Patient not found" << endl;
	}
}

/*Pre: <doctors> and <patients> array to store
* Post: <patients> data for <doctors> stored to file
* Purpose: to store <patients> from specific <doctors> to file
*/
void storePatient(Patient patients[], Doctor doctors)
{
	ofstream ofs;
	string fileName = "../../../" + doctors.getId() + ".txt";

	if (std::filesystem::exists(fileName))
	{
		remove((fileName).c_str());
	}

	ofs.open(fileName);

	int i;
	for (i = 0; i < doctors.getNumberOfPatient(); i++)
	{
		ofs << patients[i].getId() << endl
			<< patients[i].getName() << endl
			<< patients[i].getAddress() << endl
			<< patients[i].getPhoneNumber() << endl
			<< patients[i].getDoctorId() << endl;
	}

	ofs.close();


}

/*
* Pre: patients and doctors arrays as well as the number of doctors
* Post: patient specified has name changed
* Purpose: To change the name of a patient
*/
void updatePatient(Patient** patients, Doctor doctors[], int numberOfDoctor)
{
	string patientID;
	cout << "Enter SSN: ";
	getline(cin, patientID);

	if (isPatientExist(patients, doctors, numberOfDoctor, patientID))
	{
		string name;
		cout << "Enter new name: ";
		getline(cin, name);

		int patIndex, docIndex;
		getPatientIndex(patients, doctors, numberOfDoctor, patientID, patIndex, docIndex);
		patients[docIndex][patIndex].setName(name);
		cout << name << " Is set as patient " << patientID << "'s new name" << endl;

		storePatient(patients[docIndex], doctors[docIndex]);

	}
	else
	{
		cout << "Patient not found" << endl;
	}
}

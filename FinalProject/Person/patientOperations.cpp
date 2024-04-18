#include "patientOperations.h"

void patientOperations(Patient**& patients, Doctor doctors[], int numberOfDoctor)
{
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
	cout << "Enter the Patient's Doctor ID: ";
	getline(cin, docID);


	//if new patient, create new array and add patient
	if (!isPatientExist(patients, doctors, numberOfDoctor, SSN))
	{
		int i, j;
		string docName;
		int docIndex;
		cout << "Enter doctor name to put patient under: ";
		getline(cin, docName);

		if (!isDoctorExist(doctors, numberOfDoctor, docName))
		{
			cout << "Doctor name not found" << endl;
		}
		else
		{
			docIndex = getDoctorIndex(doctors, numberOfDoctor, docName);

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
					delete[] tempArr;
					break;

				}
			}
		}
	}
}

bool isPatientExist(Patient** patients, Doctor doctors[], int numberOfDoctor, string id)
{
	//to be added to
	return false;
}

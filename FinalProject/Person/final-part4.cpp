
#include "patientOperations.h"

int main()
{
	Doctor* doctors;

	loadDoctor(doctors);

	ifstream fin;
	fin.open("../../../doctors.txt");
	int numDoctors;
	fin >> numDoctors;
	fin.close();

	Patient** patients;
	patients = new Patient * [numDoctors];
	int i, j;
	for (i = 0; i < numDoctors; i++)
	{
		loadPatient(patients[i], doctors[i]);
	}

	for (i = 0; i < numDoctors; i++)
	{
		for (j = 0; j < doctors[i].getNumberOfPatient(); j++)
		{
			patients[i][j].display();
			cout << endl << endl;
		}
	}




	//deleting dynamic arrays

	delete[] doctors;

	for (i = 0; i < numDoctors; i++)
	{
		delete[] patients[i];
	}
	delete[] patients;
}
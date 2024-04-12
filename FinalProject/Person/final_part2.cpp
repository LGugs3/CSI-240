/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 2
Date Assigned: 04/05/2024
Due Date: 04/12/2024
Description:
Main file for Part 2 of the project
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
#include "patient.h"

int main()
{
	Patient patient1, patient2("12345", "Bobby", "0987 your house st city, ST 258741", "(951)-753-0147", "258970"), patient3(patient2);

	patient1.display();
	patient1.setDoctorId("12345");
	cout << endl;
	patient1.display();
	cout << endl;

	patient2.display();
	cout << endl;

	cout << patient1 << endl << patient1.getDoctorId() << endl;

	cin >> patient1;
	patient1.display();
	cout << endl;

	cout << (bool)(patient1 == patient2) << endl
		<< (bool)(patient1 != patient2) << endl
		<< (bool)(patient2 == patient3) << endl;



	return 0;
}
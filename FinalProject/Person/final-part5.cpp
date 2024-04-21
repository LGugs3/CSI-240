/*
* Author: Liam Gugliotta
Class: CSI-240-04
Assignment: Final Project Part 5
Date Assigned: 04/05/2024
Due Date: 04/26/2024
Description:
driver file for final part 5
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

int main()//dont run delete statements dont work
{
	Patient*** scheduler;
	Doctor* doctors;
	loadDoctor(doctors);
	int numDoctors;

	ifstream fin;
	fin.open("../../../doctors.txt");
	fin >> numDoctors;
	fin.close();

	//patients to be loaded into file
	Patient pat1 = Patient("000 - 00 - 0001", "pat 1", "addr 1", "100 000 0000", "111 - 11 - 1112"),
			pat2 = Patient("000 - 00 - 0002", "pat 2", "addr 2", "200 000 0000", "111 - 11 - 1111"),
			pat3 = Patient("000 - 00 - 0003", "pat 3", "addr 3", "300 000 0000", "111 - 11 - 1112"),
			pat4 = Patient("000 - 00 - 0004", "pat 4", "addr 4", "400 000 0000", "111 - 11 - 1113"),
			pat5 = Patient("000 - 00 - 0005", "pat 5", "addr 5", "500 000 0000", "111 - 11 - 1113");

	if (std::filesystem::exists("../../../" + SCHEDULER_FLIE_NAME))
	{
		remove(("../../../" + SCHEDULER_FLIE_NAME).c_str());
	}

	ofstream ofs;
	ofs.open("../../../" + SCHEDULER_FLIE_NAME);

	//loading scheduler with some junk data so it is easier to see between doctors
	int i, j, k;
	for (i = 0; i < numDoctors; i++)
	{
		for (j = 0; j < NUM_TIMESLOTS_IN_DAY; j++)
		{
			for (k = 0; k < NUM_DAYS_IN_WEEK; k++)
			{
				switch (i)
				{
					case 0:
						ofs << pat1;
						break;
					case 1:
						ofs << pat2;
						break;
					case 2:
						ofs << pat3;
						break;
					case 3:
						ofs << pat4;
						break;
					case 4:
						ofs << pat5;
						break;
					default: 
						cerr << "i is outside array" << endl;
				}
			}
		}
	}
	ofs << pat1;
	ofs.close();


	loadSchedule(scheduler, doctors, numDoctors);






	//deleting dynamic arrays
	for (i = 0; i < numDoctors; i++)
	{
		for (j = 0; j < NUM_TIMESLOTS_IN_DAY; j++)
		{
			delete[] scheduler[i][j];
		}
	}

	for (i = 0; i < numDoctors; i++)
	{
		delete[] scheduler[i];
	}

	//deletes last dimension
	delete[] scheduler;

	delete[] doctors;


	return 0;
}
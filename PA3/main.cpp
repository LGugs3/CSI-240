/*
Author: Liam Gugliotta
Class : CSI-240-04
Assignment : PA3
Date Assigned : 03/22/2024
Due Date : Due - 03/29/2024 13:00 EST
Description :
The main file for this project.
Certification of Authenticity :
I certify that this is entirely my own work, except where I have given
fully - documented references to the work of others.I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment :
	-Reproduce this assignment and provide a copy to another member of academic staff;
and /or
-Communicate a copy of this assignment to a plagiarism checking service(which may
	then retain a copy of this assignment on its database for the purpose of future
	plagiarism checking)
*/

#include "linkedList.h"


//if this line goes anywhere else compile errors are thrown
int Mushroom::k = -1; //initial value for k


int main()
{
	LinkedList knownData, testCases;

	//load data for both the known mushroom and the test mushrooms
	knownData.loadData(KNOWN_DATA_FILE);
	testCases.loadData(UNKNOWN_DATA_FILE, true);

	//make the predictions for the unknown mushrooms
	testCases.makePredictions(knownData, testCases, UNKNOWN_DATA_FILE);


	return 0;
}
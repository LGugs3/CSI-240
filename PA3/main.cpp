
#include "linkedList.h"

int Mushroom::k = -1; //initial value




int main()
{
	LinkedList knownData, testCases;

	knownData.loadData(KNOWN_DATA_FILE);
	testCases.loadData(UNKNOWN_DATA_FILE, true);

	testCases.makePredictions(knownData, testCases, UNKNOWN_DATA_FILE);


	return 0;
}
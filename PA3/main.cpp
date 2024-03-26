
#include "linkedList.h"

int Mushroom::k = -1; //initial value
const std::string KNOWN_DATA_FILE = "../../../data.txt";
const std::string UNKNOWN_DATA_FILE = "../../../input.txt";



int main()
{
	LinkedList knownData;
	LinkedList testCases;

	knownData.loadData(KNOWN_DATA_FILE);
	testCases.loadData(UNKNOWN_DATA_FILE);


	return 0;
}
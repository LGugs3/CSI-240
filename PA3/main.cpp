
#include "linkedList.h"

int Mushroom::k = -1; //initial value


int main()
{
	LinkedList nearestNeighbor;

	nearestNeighbor.loadData();
	nearestNeighbor.loopMushroomsforDistances();

	//debug
	nearestNeighbor.getMushroomDistance(0);


	return 0;
}
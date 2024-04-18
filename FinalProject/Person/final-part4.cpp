
#include "doctorOperations.h"

int main()
{
	Doctor* doctors;

	loadDoctor(doctors);
	doctors[0].display();
	doctors[1].display();


	delete[] doctors;
}
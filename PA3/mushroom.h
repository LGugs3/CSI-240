

#ifndef MUSHROOM
#define MUSHROOM

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


const int NUM_ATTRIBUTES = 22;


struct Mushroom
{
	private:
		bool mIsPoisonous;
		double* mDistance;
		int mAttributes[NUM_ATTRIBUTES];

		static int k;
	public:
		Mushroom();
		~Mushroom();
		Mushroom(bool isPoisonous, int attributes[]);
		double compareDistance(Mushroom comparator);
		int getAttribute(int index);
		void setK();
		int getK();
		void setDistance(double distance[]);


		friend std::ifstream& operator>>(std::ifstream& input, Mushroom& obj);
		Mushroom& operator=(Mushroom& rhs);


};


#endif // !MUSHROOM_H
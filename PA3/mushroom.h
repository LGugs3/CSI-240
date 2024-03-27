

#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


const int NUM_ATTRIBUTES = 22;


struct Mushroom
{
	private:
		bool mIsPoisonous;
		double *mDistance;
		int mAttributes[NUM_ATTRIBUTES];

		static int k;
	public:
		Mushroom();
		~Mushroom();
		Mushroom(bool isPoisonous, int attributes[]);
		double compareDistance(Mushroom comparator);
		int getAttribute(int index) const;
		void getDistance();
		int getK();
		void setAttributes();
		void setDistance(double distance[]);
		void setK();
		void setIsPoisonous(bool bools[]);
		
		


		friend std::ifstream& operator>>(std::ifstream& input, Mushroom& obj);
		Mushroom& operator=(Mushroom& rhs);
		bool operator==(Mushroom& rhs);


};


#endif // !MUSHROOM_H
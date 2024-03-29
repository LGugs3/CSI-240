/*
Author: Liam Gugliotta
Class : CSI-240-04
Assignment : PA3
Date Assigned : 03/22/2024
Due Date : Due - 03/29/2024 13:00 EST
Description :
Header file that contains Mushroom class declaration.
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
		double compareDistance(Mushroom comparator);
		int getAttribute(int index) const;
		void getDistance();
		bool getIsPoisonous();
		int getK();
		void setAttributes();
		void setDistance(double distance[]);
		void setK(const std::string file);
		void setIsPoisonous(bool bools[]);
		void setIsPoisonous(bool value);
		
		


		friend std::ifstream& operator>>(std::ifstream& input, Mushroom& obj);
		Mushroom& operator=(Mushroom& rhs);
		bool operator==(Mushroom& rhs);
		bool Mushroom::operator>(Mushroom rhs);
		bool Mushroom::operator<(Mushroom rhs);


};

#endif // !MUSHROOM_H
/*
Author: Liam Gugliotta
Class : CSI-240-04
Assignment : PA3
Date Assigned : 03/22/2024
Due Date : Due - 03/29/2024 13:00 EST
Description :
cpp file for Mushroom class.
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

/**************************************************************************************************************************************
* Class & Struct Construtors & Deconstructors
***************************************************************************************************************************************/

/*Pre: none
* Post: initialized mushroom object
* Purpose: To initialize mushroom object
*/
Mushroom::Mushroom()
{
	mIsPoisonous = true;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = 0;
	}

	if (k == -1) { setK(UNKNOWN_DATA_FILE); }
	mDistance = new double [k]; //tried to delete mDistance is ~Mushroom but error thrown b/c tried to delete mDistance multiple times
	for (int j = 0; j < k; j++)
	{
		mDistance[j] = 10000.0;
	}

}

/**************************************************************************************************************************************
* Member functions
***************************************************************************************************************************************/

/*Pre: index for mAttribute
* Post: specific single attribute in one mushroom
* Purpose: to return a single attribute in a mushroom
*/
int Mushroom::getAttribute(int index) const
{
	return mAttributes[index];
}

/*Pre: none
* Post: distances of mushroom printed to console
* Purpose: To print the distances of the mushroom to the console
*/
void Mushroom::getDistance()
{
	int i;
	for (i = 0; i < k; i++)
	{
		std::cout << mDistance[i] << " ";
	}
	std::cout << std::endl;
}

/*Pre: none
* Post: bool if the mushroom if poisonous or not
* Purpose: to get the clasification of the mushroom
*/
bool Mushroom::getIsPoisonous()
{
	return mIsPoisonous;
}

/*Pre: none
* Post: all attributes of mushroom set
* Purpose: To set the attributes of a mushroom
*/
void Mushroom::setAttributes()
{
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		std::cout << "Input attribute: ";
		std::cin >> mAttributes[i];
	}
}

/*Pre: array of bools from other isPoisonous mushrooms
* Post: set the classification of the current mushroom
* Purpose: to set the classification of the mushroom from an array of bools
*/
void Mushroom::setIsPoisonous(bool bools[])
{
	if (k == 1)
	{
		mIsPoisonous = bools[0]; //if k is one the array only has one value
		return;
	}

	int poisonousCount = 0, edibleCount = 0;

	for (int i = 0; i < k; i++)
	{
		if (bools[i]) { poisonousCount++; }
		else { edibleCount++; }
	}

	if (poisonousCount > edibleCount) { mIsPoisonous = true; }
	else { mIsPoisonous = false; }
}

/*Pre: a single bool from an identical mushroom
* Post: set the classification of the current mushroom'
* Purpose: to set the classification of the mushroom from a single bool
*/
void Mushroom::setIsPoisonous(bool value)
{
	mIsPoisonous = value;
}

/*Pre: none
* Post: the value of k
* Purpose: to get the value of k
*/
int Mushroom::getK()
{
	return k;
}

/*Pre: mushroom to compare to *this
* Post: distance between the two mushrooms
* Purpose: to get the distance between the two mushrooms
*/
double Mushroom::compareDistance(Mushroom comparator)
{
	double acc = 0.0;
	for (int j = 0; j < NUM_ATTRIBUTES; j++)
	{
		acc += pow(comparator.mAttributes[j] - mAttributes[j], 2);
	}
	acc = sqrt(acc);

	return acc;
}

/*Pre: name of the file that contains the k value
* Post: the value of k is set
* Purpose: To set the value of k
*/
void Mushroom::setK(const std::string file)
{
	std::ifstream fin;
	fin.open(file);

	if (fin.fail()) { std::cout << "input.txt failed to open" << std::endl; }
	else
	{
		fin >> k;
		fin.close();
	}
}

/*Pre: array of distances
* Post: distances of mushroom set
* Purpose: to set the distances of a mushroom
*/
void Mushroom::setDistance(double distance[])
{
	for (int i = 0; i < k; i++)
	{
		mDistance[i] = distance[i];
	}
}


/**************************************************************************************************************************************
* Operator Overloading
***************************************************************************************************************************************/

/*Pre: ifstream on left, mushroom on right
* Post: read attributes and classification from file into mushroom object
* Purpose: To read data from file into mushroom object
*/
std::ifstream& operator>>(std::ifstream& input, Mushroom& obj)
{
	std::string line;
	char isPoisonous;

	getline(input, line);
	std::stringstream ss(line);

	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		ss >> obj.mAttributes[i];
	}
	ss >> isPoisonous;
	if (isPoisonous == 'e') { obj.mIsPoisonous = false; }
	else { obj.mIsPoisonous = true; }

	return input;
}

/*Pre: mushroom on both sides
* Post: setting mushroom on right's data to the mushroom on the left
* Purpose: to set the the mushroom's data equal to each other, specifically the right mushroom's data
*/
Mushroom& Mushroom::operator=(Mushroom& rhs)
{
	this->mDistance = rhs.mDistance;
	this->mIsPoisonous = rhs.mIsPoisonous;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		this->mAttributes[i] = rhs.mAttributes[i];
	}
	
	return *this;
}

/*Pre: mushroom on both sides
* Post: bool if the mushrooms are equal to each other
* Purpose: To see if the mushrooms are equal to each other
*/
bool Mushroom::operator==(Mushroom& rhs)
{
	if (mIsPoisonous != rhs.mIsPoisonous) { return false; }

	int i = 0;
	for (i = 0; i < NUM_ATTRIBUTES; i++)
	{
		if (mAttributes[i] != rhs.mAttributes[i]) { return false; }
	}

	for (i = 0; i < k; i++)
	{
		if (mDistance[i] != rhs.mDistance[i]) { return false; }
	}

	return true;
}

/*Pre: mushroom on both sides
* Post: bool if the mushroom's distance of the left is greater than the mushroom's distance on the right
* Purpose: To see if the left mushroom's distance is greater than the right mushroom's distance
*/
bool Mushroom::operator>(Mushroom rhs)
{
	double avgLhs = 0.0, avgRhs = 0.0;

	for (int i = 0; i < k; i++)
	{
		avgLhs += mDistance[i];
		avgRhs += rhs.mDistance[i];
	}
	avgLhs /= k;
	avgRhs /= k;

	return avgLhs > avgRhs;
}

/*Pre: mushroom on both sides
* Post: bool if the mushroom's distance of the left is smaller than the mushroom's distance on the right
* Purpose: To see if the left mushroom's distance is smaller than the right mushroom's distance
*/
bool Mushroom::operator<(Mushroom rhs)
{
	double avgLhs = 0.0, avgRhs = 0.0;

	for (int i = 0; i < k; i++)
	{
		avgLhs += mDistance[i];
		avgRhs += rhs.mDistance[i];
	}
	avgLhs /= k;
	avgRhs /= k;

	return avgLhs < avgRhs;
}


#include "mushroom.h"
#include "linkedList.h"

Mushroom::Mushroom()
{
	mIsPoisonous = true;
	mDistance = 0;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = 0;
	}
}

Mushroom::Mushroom(bool isPoisonous, int attributes[])
{
	mIsPoisonous = isPoisonous;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = attributes[i];
	}
	mDistance = setDistance();//object to compare to

}

void Mushroom::loadData()
{
	std::ifstream fin;
	
}

void Mushroom::setDistance(Mushroom comparator)//execute after all other data has been loaded
{
	double acc = 0;
	for (int i = 0; i < NUM_ATTRIBUTES - 1; i++) //"- 1" b/c last attribute is not used in calculations 
	{
		acc += pow(comparator.mAttributes[i] - mAttributes[i], 2);
	}
	acc = sqrt(acc);
	mDistance = acc;
}






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

Mushroom Mushroom::operator=(Mushroom rhs)
{
	this->mDistance = rhs.mDistance;
	this->mIsPoisonous = rhs.mIsPoisonous;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		this->mAttributes[i] = rhs.mAttributes[i];
	}
	
	return *this;
}
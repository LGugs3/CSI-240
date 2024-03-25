
#include "mushroom.h"
#include "linkedList.h"

Mushroom::Mushroom()
{
	mIsPoisonous = true;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = 0;
	}

	if (k == -1) { setK(); }

	mDistance = new double[k];
	for (int j = 0; j < k; j++)
	{
		mDistance[j] = -1.0;
	}

}

Mushroom::~Mushroom()
{
	delete[] mDistance;
}

Mushroom::Mushroom(bool isPoisonous, int attributes[])
{
	mIsPoisonous = isPoisonous;
	mDistance = -1;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = attributes[i];
	}

	if (k == -1) { setK(); }
}

int Mushroom::getAttribute(int index)
{
	return mAttributes[index];
}

int Mushroom::getK()
{
	return k;
}

double Mushroom::compareDistance(Mushroom comparator)//execute after all other data has been loaded
{
	double acc = 0.0;
	for (int j = 0; j < NUM_ATTRIBUTES; j++)
	{
		acc += pow(comparator.mAttributes[j] - mAttributes[j], 2);
	}
	acc = sqrt(acc);

	return acc;
}

void Mushroom::setK()
{
	do
	{
		std::cout << "Enter k value: ";
		std::cin >> k;
	} while (k % 2 == 0 || k < 0);

}

void Mushroom::setDistance(double distance[])
{
	for (int i = 0; i < k; i++)
	{
		mDistance[i] = distance[i];
	}
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

#include "linkedList.h"

Mushroom::Mushroom()
{
	mIsPoisonous = true;
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		mAttributes[i] = 0;
	}

	if (k == -1) { setK(UNKNOWN_DATA_FILE); }
	mDistance = new double [k];
	for (int j = 0; j < k; j++)
	{
		mDistance[j] = 10000.0;
	}

}

int Mushroom::getAttribute(int index) const
{
	return mAttributes[index];
}

void Mushroom::getDistance()
{
	int i;
	for (i = 0; i < k; i++)
	{
		std::cout << mDistance[i] << " ";
	}
	std::cout << std::endl;
}

bool Mushroom::getIsPoisonous()
{
	return mIsPoisonous;
}

void Mushroom::setAttributes()
{
	for (int i = 0; i < NUM_ATTRIBUTES; i++)
	{
		std::cout << "Input attribute: ";
		std::cin >> mAttributes[i];
	}
}

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

void Mushroom::setIsPoisonous(bool value)
{
	mIsPoisonous = value;
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
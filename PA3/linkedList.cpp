
#include "linkedList.h"

LinkedList::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
}

LinkedList::~LinkedList()
{
	Node* tmp;

	while (mHead != nullptr)
	{
		tmp = mHead;

		mHead = tmp->mNext;
		tmp->mNext = nullptr;

		delete tmp;
	}
	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
	
}


LinkedList::Node::Node()
{
	//mData = smth
	mNext = nullptr;
}

LinkedList::Node::Node(Mushroom data)
{
	mData = data;
	mNext = nullptr;
}

int LinkedList::getDataAttribute(int NodeIndex, int AttrIndex)
{
	if (NodeIndex >= mCount || AttrIndex >= NUM_ATTRIBUTES) { return -1; } //if indices specified are out of range

	Node* tmp;
	int i;
	tmp = mHead;
	for (i = 0; i < NodeIndex; i++)
	{
		tmp = tmp->mNext;
	}

	return tmp->mData.getAttribute(AttrIndex);

}

void LinkedList::getMushroomDistance(int index)
{
	Node* tmp;
	int i;

	tmp = mHead;
	for (i = 0; i < index; i++) { tmp = tmp->mNext; }

	tmp->mData.getDistance();


}

int LinkedList::getMCount()
{
	return mCount;
}

void LinkedList::insertAtBack(Mushroom data)
{
	Node* newNode;

	newNode = new Node(data);

	if (mCount == 0)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
	}
	newNode->mNext = nullptr;
	mCount++;

}

void LinkedList::mushroomDistances(Mushroom testCase)
{
	Node* tmp;
	int k = mHead->mData.getK();
	double* distances = new double[k]; //create pointer array to temporarily store k closest distances
	double newDistance = 10000.0;
	bool unusedDistance = false;
	int i, j, index;
	bool* savedBools = new bool[k];

	for (i = 0; i < k; i++) //initializes all values of array to really big numbers that will never be used
	{
		distances[i] = 10000.0;
		savedBools[i] = false;
	}

	for (i = 0; i < k; i++)
	{
		for (tmp = mHead, index = 0; tmp != nullptr; tmp = tmp->mNext, index++)
		{
			newDistance = testCase.compareDistance(tmp->mData);

			unusedDistance = true;
			for (j = 0; j < k; j++)
			{
				if (distances[j] == newDistance) { unusedDistance = false; }
			}

			if (unusedDistance && newDistance < distances[i]) { distances[i] = newDistance; }
		}
	}

	testCase.setIsPoisonous(savedBools);

	testCase.setDistance(distances); //set distances

	delete[] distances;
	delete[] savedBools;

}

void LinkedList::makePredictions(LinkedList& knownData, LinkedList& newData, const std::string newFile)//Linked lists must be references or desructor will be called once out of scope
{
	int k = mHead->mData.getK();
	Node* knownTmp, *newTmp;
	int i, j, index;
	double newDistance, *distances;
	distances = new double[k];
	bool* savedBools = new bool[k];
	bool unusedDistance, exactMatch = false;

	for (i = 0; i < k; i++)//initializing values
	{
		distances[i] = 10000.0;
		savedBools[i] = true;
	}
	newDistance = 10000.0;
	
	for (newTmp = newData.mHead; newTmp != nullptr; newTmp = newTmp->mNext) //loops through new data to set all distances
	{
		exactMatch = false;
		for (index = 0; index < k && exactMatch == false; index++)//loops through the known data k times to get distances
		{
			for (knownTmp = knownData.mHead; knownTmp != nullptr; knownTmp = knownTmp->mNext)
			{
				if (knownTmp == newTmp) { continue; }//if the two tmps are pointing to the same location, aka the same mushroom
				
				newDistance = newTmp->mData.compareDistance(knownTmp->mData);//make new distance
				newDistance = trunc(newDistance * 1000) / 1000;//get rid of not needed points

				if (newDistance == 0.0) //if the test mushroom is the same as one of the known mushrooms
				{
					newTmp->mData.setIsPoisonous(knownTmp->mData.getIsPoisonous());
					exactMatch = true;
					break;
				}

				unusedDistance = true;//assume the new distance is true until proven false
				for (j = 0; j < k; j++)
				{
					if (distances[j] == newDistance) { unusedDistance = false; }
				}

				if (unusedDistance && newDistance < distances[index]) { distances[index] = newDistance; } //adds distance to array if it is unused and the new value is smaller than the old value
			}
		}
		if (!exactMatch) { newTmp->mData.setIsPoisonous(savedBools); }
		newTmp->mData.setDistance(distances);
	}

	delete[] distances;
	delete[] savedBools;

	newData.savePredictions();

}

void LinkedList::loadData(const std::string FILE_NAME, bool isTestFile)
{
	std::ifstream fin;
	Mushroom newMushroom;
	std::string junk;

	fin.open(FILE_NAME);
	if (fin.fail()) { std::cout << FILE_NAME << " failed to open" << std::endl; }
	else
	{
		if (isTestFile)
		{
			getline(fin, junk);
		}
		
		while (!fin.eof())
		{
			fin >> newMushroom;
			insertAtBack(newMushroom);
		}
		if (!isTestFile) { mCount--; }
	}
}

void LinkedList::loopMushroomsforDistances()
{
	Node* tmp;

	for (tmp = mHead; tmp != nullptr; tmp = tmp->mNext) { mushroomDistances(tmp->mData); }
}

void LinkedList::savePredictions()
{
	std::ifstream finTest;
	std::ofstream output;

	finTest.open(PREDICTIONS_DATA_FILE); //if the file already exists then delete it and make a new one
	if (finTest.is_open())
	{
		finTest.close();
		remove(PREDICTIONS_DATA_FILE.c_str());
	}
	output.open(PREDICTIONS_DATA_FILE);

	Node* tmp;

	for (tmp = mHead; tmp != nullptr; tmp = tmp->mNext)
	{
		output << tmp->mData;
	}
	output.close();
}





LinkedList::Node& LinkedList::Node::operator=(Mushroom& rhs)
{
	mData = rhs;
	return *this;
}

std::ofstream& operator<<(std::ofstream& output, Mushroom obj)
{
	if (obj.getIsPoisonous()) { output << "poisonous"; }
	else { output << "edible"; }

	output << std::endl;
	return output;
}
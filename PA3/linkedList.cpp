
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

		mHead = mHead->mNext;
		tmp->mNext = nullptr;

		delete tmp;
	}
	mCount = 0;
	mHead = nullptr;
	mTail = nullptr;
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






	//for (int i = 0; i < k; i++) //loops through the number of times k is, to get k number of closest distances
	//{
	//	for (tmp = mHead; tmp != nullptr; tmp = tmp->mNext)
	//	{
	//		if (tmp->mData == data) { continue; } //if the Mushrooms are the same

	//		newDistance = tmp->mData.compareDistance(data); //compare the distance between the two points
	//			
	//		unusedDistance = true; //assume distance is unused until proven false
	//		for (int j = 0; j < k; j++)
	//		{
	//			if (distances[j] == newDistance) { unusedDistance = false; } //if the distance matches any others in the pointer array the distance has already been used
	//		}
	//		if (unusedDistance && newDistance < distances[i]) { distances[i] = newDistance; } //if its a new distance and its smaller than the previous one
	//	}
	//}

	testCase.setDistance(distances); //set distances

	delete[] distances;
	delete[] savedBools;

}

void LinkedList::makePredictions(LinkedList knownData, const std::string newFile)
{
	std::ifstream finTest;
	std::ofstream output;

	finTest.open(newFile); //if the file already exists then delete it and make a new one
	if (finTest.is_open())
	{
		finTest.close();
		remove(newFile.c_str());
	}
	output.open(newFile);

	

}

void LinkedList::loadData(const std::string FILE_NAME)
{
	std::ifstream fin;
	Mushroom newMushroom;

	fin.open(FILE_NAME);
	if (fin.fail()) { std::cout << FILE_NAME << " failed to open" << std::endl; }

	else
	{
		while (!fin.eof())
		{
			fin >> newMushroom;
			insertAtBack(newMushroom);
		}

	}
}

void LinkedList::loopMushroomsforDistances()
{
	Node* tmp;

	for (tmp = mHead; tmp != nullptr; tmp = tmp->mNext) { mushroomDistances(tmp->mData); }
}







LinkedList::Node& LinkedList::Node::operator=(Mushroom& rhs)
{
	mData = rhs;
	return *this;
}

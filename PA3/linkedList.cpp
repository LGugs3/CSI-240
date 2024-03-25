
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
	mCount++;

}

void LinkedList::mushroomDistances()
{
	Node* tmp, *tmp2;
	int k = mHead->mData.getK();
	double* distances = new double[k];
	double newDistance;
	bool unusedDistance;

	for (int i = 0; i < k; i++)
	{
		for (tmp = mHead; tmp != nullptr; tmp = tmp->mNext)
		{
			for (tmp2 = mHead; tmp2 != nullptr; tmp2->mNext)
			{
				if (tmp == tmp2) { continue; }
				newDistance = tmp->mData.compareDistance(tmp2->mData);
				
				unusedDistance = true;
				for (int j = 0; j < k; j++)
				{
					if (distances[j] == newDistance) { unusedDistance = false; }
				}
				if (unusedDistance) { distances[i] = newDistance; }
			}
		}
	}
	tmp->mData.setDistance(distances[]);



	delete[] distances;

}

void LinkedList::loadData()
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

LinkedList::Node& LinkedList::Node::operator=(Mushroom& rhs)
{
	mData = rhs;
	return *this;
}

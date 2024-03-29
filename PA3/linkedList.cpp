/*
Author: Liam Gugliotta
Class : CSI-240-04
Assignment : PA3
Date Assigned : 03/22/2024
Due Date : Due - 03/29/2024 13:00 EST
Description :
cpp file for LinkedList class and Node struct.
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

/*Pre: None
* Post: Linked List initialized
* Purpose: To initialize a linked list
*/
LinkedList::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
}

/*Pre: None
* Post: Destroyed Linked List
* Purpose: To safely delete memory in the heap before destroying the linked list
* 
*/
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

/*Pre: None
* Post: Initialized node
* Purpose: To initialize a node in a linked list
*/
LinkedList::Node::Node()
{
	mData = Mushroom();
	mNext = nullptr;
}

/*Pre: data to initialize a node with
* Post: initialized node with given data
* Purpose: to initialize node with given data
*/
LinkedList::Node::Node(Mushroom data)
{
	mData = data;
	mNext = nullptr;
}

/**************************************************************************************************************************************
* Member functions
***************************************************************************************************************************************/

/*Pre: none
* Post: mCount of *this Linked List
* Purpose: to get the mCount of a Linked List
*/
int LinkedList::getMCount()
{
	return mCount;
}

/*Pre: Mushroom to be inserted
* Post: Mushroom node added to the end of a linked list
* Purpose: add a new node to the end of a linked list
*/
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

/*Pre: linked list with the known mushrooms, linked list with the unknown mushrooms, and the name of the output file
* Post: output file filled with predictions of unknown mushrooms
* Purpose: To make predictions of the unknown mushrooms
*/
void LinkedList::makePredictions(LinkedList& knownData, LinkedList& newData, const std::string newFile)//Linked lists must be references or desructor will be called once out of scope
{
	int k = mHead->mData.getK();
	Node* knownTmp, *newTmp;
	int i, j, index;
	double newDistance, *distances;
	distances = new double[k];
	bool* savedBools = new bool[k];
	bool unusedDistance, exactMatch = false;

	for (i = 0; i < k; i++)//initializing values to highest possible values to make sure the real values get assigned
	{
		distances[i] = 10000.0;
		savedBools[i] = true;
	}
	newDistance = 10000.0;
	

	/* Overall structure
	* outer loop(newTmp = 0) loops through the new mushrooms, the ones without classification, to get their distances
	* second for loop(k) loops k times to get the proper number of distances
	* third for loop(knownTmp) loops through the mushrooms that have classifications to compare the distances
	* another third for loop(j) loops through the distances array to see if the new potential distance is already used
	* 
	* Summary: The known mushrooms are looped through k times to find k distances that are closest to newTmp
	*/
	for (newTmp = newData.mHead; newTmp != nullptr; newTmp = newTmp->mNext) //loops through new data to set all distances
	{
		exactMatch = false;
		for (index = 0; index < k && exactMatch == false; index++)//loops through the known data k times to get distances
		{
			for (knownTmp = knownData.mHead; knownTmp != nullptr; knownTmp = knownTmp->mNext)
			{
				if (knownTmp == newTmp) { continue; }//if the two tmps are pointing to the same location, aka the same mushroom
				
				newDistance = newTmp->mData.compareDistance(knownTmp->mData);//set new distance
				newDistance = trunc(newDistance * 1000) / 1000;//get rid of unnessesary decimal places

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

				//adds distance to array if it is unused and the new value is smaller than the old value
				if (unusedDistance && newDistance < distances[index]) { distances[index] = newDistance; }
			}
		}
		//if the classification hasn't been set yet
		if (!exactMatch) { newTmp->mData.setIsPoisonous(savedBools); }
		newTmp->mData.setDistance(distances); //set the distance
	}

	//deleting pointers
	delete[] distances;
	delete[] savedBools;

	//putting predictions into file
	newData.savePredictions();

}

/*Pre: file to read mushroom data from, bool to see if the file in the first argument is the file that has the unknown mushrooms
* Post: mushroom data loaded into the linked list
* Purpose: load mushroom data into linked list
*/
void LinkedList::loadData(const std::string FILE_NAME, bool isTestFile)
{
	std::ifstream fin;
	Mushroom newMushroom;
	std::string junk;

	fin.open(FILE_NAME);
	if (fin.fail()) { std::cout << FILE_NAME << " failed to open" << std::endl; }
	else
	{
		//if the file is the one that has the unknown mushrooms
		if (isTestFile)
		{
			getline(fin, junk);//the k value gets assigned in another fxn, so it is ignored
		}
		
		while (!fin.eof())
		{
			fin >> newMushroom;
			insertAtBack(newMushroom);
		}
		if (!isTestFile) { mCount--; } //for some reason the file with the known mushrooms always has an mCount one larger than the actual count
	}
}

/*Pre: none
* Post: predictions printed in output file
* Purpose: To print the predictions of unknown mushrooms to the output file
*/
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
	//create new output file
	output.open(PREDICTIONS_DATA_FILE);

	Node* tmp;

	for (tmp = mHead; tmp != nullptr; tmp = tmp->mNext)
	{
		output << tmp->mData;
	}
	output.close();
}



/**************************************************************************************************************************************
* Operator Overloading
***************************************************************************************************************************************/


/*Pre: Node on the left side, Mushrrom on the right
* Post: mushroom is set to mData in the node
* Purpose: to add the mushroom data to the mData in the Node
*/
LinkedList::Node& LinkedList::Node::operator=(Mushroom& rhs)
{
	mData = rhs;
	return *this;
}

/*Pre: ofstream on left, Mushroom type on right
* Post: mushroom classification printed to ofstream
* Purpose: To print mushroom classification to the ofstream
*/
std::ofstream& operator<<(std::ofstream& output, Mushroom obj)
{
	if (obj.getIsPoisonous()) { output << "poisonous"; }
	else { output << "edible"; }

	output << std::endl;
	return output;
}

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "mushroom.h"

const std::string KNOWN_DATA_FILE = "../../../data.txt";
const std::string UNKNOWN_DATA_FILE = "../../../input.txt";
const std::string PREDICTIONS_DATA_FILE = "../../../predictions.txt";

class LinkedList
{
	struct Node
	{
		Mushroom mData;
		Node* mNext;

		Node();
		Node(Mushroom data);

		Node& operator=(Mushroom& rhs);
	};
	private:
		Node* mHead, *mTail;
		int mCount;


	public:
		LinkedList();
		~LinkedList();
		void insertAtBack(Mushroom data);
		int getMCount();
		void loadData(const std::string FILE_NAME, bool isTestFile = false);
		int getDataAttribute(int Nodeindex, int AttrIndex);
		void getMushroomDistance(int index);
		void mushroomDistances(Mushroom testCase);
		void makePredictions(LinkedList& knownData, LinkedList& newData, const std::string newFile);
		void loopMushroomsforDistances();
		void savePredictions();
		
		
		friend std::ofstream& operator<<(std::ofstream& output, Mushroom obj);

		
};



#endif // !LINKED_LIST

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "mushroom.h"



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
		void loadData(const std::string FILE_NAME);
		int getDataAttribute(int Nodeindex, int AttrIndex);
		void getMushroomDistance(int index);
		void mushroomDistances(Mushroom testCase);
		void makePredictions(LinkedList knownData, const std::string newFile);
		void loopMushroomsforDistances();
		
		


		
};



#endif // !LINKED_LIST
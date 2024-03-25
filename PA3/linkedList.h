
#ifndef LINKEDLIST
#define LINKEDLIST

#include "mushroom.h"

const std::string FILE_NAME = "../../../data.txt";


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
		void loadData();
		int getDataAttribute(int Nodeindex, int AttrIndex);
		void mushroomDistances();
		


		
};



#endif // !LINKED_LIST
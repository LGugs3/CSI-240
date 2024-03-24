
#ifndef LINKEDLIST
#define LINKEDLIST

#include "mushroom.h"

class LinkedList
{
	struct Node
	{
		Mushroom mData;
		Node* mNext;

		Node();
		Node(Mushroom data);

		Node operator=(Mushroom rhs);
	};
	private:
		Node* mHead, *mTail;
		int mCount;


	public:
		void insertAtBack(Mushroom data);


		
};



#endif // !LINKED_LIST
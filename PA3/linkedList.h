
#ifndef LINKED_LIST
#define LINKED_LIST

#include "mushroom.h"

class LinkedList
{
	struct Node
	{
		Mushroom mData;
		Node* mNext;

		Node();
		Node(Mushroom data);
	};
	private:
		Node* mHead, mTail;

};



#endif // !LINKED_LIST
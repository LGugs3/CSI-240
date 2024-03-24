
#include "linkedList.h"

LinkedList::Node::Node()
{
	//mData = smth
	mNext = nullptr;
}

LinkedList::Node::Node(Mushroom data)
{
	mData = data; //overload
	mNext = nullptr;
}

#include "linkedList.h"

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

LinkedList::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
}

void LinkedList::insertAtBack(Mushroom data)
{
	Node* newNode;

	newNode = new Node(data); //need to overload

	if (mCount == 0)
	{
		mHead = newNode;
		mTail == newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
	}
	mCount++;
}



LinkedList::Node LinkedList::Node::operator=(Mushroom rhs)
{
	mData = rhs;
	return *this;
}

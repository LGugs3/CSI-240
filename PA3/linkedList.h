/*
Author: Liam Gugliotta
Class : CSI-240-04
Assignment : PA3
Date Assigned : 03/22/2024
Due Date : Due - 03/29/2024 13:00 EST
Description :
Header file that defines the LinkedList class and Node struct declarations.
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
		void makePredictions(LinkedList& knownData, LinkedList& newData, const std::string newFile);
		void savePredictions();
		
		
		friend std::ofstream& operator<<(std::ofstream& output, Mushroom obj);

		
};

#endif // !LINKED_LIST
#include "SkipList.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Node.h"


SkipList::SkipList()
{
	head = new Node();
	tail = new Node();
	
	maxHeight = head->getNodeHeight();

	for (int i = maxHeight - 1; i >= 0; i--)
	{
		head->assignForwardPtrTo(i, tail);
	}


}


SkipList::~SkipList()
{
	//recursiveDeconstruction(head);

	itterativeDeconstruction();

}

//Recursive deconstructor! Trying someting new.
void SkipList::recursiveDeconstruction(Node* nodePtr)
{
	if (nodePtr->forwardNode(0) != nullptr)
	{
		recursiveDeconstruction(nodePtr->forwardNode(0));
	}
	delete nodePtr;
}

void SkipList::itterativeDeconstruction()
{
	Node * nextNode;
	skipItt = head;

	while (skipItt != nullptr)
	{
		nextNode = skipItt->forwardNode(0);
		delete skipItt;
		skipItt = nextNode;
	}

}

bool SkipList::insert(string argWord)
{
	bool inserted = false;
	string rootWord;

	//Check if word exists

	rootWord = formatWord(argWord);

	prvtInsert(rootWord);

	return inserted;
}

bool SkipList::prvtInsert(string argWord)
{
	bool inserted = true;
	Node* newNode = new Node(argWord);
	int newNodeHeight = newNode->getNodeHeight();

	//Check node tower size
	while (maxHeight < newNodeHeight)
	{
		maxHeight++;
		head->pushBackTower(tail);
	}

	skipItt = head;

	for (int i = newNodeHeight - 1; i >= 0; i--)
	{
		while (skipItt->forwardNode(i)->getData() < argWord && skipItt->forwardNode(i) != tail)
		{
			skipItt = skipItt->forwardNode(i);
		}

		//Attach Node at level i
		newNode->assignForwardPtrTo(i, skipItt->forwardNode(i));
		skipItt->assignForwardPtrTo(i, newNode);

	}


	return inserted;
}

bool SkipList::prvtfind(const string argWord)
{

	return false;
}

//Format word function
string SkipList::formatWord(string argString)
{
	string formatedString;
	for (int i = 0; i < argString.size() && !ispunct(argString[i]); i++)
	{
		formatedString += tolower(argString[i]);
	}

	return formatedString;
}

ostream& operator << (ostream& outputStream, const SkipList& list)
{
	int maxIndex = list.getMaxHeight() - 1;
	Node * nodeItt = list.getHead()->forwardNode(maxIndex);

	if (nodeItt != list.getTail())
	{
		for (int i = maxIndex; i >= 0; i--)
		{
			nodeItt = list.getHead()->forwardNode(i);
			outputStream << "Level " << i + 1 << ": ";

			while (nodeItt != list.getTail())
			{
				outputStream << nodeItt->getData();
				nodeItt = nodeItt->forwardNode(i);

				nodeItt != list.getTail() ? outputStream << ", " : outputStream << "\n";
			}
		}
	}
	else
	{
		outputStream << "Emply List!\n";
	}

	return outputStream;
}

int SkipList::getMaxHeight() const
{
	return maxHeight;
}

Node* SkipList::getHead() const
{
	return head;
}

Node* SkipList::getTail() const 
{
	return tail;
}
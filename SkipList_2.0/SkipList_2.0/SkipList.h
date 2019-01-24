#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;

class SkipList
{
private:
	Node* skipItt;
	Node* head;
	Node* tail;
	int maxHeight;

	//Functions
	bool prvtInsert(string argWord);

	bool prvtfind(const string argWord);

	string formatWord(string argstring);

	void recursiveDeconstruction(Node* nodePtr);
	void itterativeDeconstruction();

	

public:
	SkipList();
	~SkipList();

	bool insert(string argWord);

	bool find(const string argWord);

	friend ostream& operator << (ostream& outputStream, const SkipList& list);

	int getMaxHeight() const;

	Node* getHead() const;

	Node* getTail() const;
};


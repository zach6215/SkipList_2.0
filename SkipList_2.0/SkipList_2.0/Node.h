#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Node
{
private:
	vector <Node *> forward;
	string data;


public:
	Node();
	Node(string argString);
	~Node();

	void changeForwardSizeTo(int argMaxHeight);
	void assignForwardPtrTo(int argIndex, Node * argNode);
	void pushBackTower(Node* argNode);

	int getNodeHeight();
	Node * forwardNode(int argIndex);
	string getData();
};


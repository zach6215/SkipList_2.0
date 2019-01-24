#include "Node.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>


Node::Node()
{
	//Nodes always have at least hieght of one
	forward.push_back(nullptr);

	//Coin flip to decide tower height
	while (rand() % 2)
	{
		forward.push_back(nullptr);
	}
}


Node::~Node()
{
}

Node::Node(string argNode)
{
	data = argNode;

	//Nodes always have at least hieght of one
	forward.push_back(nullptr);

	//Coin flip to decide tower height
	while (rand() % 2)
	{
		forward.push_back(nullptr);
	}

}

void Node::changeForwardSizeTo(int argMaxHeight)
{


}

void Node::assignForwardPtrTo(int argIndex, Node * argNode)
{
	forward[argIndex] = argNode;
}

int Node::getNodeHeight()
{
	return forward.size();
}

void Node::pushBackTower(Node* argNode)
{
	forward.push_back(argNode);
}

Node * Node::forwardNode(int argIndex)
{
	return forward[argIndex];
}

string Node::getData()
{
	return data;
}
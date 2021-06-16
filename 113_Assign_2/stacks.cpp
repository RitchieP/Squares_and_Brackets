#include "Stacks.h"

//Initialize stacks with a empty head node
Stacks::Stacks()
{
	top = nullptr;
}

//Delete all nodes from memory space
Stacks::~Stacks()
{
	Node* nodePtr;
	Node* nextNode;

	nodePtr = top;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//Pushes instructions onto the stack
void Stacks::push(int instructions)
{
	Node* newNode;
	newNode = new Node();

	newNode->instructions = instructions;

	if (top == nullptr)
	{
		top = newNode;
		top->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

//Removes and returns the value of the top element in the stack
int Stacks::pop()
{
	Node* temp = nullptr;
	int insLabel = 0;

	if (top == nullptr)
	{
		std::cout << "Error! Stack is empty." << std::endl;
	}
	else
	{
		insLabel = top->instructions;
		temp = top;
		top = top->next;
		delete temp;
	}

	return insLabel;
}

/*
	Returns the size of the stack
	Which is the number of nodes inside the stack
*/
int Stacks::sizeOfStack()
{
	int count = 0;
	Node* nodePtr;
	nodePtr = top;

	if (nodePtr == nullptr)
	{
		return 0;
	}
	else
	{
		while (nodePtr != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		count++;
	}

	return count;
}
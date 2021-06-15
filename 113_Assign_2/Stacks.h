#pragma once
#ifndef STACKS_H
#define STACKS_H

#include <string>
#include <iostream>

class Stacks
{
public:
	Stacks();
	~Stacks();

	void push(int);
	int pop();
	int sizeOfStack();

private:
	struct Node
	{
		int instructions;
		struct Node* next;
	};

	Node* top;
};


#endif // !STACKS_H

#pragma once
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <string>

template <typename T>
class CircularLinkedList
{
public:
	CircularLinkedList();
	~CircularLinkedList();

	void appendNode(T);
	T nextNode(int);
	void setPos(int, int);
	bool checkSymbol(std::string);
	int findNode(std::string);
	int getNodePos(int);

private:
	struct Node
	{
		T value;
		struct Node* next;
	};

	Node* head;
};

//Initialize empty Linked List
template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
	head = nullptr;
}

//Delete Linked List
template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
	Node* nodePtr;
	Node* nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

/*
	Append Node at the end of the list
	The head pointer will always stay the same
*/
template <typename T>
void CircularLinkedList<T>::appendNode(T newVal)
{
	Node* newNode;
	Node* nodePtr;
	newNode = new Node();

	nodePtr = head;
	newNode->value = newVal;

	if (nodePtr == nullptr)
	{
		head = newNode;
		head->next = head;
	}
	else
	{
		while (nodePtr->next != head)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		newNode->next = head;
	}
}

//Return the value of the next Node
/*
	In this project, T refers to Player object.
		It will return the current Player based on 
		the turns.

	For instance, when n==3, will return 3rd player
		as object.
	
	Also, to avoid it looped inefficiently(n may be 1< n <=30),
	 inside game.cpp, we only passed which player's turn by using
	 formula:

	 currentPlayer = (roundNumber % 4)

	Why we use this formula? 
	
	See more details inside game.cpp -> startGame()!
*/
template <typename T>
T CircularLinkedList<T>::nextNode(int n)
{
	Node* nodePtr;
	nodePtr = head;
	int count = 0;
	while (count < n) {
		nodePtr = nodePtr->next;
		count++;
	}

	return nodePtr->value;
}

/*
	Set position of the current value
	Takes in two integer values a arguments
	First integer parameter is the number of current player
	if the value passsed is 0, it means the current player is the first player
	Second integer parameter is the latest position of the player on the map
*/
template <typename T>
void CircularLinkedList<T>::setPos(int n, int LatestPos)
{
	//will loop until reach requested player---(Player 1-4)
	Node* nodePtr;
	nodePtr = head;
	int count = 0;
	while (count < n) {
		nodePtr = nodePtr->next;
		count++;
	}

	//Set the latest position of the selected player to its Object
	nodePtr->value.setPosition(LatestPos);
}

/*
	To check whether the symbol entered is available
	Takes in a string value as argument
	Returns a boolean value
	Used in game.cpp wildCardPlay() function
*/
template <typename T>
bool CircularLinkedList<T>::checkSymbol(std::string targetSymbol)
{
	bool flag = false;
	Node* nodePtr;
	nodePtr = head;

	if (nodePtr == nullptr)
	{
		std::cout << "Error, Circular Linked List is empty." << std::endl;
		std::cout << "Inside Circular Linked List checkSymbol() function." << std::endl;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (nodePtr->value.getSymbol() == targetSymbol)
			{
				flag = true;
				break;
			}

			nodePtr = nodePtr->next;
		}
	}

	return flag;
}

/*
	Find the order of the player through the node
	Takes in a string as an argument which is the target player, passing in as their symbol
	Returns an integer value which is the order of the targeted player
*/
template <typename T>
int CircularLinkedList<T>::findNode(std::string targetSymbol)
{
	int count = 0;
	Node* nodePtr = head;

	while (nodePtr != nullptr)
	{
		if (nodePtr->value.getSymbol() == targetSymbol)
		{
			break;
		}
		else
		{
			nodePtr = nodePtr->next;
		}
		count++;
	}

	return count;
}


/*
	Get the value of position of the current node
	Takes in an integer value as argument which is the order of player
	Returns an integer value which is the position of the player on the map
*/
template <typename T>
int CircularLinkedList<T>::getNodePos(int n)
{
	Node* nodePtr;
	nodePtr = head;
	int count = 0;

	while (count < n) {
		nodePtr = nodePtr->next;
		count++;
	}

	return nodePtr->value.getPos();
}
#endif // !CIRCULARLINKEDLIST_H

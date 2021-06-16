#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Player.h"

#include <string>
#include <iostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void appendNode(int, std::string);
	void displayAllNode();
	void initialize(Player[]);
	void deleteOldAddNew(int, int, std::string);
	std::string getPos(int);

private:
	struct Node
	{
		int value;		//Store number of each node, eg: 1-30 for 30 nodes
		std::string itemsAndPlayers;	//This is to store all items and players inside one node of the map
		struct Node* next;
	};

	Node* head;
};

#endif // !LINKEDLIST_H

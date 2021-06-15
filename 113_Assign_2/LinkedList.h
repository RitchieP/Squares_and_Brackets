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
	void deleteOld(int, std::string);
	void appendNew(int, std::string);
	void deleteOldAddNew(int, int, std::string);
	std::string getPos(int);

private:
	struct Node
	{
		int value;
		std::string itemsAndPlayers;
		struct Node* next;
	};

	Node* head;
};

#endif // !LINKEDLIST_H

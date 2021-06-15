#include "LinkedList.h"

//Initialize a empty linked list
LinkedList::LinkedList()
{
	head = nullptr;
}

//Delete all linked list in memory
LinkedList::~LinkedList()
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

//Insert node at the end of the list.
void LinkedList::appendNode(int value, std::string itemsAndPlayers)
{
	Node* newNode;
	Node* nodePtr;

	newNode = new Node();
	newNode->value = value;
	newNode->itemsAndPlayers = itemsAndPlayers;
	nodePtr = head;

	if (nodePtr == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

//Displays all the node inside the list
void LinkedList::displayAllNode()
{

	Node* nodePtr = head;
	Node* tempptr = nullptr;
	int count = 0;
	int countItems = 0;

	std::cout << "\n" << std::endl;

	while (nodePtr != nullptr)
	{

		if (count < 9)
		{
			std::cout << "   " << nodePtr->value << "   |";
		}
		else if (count >= 9)
		{
			std::cout << "   " << nodePtr->value << "  |";
		}

		if (count == 9)
		{
			std::cout << std::endl;
			nodePtr = head;
			while (countItems < 10)
			{
				std::string itemsOrPlayers = nodePtr->itemsAndPlayers;
				int len = itemsOrPlayers.length();
				if (countItems == 2)
				{
					switch (len)
					{
					case 0:
						std::cout << "[     ]|";
						break;
					case 1:
						std::cout << "[  " << itemsOrPlayers << "  ]|";
						break;
					case 2:
						std::cout << "[  " << itemsOrPlayers << " ]|";
						break;
					case 3:
						std::cout << "[ " << itemsOrPlayers << " ]|";
						break;
					case 4:
						std::cout << "[ " << itemsOrPlayers << "]|";
						break;
					case 5:
						std::cout << "[" << itemsOrPlayers << "]|";
						break;
					default:
						break;
					}
				}
				else if (countItems == 6)
				{
					switch (len)
					{
					case 0:
						std::cout << "{     }|";
						break;
					case 1:
						std::cout << "{  " << itemsOrPlayers << "  }|";
						break;
					case 2:
						std::cout << "{  " << itemsOrPlayers << " }|";
						break;
					case 3:
						std::cout << "{ " << itemsOrPlayers << " }|";
						break;
					case 4:
						std::cout << "[ " << itemsOrPlayers << "]|";
						break;
					case 5:
						std::cout << "[" << itemsOrPlayers << "]|";
						break;
					default:
						break;
					}
				}
				else
				{
					switch (len)
					{
					case 0:
						std::cout << "       |";
						break;
					case 1:
						std::cout << "   " << itemsOrPlayers << "   |";
						break;
					case 2:
						std::cout << "   " << itemsOrPlayers << "  |";
						break;
					case 3:
						std::cout << "   " << itemsOrPlayers << " |";
						break;
					case 4:
						std::cout << "  " << itemsOrPlayers << " |";
						break;
					case 5:
						std::cout << " " << itemsOrPlayers << " |";
						break;
					default:
						break;
					}
				}

				countItems++;
				if (countItems != 10)
				{
					nodePtr = nodePtr->next;
				}
				else
				{
					std::cout << std::endl;
					break;
				}
			}
			tempptr = nodePtr->next;
			std::cout << "________________________________________________________________________________" << std::endl;
			countItems = 0;
		}
		else if (count == 19 || count == 29)
		{
			std::cout << std::endl;
			nodePtr = tempptr;
			while (countItems < 10)
			{
				std::string itemsOrPlayers = nodePtr->itemsAndPlayers;
				int len = itemsOrPlayers.length();
				if (count < 20)
				{
					if (countItems == 1)
					{
						switch (len)
						{
						case 0:
							std::cout << "{     }|";
							break;
						case 1:
							std::cout << "{  " << itemsOrPlayers << "  }|";
							break;
						case 2:
							std::cout << "{  " << itemsOrPlayers << " }|";
							break;
						case 3:
							std::cout << "{ " << itemsOrPlayers << " }|";
							break;
						case 4:
							std::cout << "[ " << itemsOrPlayers << "]|";
							break;
						case 5:
							std::cout << "[" << itemsOrPlayers << "]|";
							break;
						default:
							break;
						}
					}
					else if (countItems == 5)
					{
						switch (len)
						{
						case 0:
							std::cout << "[     ]|";
							break;
						case 1:
							std::cout << "[  " << itemsOrPlayers << "  ]|";
							break;
						case 2:
							std::cout << "[  " << itemsOrPlayers << " ]|";
							break;
						case 3:
							std::cout << "[ " << itemsOrPlayers << " ]|";
							break;
						case 4:
							std::cout << "[ " << itemsOrPlayers << "]|";
							break;
						case 5:
							std::cout << "[" << itemsOrPlayers << "]|";
							break;
						default:
							break;
						}
					}
					else
					{
						switch (len)
						{
						case 0:
							std::cout << "       |";
							break;
						case 1:
							std::cout << "   " << itemsOrPlayers << "   |";
							break;
						case 2:
							std::cout << "   " << itemsOrPlayers << "  |";
							break;
						case 3:
							std::cout << "   " << itemsOrPlayers << " |";
							break;
						case 4:
							std::cout << "  " << itemsOrPlayers << " |";
							break;
						case 5:
							std::cout << " " << itemsOrPlayers << " |";
							break;
						default:
							break;
						}
					}
				}
				else
				{
					if (countItems == 2 || countItems == 6)
					{
						switch (len)
						{
						case 0:
							std::cout << "{     }|";
							break;
						case 1:
							std::cout << "{  " << itemsOrPlayers << "  }|";
							break;
						case 2:
							std::cout << "{  " << itemsOrPlayers << " }|";
							break;
						case 3:
							std::cout << "{ " << itemsOrPlayers << " }|";
							break;
						case 4:
							std::cout << "{ " << itemsOrPlayers << "}|";
							break;
						case 5:
							std::cout << "[" << itemsOrPlayers << "]|";
							break;
						default:
							break;
						}
					}
					else
					{
						switch (len)
						{
						case 0:
							std::cout << "       |";
							break;
						case 1:
							std::cout << "   " << itemsOrPlayers << "   |";
							break;
						case 2:
							std::cout << "   " << itemsOrPlayers << "  |";
							break;
						case 3:
							std::cout << "   " << itemsOrPlayers << " |";
							break;
						case 4:
							std::cout << "  " << itemsOrPlayers << " |";
							break;
						case 5:
							std::cout << " " << itemsOrPlayers << " |";
							break;
						default:
							break;
						}
					}
				}

				countItems++;
				if (countItems != 10)
				{
					nodePtr = nodePtr->next;
				}
				else
				{
					break;
				}
			}
			tempptr = nodePtr->next;
			std::cout << "\n________________________________________________________________________________" << std::endl;
			countItems = 0;
		}
		nodePtr = nodePtr->next;
		count++;
	}
}

void LinkedList::initialize(Player players[])
{
	for (int i = 0; i < 4; i++)
	{
		head->itemsAndPlayers.append(players[i].getSymbol());
	}

	displayAllNode();
}

//Return all items in certain requested Node
//Takes in an integer valuie as argument
//Integer argument is the position on the map
std::string LinkedList::getPos(int n)
{

	//will loop until reach requested node
	Node* nodePtr = nullptr;
	nodePtr = head;
	for (int i = 0; i < n; i++)
	{
		nodePtr = nodePtr->next;
	}

	//return items of the FOUND requested node
	return nodePtr->itemsAndPlayers;
}

//old = old position, current = current position, may be > or < old position
void LinkedList::deleteOldAddNew(int old, int current, std::string symbol)
{
	//declare variables
	int c = 0;
	Node* nodePtr;
	nodePtr = head;

	if (old == current)
	{
		std::cout << "IT IS GOOODODODODOD" << std::endl;
	}
	else if (old < current)
	{
		std::string itemsAndPlayer = nodePtr->itemsAndPlayers;

		while (c <= current)
		{
			if (c == old)
			{
				std::cout << "old<current, "<<symbol<< "Before: "<< nodePtr->itemsAndPlayers << std::endl;
				//find the symbol index
				int index = 0;
				char target = symbol[0];
				for (int i = 0; i < nodePtr->itemsAndPlayers.length(); i++)
				{
					if (nodePtr->itemsAndPlayers.at(i) == target)
					{
						index = i;
						break;
					}
				}
				nodePtr->itemsAndPlayers.erase(index, 1);
				std::cout << "old<current, "<<symbol<< "After: "<< nodePtr->itemsAndPlayers << std::endl;
			}
			else if (c == current)
			{
				std::string itemsAndPlayer = nodePtr->itemsAndPlayers;
				itemsAndPlayer.push_back(symbol[0]);
				nodePtr->itemsAndPlayers = itemsAndPlayer;
			}
			nodePtr = nodePtr->next;
			c++;
		}
	}
	else if (old > current)
	{
		while (c <= old)
		{
			if (c == old)
			{
				std::string itemsAndPlayer = nodePtr->itemsAndPlayers;
				std::cout << "old>current, "<<symbol<<"Before: "<< nodePtr->itemsAndPlayers << std::endl;

				int index = 0;
				char target = symbol[0];
				for (int i = 0; i < nodePtr->itemsAndPlayers.length(); i++)
				{
					if (nodePtr->itemsAndPlayers.at(i) == target)
					{
						index = i;
						break;
					}
				}
				nodePtr->itemsAndPlayers.erase(index, 1);
				std::cout << "old>current, "<<symbol<< "After: "<< nodePtr->itemsAndPlayers << std::endl;
			}
			if (c == current)
			{
				std::string itemsAndPlayer = nodePtr->itemsAndPlayers;
				std::cout << "CURRENTTTTT" << std::endl;

				//Insert the character at the end of the string
				itemsAndPlayer.push_back(symbol[0]);
				nodePtr->itemsAndPlayers = itemsAndPlayer;
			}
			nodePtr = nodePtr->next;
			c++;
		}
	}
}

//Delete player from old location
void LinkedList::deleteOld(int oldLocation, std::string symbol)
{
	int c = 0;
	Node* nodePtr = nullptr;
	nodePtr = head;

	while (c != oldLocation)
	{

		nodePtr = nodePtr->next;
		c++;
	}
	if (c == oldLocation)
	{
		std::string itemsAndPlayer = nodePtr->itemsAndPlayers;

		int index = 0;
		char target = symbol[0];
		for (int i = 0; i < itemsAndPlayer.length(); i++)
		{
			if (nodePtr->itemsAndPlayers.at(i) == target)
			{
				index = i;
				break;
			}
		}
		nodePtr->itemsAndPlayers.erase(index, 1);
	}
}

//Append player to new location
void LinkedList::appendNew(int newLocation, std::string symbol)
{
	int c = 0;
	Node* nodePtr = nullptr;
	nodePtr = head;

	while (c <= newLocation)
	{

		if (c == newLocation)
		{
			nodePtr->itemsAndPlayers = nodePtr->itemsAndPlayers.append(symbol);
		}
		nodePtr = nodePtr->next;
		c++;
	}
}

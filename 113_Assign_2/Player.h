#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
	Player();
	~Player();

	void setName(std::string);
	void setSymbol(std::string);
	void setPosition(int);
	void setGroupNumber(int);
	std::string getName();
	std::string getSymbol();
	int getGroupNumber();
	int getPos();

private:
	std::string name;
	std::string symbol;
	int pos;
	int groupNumber;
};

#endif // !PLAYERS_H

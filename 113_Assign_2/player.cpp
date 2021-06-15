#include "Player.h"

//constructor
Player::Player()
{
	name = "";
	symbol = "";
	pos = 0;
	groupNumber=0;
}

//destructor function
Player::~Player()
{
}

//Function to set Name
//Takes in a string value as argument
void Player::setName(std::string name){
    this->name = name;
}

//Function to set Symbol
//Takes in a string value as argument
void Player::setSymbol(std::string symbol){
	this->symbol = symbol;
}

//Function to set Position
//Takes in an integer value as argument
void Player::setPosition(int pos){
	this->pos = pos;
}

//Function to set Group Number
//Takes in an integer value as argument
void Player::setGroupNumber(int gN){
	this->groupNumber = gN;
}

//Getter function of name
//Returns a string value
std::string Player::getName()
{
	return name;
}

//Getter function of Symbol
//Returns a string value
std::string Player::getSymbol()
{
	return symbol;
}

//Getter function of Position
//Returns an integer value
int Player::getPos()
{
	return pos;
}

//Getter function of GroupNumber
//Returns an integer value
int Player::getGroupNumber(){
	return groupNumber;
}
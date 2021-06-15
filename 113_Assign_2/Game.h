#pragma once
#ifndef GAME_H
#define GAME_H

#include "LinkedList.h"
#include "Stacks.h"
#include "CircularLinkedLists.h"
#include "Player.h"

#include <stdlib.h>
#include <time.h>

class Game
{
public:
	Game();
	~Game();

	void printUpdatedMap();
    int throwDice();

    void randomWildCards();
    void printWildCard(int);
    bool checkPosWildCard(Player&);
    int getWildCard();
    void wildCardPlay(int, Player&, int);

    void printDice(int);
    bool isNotWon();
    void initializeAllPlayers(Player[]);
    void startGame();

private:
    CircularLinkedList<Player> playerList;
    LinkedList linklist;
    Stacks stack;
    
    int winGroupNumber = 0;
    int totalRound = 0;

    int ins1 = 1, ins2 = 2, ins3 = 3, ins4 = 4;


    /*std::string ins1 = "Move a player back 5 steps.";
    std::string ins2 = "Move a player back 10 steps";
    std::string ins3 = "Promote yourself 5 steps";
    std::string ins4 = "Promote yourself 10 steps";*/
};

#endif // !GAME_H

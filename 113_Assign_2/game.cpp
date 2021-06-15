#include "Game.h"

//Constructor
Game::Game()
{
	//Initialize random seed with time
	srand(time(NULL));

	for (int i = 1; i <= 30; i++)
	{
		if (i == 4 || i == 10 || i == 17 || i == 22 || i == 28)
		{
			linklist.appendNode(i, "!");
		}
		else
		{
			linklist.appendNode(i, "");
		}
	}
}

//Destructor
Game::~Game()
{
}

//Prints the map with players position
void Game::printUpdatedMap()
{
	linklist.displayAllNode();
}

//Throws the dice
//Returns an integer value
int Game::throwDice()
{

	int randomDice = rand() % 6 + 1;

	return randomDice;
}

//Randomly insert wild instructions onto the stack.
void Game::randomWildCards()
{
	int randNum;

	//Randomly insert ten instructions into the stack
	for (int i = 1; i <= 10; i++)
	{
		randNum = rand() % 4 + 1;

		switch (randNum)
		{
		case 1:
			stack.push(ins1);
			break;
		case 2:
			stack.push(ins2);
			break;
		case 3:
			stack.push(ins3);
			break;
		case 4:
			stack.push(ins4);
			break;
		default:
			std::cout << "Error, randomized number does not match the switch cases." << std::endl;
			break;
		}
	}
}

//Print the instruction of the wild card
//If the player position is a wild card position
void Game::printWildCard(int insLabel)
{
	switch (insLabel)
	{
	case 1:
		std::cout << "\n_________________________________________________\n";
		std::cout << "|Move a player back 5 steps\n|\n|_________________________________________________\n";
		break;
	case 2:
		std::cout << "\n_________________________________________________\n";
		std::cout << "|Move a player back 10 steps\n|\n|_________________________________________________\n";
		break;
	case 3:
		std::cout << "\n_________________________________________________\n";
		std::cout << "|Promote yourself 5 steps\n|\n|_________________________________________________\n";
		break;
	case 4:
		std::cout << "\n_________________________________________________\n";
		std::cout << "|Promote yourself 10 steps \n|\n|_________________________________________________\n";
		break;
	default:
		break;
	}
}

//Check whether the player position is a wild card position
bool Game::checkPosWildCard(Player& curPlayer)
{
	if (linklist.getPos(curPlayer.getPos()).at(0) == '!')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Play of the wild card
//Takes in an integer as argument
//Integer argument determines which wild card play should be performed.
void Game::wildCardPlay(int insLabel, Player& curPlayer, int newPos)
{
	std::string userChoice;
	int orderPlayer = 0, posPlayer = 0;

	switch (insLabel)
	{
		//Throw a player back 5
	case 1:
		std::cout << "Select a player to move by keying in their symbol." << std::endl;
		std::cin >> userChoice;

		//Validate the input to have the available player
		//And not choose themselves
		while (!playerList.checkSymbol(userChoice) && userChoice != curPlayer.getSymbol())
		{
			std::cout << "Invalid input, try again." << std::endl;
			std::cin >> userChoice;
		}

		//This is to get the player order, and the position of the player
		orderPlayer = playerList.findNode(userChoice);
		posPlayer = playerList.getNodePos(orderPlayer);

		//If the player moved backwards is less than the starting point
		//It will stop at zero a.k.a starting point
		if (posPlayer - 5 < 0)
		{
			playerList.setPos(orderPlayer, 0);
			std::cout << "selected: " << userChoice << ", old: " << posPlayer << ", new: 0" << std::endl;
			linklist.deleteOldAddNew(posPlayer, 0, userChoice);
		}
		else
		{
			playerList.setPos(orderPlayer, posPlayer - 5);
			std::cout << "selected: " << userChoice << "old: " << posPlayer << ", new: " << posPlayer - 5 << std::endl;
			linklist.deleteOldAddNew(posPlayer, posPlayer - 5, userChoice);
		}

		break;

		//Throw a player back 10 steps
	case 2:
		std::cout << "Select a player to move by keying in their symbol." << std::endl;
		std::cin >> userChoice;

		//Validate the input to have the available player
		while (!playerList.checkSymbol(userChoice))
		{
			std::cout << "Invalid input, try again." << std::endl;
			std::cin >> userChoice;
		}

		//This is to get the player order, and the position of the player
		orderPlayer = playerList.findNode(userChoice);
		posPlayer = playerList.getNodePos(orderPlayer);

		//If the player moved backwards is less than the starting point
		//It will stop at zero a.k.a starting point
		if (posPlayer - 10 < 0)
		{
			playerList.setPos(orderPlayer, 0);
			std::cout <<"selected: "<<userChoice<<"old: "<< posPlayer <<", new: 0"<< std::endl;
			linklist.deleteOldAddNew(posPlayer, 0, userChoice);
		}
		else
		{
			playerList.setPos(orderPlayer, posPlayer - 10);
			std::cout <<"selected: "<<userChoice<<"old: "<< posPlayer <<", new: "<<posPlayer-10<< std::endl;
			linklist.deleteOldAddNew(posPlayer, posPlayer - 10, userChoice);
		}

		break;

		//Promote 5
		//TODO: Fix position issue
	case 3:
		orderPlayer = playerList.findNode(curPlayer.getSymbol());

		if (newPos + 5 > 29)
		{
			posPlayer = 58 - (newPos + 5);
		}
		else
		{
			posPlayer = newPos + 5;
		}
		playerList.setPos(orderPlayer, posPlayer);
		std::cout <<"selected: "<<curPlayer.getSymbol()<<"old: "<< newPos <<", new: "<<posPlayer<< std::endl;
		linklist.deleteOldAddNew(newPos, posPlayer, curPlayer.getSymbol());


		break;

		//Promote 10
	case 4:
		orderPlayer = playerList.findNode(curPlayer.getSymbol());

		if (newPos + 10 > 29)
		{
			posPlayer = 58 - (newPos + 10);
		}
		else
		{
			posPlayer = newPos + 10;
		}
		playerList.setPos(orderPlayer, posPlayer);
		std::cout <<"selected: "<<curPlayer.getSymbol()<<"old: "<< newPos <<", new: "<<posPlayer<< std::endl;
		linklist.deleteOldAddNew(newPos, posPlayer, curPlayer.getSymbol());

		break;

		//Display error message
	default:
		std::cout << "Error, something went wrong in wildCardPlay() function." << std::endl;

		break;
	}
}

//Return the wild card popped from a stack of Wild Cards
int Game::getWildCard()
{
	return stack.pop();
}

//Print dice, takes in an integer as an argument.
void Game::printDice(int n)
{
	if (n == 1)
	{
		std::cout << " _____ \n"
			<< "|     |\n"
			<< "|  *  |\n"
			<< "|     |\n";
	}
	else if (n == 2)
	{
		std::cout << " _____ \n"
			<< "| *   |\n"
			<< "|     |\n"
			<< "|   * |\n";
	}
	else if (n == 3)
	{
		std::cout << " _____ \n"
			<< "| *   |\n"
			<< "|  *  |\n"
			<< "|   * |\n";
	}
	else if (n == 4)
	{
		std::cout << " _____ \n"
			<< "| * * |\n"
			<< "|     |\n"
			<< "| * * |\n";
	}
	else if (n == 5)
	{
		std::cout << " _____ \n"
			<< "| * * |\n"
			<< "|  *  |\n"
			<< "| * * |\n";
	}
	else if (n == 6)
	{
		std::cout << " _____ \n"
			<< "| * * |\n"
			<< "| * * |\n"
			<< "| * * |\n";
	}

	std::cout << std::endl;
}

//Determine whether the game has ended or not.
//Returns a boolean value
bool Game::isNotWon()
{
	return (winGroupNumber == 0);
}

//Insert the order of players from arrays of object ( parameter passed from main.cpp )
//  into the Circular Linked List
void Game::initializeAllPlayers(Player players[])
{
	playerList.appendNode(players[0]);
	playerList.appendNode(players[1]);
	playerList.appendNode(players[2]);
	playerList.appendNode(players[3]);

	linklist.initialize(players);
}

//The game will be runned in here
/*
	This is the main part of the game. Task including
	tracking the current player, updating the map, and
	determining win situation are done here.

	This is also the most complex part of this project. We
	wrote some comments to help you to understand it.
*/
void Game::startGame()
{

	//To keep track of the current player
	/*
		We store the player object using the circular linked list. We pass which player
		  we need to store as parameter.

		Why we use totalRound%4 here?

		Because we dont have to travel unnecessary loops,
		  We just have to determine which player, not travel
		  whole map.

		For Instance:
			Total round = 5, this means is the First player's Round,

		Why? because 5%4 = 1

	*/
	Player currentPlayer = playerList.nextNode(totalRound % 4);
	int diceRolled, groupNumber, currentLocation, newPos;
	diceRolled = 0;
	std::string name, symbol, any;
	int wildCards = 0;

	randomWildCards();

	std::cout << "\n|-----------------------------------------------Game Start-----------------------------------------------------|\n"
		<< std::endl;

	//The program will continue until the game ends
	while (isNotWon())
	{
		//Get current player's info
		name = currentPlayer.getName();
		currentLocation = currentPlayer.getPos();
		groupNumber = currentPlayer.getGroupNumber();

		//Inform user which player's turn now
		std::cout << "\n_________________________________________________\n|\n|Now is Team #" << groupNumber << " " << name << "'s turn. Enter any key to roll dice.... ";
		std::cin >> any;
		std::cout << "|_________________________________________________";
		//Always wait until the user enters any key
		if (any != "")
		{

			//Start roll dice
			diceRolled = throwDice();

			//Print user threw how many points from dice
			std::cout << "\n" << name << " threw " << diceRolled << std::endl;
			printDice(diceRolled);

			/*
				We need to check whether the player rolled dice and exceed the limit, aka 30th nodes.
				If he exceeded, he will bounced back from 30th node.

				How we overcome it?
					We use 60 and minus the new location( which player exceeded the limit)

				For instance:
					if user is on 28th location, and he rolled 6. If we add up, will get 34th.
					This had exceeded the limit, 30th node.

				We calculated using the formula : correct position = 2 * 29 - (old location + dice rolled)
					Example: correct position = 2*29 - (28+6) = 24
			*/
			if ((currentLocation + diceRolled) > 29)
			{
				newPos = 58 - (currentLocation + diceRolled);
			}
			else
			{
				newPos = currentLocation + diceRolled;
			}

			//Wild card plays
			if (newPos == 3 || newPos == 9 || newPos == 16 || newPos == 21 || newPos == 27)
			{
				//Retreieve the new position first, then play the wild cards based off from there
				playerList.setPos(totalRound % 4, newPos);
				linklist.deleteOldAddNew(currentLocation, newPos, currentPlayer.getSymbol());
				currentLocation = newPos;
				printUpdatedMap();

				currentPlayer = playerList.nextNode(totalRound % 4);
				wildCards = getWildCard();
				printWildCard(wildCards);
				wildCardPlay(wildCards, currentPlayer, newPos);
				//Because wild card three and four is promoting themselves, have to update here
				if (wildCards == 3 || wildCards == 4)
				{
					newPos = currentPlayer.getPos();
				}
				currentLocation= newPos;
				playerList.setPos(totalRound % 4, currentLocation);
			}

			//Teleportation plays
			if (newPos == 2)
			{
				newPos += 2;
				std::cout << "\n__________________________________________________\n";
				std::cout << "|Move front 2 steps. To: " << newPos << "\n|\n|_________________________________________________\n";
			}
			else if (newPos == 6)
			{
				newPos -= 5;
				std::cout << "\n_________________________________________________\n";
				std::cout << "|Move back 5 steps. To: " << newPos << "\n|\n|_________________________________________________\n";
			}
			else if (newPos == 11)
			{
				newPos -= 3;
				std::cout << "\n_________________________________________________\n";
				std::cout << "|Move back 3 steps. To: " << newPos << "\n|\n|_________________________________________________\n";
			}
			else if (newPos == 15)
			{
				newPos += 4;
				std::cout << "\n_________________________________________________\n";
				std::cout << "|Move front 4 steps. To: " << newPos << "\n|\n|_________________________________________________\n";
			}
			else if (newPos == 22)
			{
				newPos -= 5;
				std::cout << "\n_________________________________________________\n";
				std::cout << "|Move back 5 steps. To: " << newPos << "\n|\n|_________________________________________________\n";
			}
			else if (newPos == 26)
			{
				newPos -= 3;
				std::cout << "\n__________________________________________________\n";
				std::cout << "|Move back 3 steps. To: " << newPos << "\n|\n|_________________________________________________\n";
			}
			
			playerList.setPos(totalRound % 4, newPos);
			linklist.deleteOldAddNew(currentLocation, newPos, currentPlayer.getSymbol());
			currentLocation = newPos;

			printUpdatedMap();

			//Update the players current location
			/*
				We will send to the function, which nodes are required to update( old and new ),
					Then, we will remove the player's symbol in old and append in new position.
					These all are done using queue, not array.
			*/
			//check did some one won
			if (newPos == 29)
			{
				winGroupNumber = groupNumber;

				std::cout << "\t __      __.___ _______    _______  _____________________     \n";
				std::cout << "\t/  \\    /  \\   |\\      \\   \\      \\ \\_   _____/\\______   \\ /\\ \n";
				std::cout << "\t\\   \\/\\/   /   |/   |   \\  /   |   \\ |    __)_  |       _/ \\/ \n";
				std::cout << "\t \\        /|   /    |    \\/    |    \\|        \\ |    |   \\ /\\ \n";
				std::cout << "\t  \\__/\\  / |___\\____|__  /\\____|__  /_______  / |____|_  / \\/ \n";
				std::cout << "\t       \\/              \\/         \\/        \\/         \\/ \n";
				if (winGroupNumber == 1)
				{
					std::cout << "\t  __________________ ________   ____ _____________   ____ \n";
					std::cout << "\t /  _____/\\______   \\\\_____  \\ |    |   \\______   \\ /_   |\n";
					std::cout << "\t/   \\  ___ |       _/ /   |   \\|    |   /|     ___/  |   |\n";
					std::cout << "\t\\    \\_\\  \\|    |   \\/    |    \\    |  / |    |      |   |\n";
					std::cout << "\t \\______  /|____|_  /\\_______  /______/  |____|      |___|\n";
					std::cout << "\t        \\/        \\/         \\/                           \n";
				}
				else
				{
					std::cout << "\t  __________________ ________   ____ _____________  ________  \n";
					std::cout << "\t /  _____/\\______   \\_____  \\\\ |    |   \\______   \\ \\_____  \\ \n";
					std::cout << "\t/   \\  ___ |       _/ /   |   \\|    |   /|     ___/  /  ____/ \n";
					std::cout << "\t\\    \\_\\  \\|    |   \\/    |    \\    |  / |    |     /       \\ \n";
					std::cout << "\t \\______  /|____|_  /\\_______  /______/  |____|     \\_______ \\\n";
					std::cout << "\t        \\/        \\/         \\/                             \\/\n";
				}
				std::cout << "___________.__                   __               _____              \n";
				std::cout << "\\__    ___/|  |__ _____    ____ |  | __  ______ _/ ____\\___________  \n";
				std::cout << "  |    |   |  |  \\\\__  \\  /    \\|  |/ / /  ___/ \\   __\\/  _ \\_  __ \\ \n";
				std::cout << "  |    |   |   Y  \\/ __ \\|   |  \\    <  \\___ \\   |  | (  <_> )  | \\/ \n";
				std::cout << "  |____|   |___|  (____  /___|  /__|_ \\/____  >  |__|  \\____/|__|    \n";
				std::cout << "                \\/     \\/     \\/     \\/     \\/                       \n";
				std::cout << "__________.__                .__                                     \n";
				std::cout << "\\______   \\  | _____  ___.__.|__| ____    ____                       \n";
				std::cout << " |     ___/  | \\__  \\<   |  ||  |/    \\  / ___\\                      \n";
				std::cout << " |    |   |  |__/ __ \\\\___  ||  |   |  \\/ /_/  >                     \n";
				std::cout << " |____|   |____(____  / ____||__|___|  /\\___  /                      \n";
				std::cout << "                    \\/\\/             \\//_____/                       \n";
				exit(0);
			}
			//otherwise, increment totalround by 1.
			else
			{
				totalRound++;
				//Proceed to next Player

				/*
				Why we use totalRound%4 here?

				Because we dont have to travel unnecessary loops,
					We just have to determine which player, not travel
					whole map.

					For Instance:
					Total round = 5, this means is the First player's Round,
					Why? because 5%4 = 1
				*/
				currentPlayer = playerList.nextNode(totalRound % 4);
				wildCards = 0;
			}
		}

		//Refresh the wild card stack, if the card is finished
		if (stack.sizeOfStack() == 0)
		{
			randomWildCards();
		}
	}
}

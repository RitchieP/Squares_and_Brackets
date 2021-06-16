#include "Player.h"
#include "Game.h"

using namespace std;

void setData(Player[]);
int titleScreen();
void printRules();

int main() {

	//Print the name of our game
	cout << "  _________________   ____ ___  _____ _____________________ _________    ____     \n";
	cout << " /   _____/\\_____  \\ |    |   \\/  _  \\\\______   \\_   _____//   _____/   /  _ \\    \n";
	cout << " \\_____  \\  /  / \\  \\|    |   /  /_\\  \\|       _/|    __)_ \\_____  \\    >  _ </\\  \n";
	cout << " /        \\/   \\_/.  \\    |  /    |    \\    |   \\|        \\/        \\  /  <_\\ \\/  \n";
	cout << "/_______  /\\_____\\ \\_/______/\\____|__  /____|_  /_______  /_______  /  \\_____\\ \\  \n";
	cout << "        \\/        \\__>               \\/       \\/        \\/        \\/          \\/  \n";
	cout << "____________________    _____  _________  ____  __._______________________________\n";
	cout << "\\______   \\______   \\  /  _  \\ \\_   ___ \\|    |/ _|\\_   _____/\\__    ___/   _____/\n";
	cout << " |    |  _/|       _/ /  /_\\  \\/    \\  \\/|      <   |    __)_   |    |  \\_____  \\ \n";
	cout << " |    |   \\|    |   \\/    |    \\     \\___|    |  \\  |        \\  |    |  /        \\\n";
	cout << " |______  /|____|_  /\\____|__  /\\______  /____|__ \\/_______  /  |____| /_______  /\n";
	cout << "        \\/        \\/         \\/        \\/        \\/        \\/                  \\/\n";

	//Printing the initial prompt menu
	int choice = titleScreen();

	while (choice == 1) {
		printRules();
		choice = titleScreen();
	}

	cout << "================================================================================\n|                                                                               |\n|\tStart Game                                                              |\n|                                                                               |\n================================================================================\n";
	//Create array of objects and set the data
	Player players[4];
	setData(players);

	//start the game, initialize all players, store their data
	Game game;
	game.initializeAllPlayers(players);

	//start game!
	game.startGame();
}

bool ifRepeatedSymbol(string str, char symbol) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == symbol) return true;
	}
	return false;
}

//function to set data for all 4 players from 2 teams
void setData(Player players[]) {
	string tempName;
	string tempSymbol;
	string fourSymbols = " ";
	cout << "Insert 4 players' name and symbol: \n";
	for (int i = 0; i < 4; i++) {

		//Users will enter info for each member in sequence, one for each group
		cout << "\tPlayer " << i + 1 << " ( Team #" << (i % 2) + 1 << " ): \n";

		//users input name
		cout << "\tName: ";
		getline(cin, tempName, '\n');
		players[i].setName(tempName);

		//automatically set group number
		players[i].setGroupNumber((i % 2) + 1);

		//user input symbol chose by them
		cout << "\tSymbol: ";
		cin >> tempSymbol;
		cin.ignore();
		//Player cannot enter same symbol


		//Player cannot enter more than 1 character
		while (tempSymbol.length() != 1 || ifRepeatedSymbol(fourSymbols, tempSymbol[0])) {
			if (tempSymbol.length() != 1)
				cout << "Please enter 1 character. Enter again: ";
			else
				cout << "Symbol is already selected. Enter again: ";

			cin >> tempSymbol;
			cin.ignore();
		}

		fourSymbols.append(tempSymbol);

		players[i].setSymbol(tempSymbol);
	}
}

int titleScreen() {
	cout << "\nPlease select: \n\n\t( 1 ) Read Game Rules Before Start ( Most Recommended! )\n\t( 2 ) Start the game! ( I already played this game at least once! ) \n\n Choice:\t";
	int choice;
	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "Sorry! Choice entered invalid...Enter again! \nChoice:\t";
		cin >> choice;
	}
	cin.ignore();
	return choice;
}

void printRules() {
	cout << "================================================================================\n|                                                                               |\n|\tRules                                                                   |\n|                                                                               |\n================================================================================";
	cout << "\n\nThis is SQUARES & BRACKETS game." << endl;
	cout << "The game will be separated into two groups, each group having two persons." << endl;
	cout << "The first player and the third player will be in one group. While the other two players will be in one group.\n" << endl;

	cout << "\nThen game will proceed with each players throwing a dice," << endl;
	cout << "and the player order will be decided based on the group number from 1 to 2." << endl;
	cout << "The game will end when one player reaches the end of the map, and his/her respective group will win.\n" << endl;

	cout << "\nWhen player reach WildCard," << endl;
	cout << "Player will draw one card and do as the card told. \n" << endl;

	cout << "\nWhen player reach Portals," << endl;
	cout << "Player will teleport forward or back based on different portals. \n" << endl;

	cout << "!! Player only can do one Portal or one WildCard in each turn! \n" << endl;

}

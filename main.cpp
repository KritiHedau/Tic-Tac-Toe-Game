#include"TicTacToeGame.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {

	//system("color 02");
	system("color 06");
	char input;
	bool isDone = false;
	TicTacToeGame game;
	cout << "\t\t\t    Welcome to TicTacToe Game!!!\n";
	cout << "\t\t  ---------------------------------------------";
	while (isDone == false) {
		game.playGame();
		cout << "Would you like to play again? (Y/N)";
		cin >> input;
		if (input == 'N' || input == 'n') {
			isDone = true;
		}

	}

	system("PAUSE");
	return 0;
}

#include "TicTacToeGame.h"
#include<iostream>

using namespace std;

TicTacToeGame::TicTacToeGame() {

	
}

void TicTacToeGame::playGame() {

	clearBoard();
	char player1 = 'X';
	char player2 = 'O';
	
	char currentPlayer = 'X';
	bool isDone = false;

	int x, y, turns = 0;

	while (isDone == false) {
		printBoard();

		x = getXCoord();
		y = getYCoord();
		//place the marker
		if (placeMarker(x, y, currentPlayer) == false) {
			cout << "\n That spot is occupied\n";
		}
		else {
			turns++;
			if (checkForVictory(currentPlayer) == true) {

				cout << "\n The game is over! Player " << currentPlayer << " has won!\n";
				isDone = true;
			}
			else if(turns == 9){
				cout << "\n Its a tie game!";
				isDone = true;
			}

			//switch players
			if (currentPlayer == player1) {
				currentPlayer = player2;
			}
			else {
				currentPlayer = player1;
			}
		}
	} 
}
int TicTacToeGame::getXCoord() {

	bool isInputBad = true;
	int x;

	while (isInputBad == true) {
		
		cout << "Enter the x coordinate:\n";
		cin >> x;

		if (x < 1 || x > 3)
			cout << "Invalid Coordinate!\n";
		isInputBad = false;
	}
	return x-1;

}

int TicTacToeGame::getYCoord() {

	bool isInputBad = true;
	int y;
	while (isInputBad == true) {

		cout << "Enter the y coordinate:\n";
		cin >> y;

		if (y < 1 || y > 3)
			cout << "Invalid Coordinate!\n";
		isInputBad = false;
	}
	return y - 1;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer) {

	if (board[x][y] != ' ')
		return false;

	board[x][y] = currentPlayer;
	return true;
 }

bool TicTacToeGame::checkForVictory(char currentPlayer) {

	//check the rows
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
			return true;
		}
	}
	//check for column
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
			return true;
		}
	}

	//check top left diagonal
	if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		return true;
	}

	//check top right diagonal
	if ((board[2][0] == currentPlayer) && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
		return true;
	}

	return false;
}
void TicTacToeGame::clearBoard() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';
	}
}

void TicTacToeGame::printBoard() {

	cout << endl;
	cout << "\t\t\t\t   | 1   2   3 |\n";
	for (int i = 0; i < 3; i++) {
		cout << "\t\t\t\t ---------------\n";
		cout << "\t\t\t\t "<< i+1 << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2]<<" | \n";

	}
	cout << " \t\t\t\t----------------\n";

}


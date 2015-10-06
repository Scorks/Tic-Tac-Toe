//============================================================================
// Name        : TicTacToe.cpp
// Author      : Caro Strickland
// Version     : 1.0
// Copyright   : Use if you want, what do I care?
// Description : Simple TicTacToe game for C++
//============================================================================

#include <iostream>
#include "Player.h"
using namespace std;


void printInitialBoard() {
	cout << " 1 | 2 | 3 " << endl;
	cout << "-----------" << endl;
	cout << " 4 | 5 | 6 " << endl;
	cout << "-----------" << endl;
	cout << " 7 | 8 | 9 " << endl;
	cout << endl << endl;
}

//tests for wins for P1
bool isWinForX(string board[3][3]) {
	if (board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X") {
		return true;
		}
	if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") {
		return true;
		}
	if (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X") {
			return true;
			}
	if (board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X") {
			return true;
			}
	if (board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X") {
			return true;
			}
	if (board[0][0] == "X" && board[0][1] == "X" && board[0][2] == "X") {
			return true;
			}
	if (board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X") {
				return true;
			}
	else { return false; }
	}

//tests for wins for P2
bool isWinForO(string board[3][3]) {
	if (board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O") {
		return true;
		}
	if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O") {
		return true;
		}
	if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O") {
		return true;
		}
	if (board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O") {
		return true;
		}
	if (board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O") {
		return true;
		}
	if (board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "O") {
		return true;
		}
	if (board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O") {
			return true;
		}
	else { return false; }
	}

bool choiceCheck(string val) {
	if (val == "1" || val == "2" || val == "3" || val == "4" || val == "5" || val == "6" || val == "7" || val == "8" || val == "9") {
		return true;
	}
	else {
		return false;
	}
}

//sets X tiles for P1
void setX(string val, string board[3][3]) {
	for (int r = 0; r < 3; r++)
	    {
	        for (int c = 0; c < 3; c++)
	        {
	            if (board[r][c] == val)
	            {
	            	board[r][c] = "X";

	            }
	        }
	    }
}

//sets O tile for P2
void setO(string val, string board[3][3]) {
	for (int r = 0; r < 3; r++)
	    {
	        for (int c = 0; c < 3; c++)
	        {
	            if (board[r][c] == val)
	            {
	            	board[r][c] = "O";

	            }
	        }
	    }
}

//searches to see if that tile exists
bool search(string val, string board[3][3]) {
	for (int r = 0; r < 3; r++)
	    {
	        for (int c = 0; c < 3; c++)
	        {
	            if (board[r][c] == val)
	            {
	            	return true;
	            }
	        }
	    }
	return false;
}

//prints the board
void printBoard(string board[3][3]) {
	cout << endl;
	cout << endl;
	cout << board[0][0] << "  |  " << board[0][1] << " |  " << board[0][2] << endl;
	cout << "-------------" << endl;
	cout << board[1][0] << "  |  " << board[1][1] << " |  " << board[1][2] << endl;
	cout << "-------------" << endl;
	cout << board[2][0] << "  |  " << board[2][1] << " |  " << board[2][2] << endl;
	cout << endl;
	cout << endl;
}



int main() {

	Player p1;
	Player p2;
	string name1;
	string name2;
	static string myBoard[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};

	cout << "Welcome to C++ TicTacToe! The following is the board layout: " << endl << endl;
	printInitialBoard();

	cout << "What is player 1's name? : ";
	cin >> name1;
	p1.setName(name1);

	cout << "What is player 2's name? : ";
	cin >> name2;
	p2.setName(name2);
	cout << endl;

	cout << p1.getName() << " will go first." << endl << endl;

	string p1choice;
	string p2choice;

	int count = 0; //will keep track of the number of loops

	//main loop for game
	while (true) {
		cout << p1.getName() << ", please choose a position to place your tile: ";
		cin >> p1choice;
		while (choiceCheck(p1choice) == false ) {
			cout << "Please enter a valid choice: ";
			cin >> p1choice;
		}
		while (search(p1choice, myBoard) == false) {
			cout << "Position already taken. Please choose another value: ";
			cin >> p1choice;
		}
		setX(p1choice, myBoard);
		printBoard(myBoard);
		if (isWinForX(myBoard)) {
			cout << p1.getName() << " WINS!" << endl;
			break;
		}

		//check for a tie
		if (count == 4) {
				cout << "It's a tie!";
				break;
			}

		cout << p2.getName() << ", please choose a position to place your tile: ";
		cin >> p2choice;
		while (choiceCheck(p1choice) == false ) {
			cout << "Please enter a valid choice: ";
			cin >> p1choice;
		}
		while (search(p2choice, myBoard) == false) {
			cout << "Position already taken. Please choose another value: ";
			cin >> p2choice;
		}
		setO(p2choice, myBoard);
		printBoard(myBoard);
		if (isWinForO(myBoard)) {
				cout << p2.getName() << " WINS!" << endl;
				break;
			}
		count ++;
	}


	return 0;
}

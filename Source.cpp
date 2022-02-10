#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	int numStonesRemaining = rand() % 13 + 12; // 12 to 24
	string playerInput;
	int numStonesTaken;
	int numTurn = 0;
	bool isPlayer1Human;
	bool isPlayer2Human;

	cout << "\n*********************"
		<< "\n*** MAGIC NUMBERS ***"
		<< "\n*********************"
		<< "\n\nTheir are " << numStonesRemaining << " stones."
		<< "\nTake 1, 2, or 3."
		<< "\nTo win, don't take the last stone."
		<< "\n\n\n";

	do {
		cout << "Enter 1 for PVP or 2 for PVC: ";
		cin >> playerInput;
	} while (playerInput != "1" && playerInput != "2");

	isPlayer1Human = true;
	isPlayer2Human = playerInput == "1";

	/****** GAME LOOP *****/
	while (true) {
		numTurn++;
		bool isCurrentPlayerHuman = false;
		bool validInput = false;
		while ( ! validInput ){
			if (numTurn % 2 == 0) {
				cout << "\nPlayer 2";
				if (isPlayer2Human) isCurrentPlayerHuman = true;
			}
			else {
				cout << "\nPlayer 1";
				if (isPlayer1Human) isCurrentPlayerHuman = true;
			}
			
			if (isCurrentPlayerHuman) {
				cout << ", there are " << numStonesRemaining << " stones.";
				cout << "\nHow many do you want to take?  ";
				cin >> playerInput;

				if (playerInput == "1" || playerInput == "2" || playerInput == "3") {
					if (playerInput == "1") numStonesTaken = 1;
					else if (playerInput == "2") numStonesTaken = 2;
					else numStonesTaken = 3;

					if (numStonesTaken <= numStonesRemaining) {
						validInput = true;
					}
					else {
						cout << "Invalid input. There are not that many stones.";
					}
				}
				else {
					cout << "\nInvalid input. You must enter 1, 2, or 3.";
				}
			}
			else {
				// Computer's turn
				cout << ", there are " << numStonesRemaining << " stones remaining.";
				cout << "\n\nHow many do you want?";
				// pause
				if (numStonesRemaining == 4) numStonesTaken = 3;
				else if (numStonesRemaining == 3) numStonesTaken = 2;
				else if (numStonesRemaining == 2) numStonesTaken = 1;
				else if (numStonesRemaining == 1) numStonesTaken = 1;
				else numStonesTaken = rand() % 3 + 1;

				cout << "\n\nComputer takes " << numStonesTaken << " stones.";
				validInput = true;
			}
		}

		numStonesRemaining -= numStonesTaken;

		if (numStonesRemaining == 0) {
			if (numTurn % 2 == 0) {
				cout << "\n\nPlayer 1 wins";
			}
			else {
				cout << "\n\nPlayer 2 wins";
			}
			
			break;
		}

		cout << "\n\n\n";
	
	} // end game loop

	cout << "\n\n\n";
	
	return 0;
}

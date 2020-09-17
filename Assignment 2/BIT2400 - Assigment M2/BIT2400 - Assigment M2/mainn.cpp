//Title: Assignment-2
//Author: Favour Diokpo
//
//Objective: Using Enum to display different states or options.

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
using namespace std;


enum States { GAME = 1, CREDIT, END };
void game();
void menu();
void credit();
char randomCard();
void compareCard(char player, char computer, int* comp, int* you);


int main() {
	srand(time(NULL));
	menu();
	return 0;
}

//function for Card Game
void game() {
	char l = 124;
	 char line = 186;
	 char dash = 205;
	 char leftConerTop = 201;
	 char leftConerBottom = 200;
	 char rightConerTop = 187;
	 char rightConerBottom = 188;
	 char heart = 176;
	 char club = 177;
	 char spade = 178;
	 char diamond = 178;
	int m = 1;

	while (m == 1) {

		char computerArray[] = { (char)(rand() % (90 - 65) + 65 + 1) };
		char playerCard = randomCard();
		char computerCard = '\0';
		char option = '\0';

		cout << "\n  Instructions \n----------------" << endl;
		cout << " 1) there are a total of 50 cards" << endl;
		cout << " 2) they range from A to Z " << endl;
		cout << " 3) Z = 90; therefore Z is strongest" << endl;
		cout << " 4) A = 65; therefore A is the weakest" << endl;
		cout << " 5) the dealer will give you and your opponent one card each" << endl;
		cout << " 6) the player with the highest card among the 2 wins\n" << endl;
		cout << "Would you like to select a card (y/n)" << endl;
		cin >> option;


		if ((option == 'y') || (option == 'Y')) {

			int * you = new int();
			int * comp = new int();

			if (option == 'y') {
				playerCard = randomCard();
				computerCard = computerArray[0];

				system("CLS");
				//ask player to reveal card or change card
				cout << leftConerTop << dash << dash << dash << dash << dash << dash << dash << rightConerTop << endl;
				cout << line << diamond << " " << " " << " " << " " << " " << heart << line << endl;
				cout << line << " " << " " << " " << " " << " " << " " << " " << line << endl;
				cout << line << " " << " " << " " << "?" << " " << " " << " " << line << "         Do you want to reveal your card? (y/n)" << endl;
				cout << line << " " << " " << " " << " " << " " << " " << " " << line << endl;
				cout << line << club << " " << " " << " " << " " << " " << spade << line << endl;
				cout << leftConerBottom << dash << dash << dash << dash << dash << dash << dash << rightConerBottom << endl;
				cin >> option;


				if (option == 'y') {
					system("CLS");
					compareCard(playerCard, computerCard, comp, you);
				}
				else {

					cout << "Select another card (y) \n";
					cin >> option;

					while ((option != 'y')) {
						cout << "Error: enter the right letter for a new card (y) \n       or do you want to go back to the main menu (m)\n";
						cin >> option;

						if (option == 'm') {
							system("CLS");
							menu();
						}
					}
					if (option == 'y') {
						playerCard = randomCard();
						compareCard(playerCard, computerCard, comp, you);
					}

				}
				system("pause");
				// required to end the while loop
				option = 'n';

			}
			char yesNo;
			cout << "Would you like to play again (y/n)\n";
			cin >> yesNo;

			if (yesNo == 'y') {
				system("CLS");
				game();
			}
			else {
				system("CLS");
				menu();
			}
		}
		else {
			system("pause");
			menu();
		}
	}
}

void menu() {
	int entry = 0;
	cout << "\nSelect an option from the main menu \n\n";
	cout << " Press 1 to play a Game \n";
	cout << " Press 2 to Credit \n";
	cout << " Press 3 to Quit \n";
	cin >> entry;

	if (entry == GAME) {
		system("CLS");
		game();
		system("pause");
	}
	else if (entry == CREDIT) {
		system("CLS");
		credit();
	}
	else if (entry == END) {
		exit(0);
	}
	else {
		cout << "ERROR: READ MENU CAREFULLY\n\n";
		system("CLS");
		menu();
	}

}

//Credits for the program
void credit() {
	cout << "\n Created by: Favour Diokpo \n";
	cout << "   BIT2400 Assignment M2   \n";
	cout << "     September 25 2017     \n\n";

	char m;
	cout << "Press a Letter to go back to Main Menu\n";
	cin >> m;

	if (m == 'm') {
		system("CLS");
		menu();
	}
	else {
		system("CLS");
		menu();
	}
}

//function when player wants to select a new card
char randomCard() {
	char cardArray[] = { static_cast<char>(rand() % (90 - 65) + 65 + 1) };
	char card = '\0';

	card = cardArray[0];
	return card;
}

//function creates card image using Ascii and Unicode and compares players cards to computers
void compareCard(char player, char computer, int* comp, int* you) {
	char l = 124;
	char line = 186;
	char dash = 205;
	char leftConerTop = 201;
	char leftConerBottom = 200;
	char rightConerTop = 187;
	char rightConerBottom = 188;
	char heart = 176;
	char club = 177;
	char spade = 178;
	char diamond = 178;

	if (player > computer) {
		cout << leftConerTop << dash << dash << dash << dash << dash << dash << dash << rightConerTop << "                " << leftConerTop << dash << dash << dash << dash << dash << dash << dash << rightConerTop << "                " << endl;
		cout << line << diamond << " " << " " << " " << " " << " " << heart << line << "                " << line << diamond << " " << " " << " " << " " << " " << heart << line << endl;
		cout << line << " " << " " << "Y" << "O" << "U" << " " << " " << line << "                " << line << " " << " " << "C" << "O" << "M" << " " << " " << line << endl;
		cout << line << " " << " " << " " << player << " " << " " << " " << line << "        >       " << line << " " << " " << " " << computer << " " << " " << " " << line << endl;
		cout << line << " " << " " << " " << " " << " " << " " << " " << line << "                " << line << " " << " " << " " << " " << " " << " " << " " << line << endl;
		cout << line << club << " " << " " << " " << " " << " " << spade << line << "                " << line << club << " " << " " << " " << " " << " " << spade << line << endl;
		cout << leftConerBottom << dash << dash << dash << dash << dash << dash << dash << rightConerBottom << "                " << leftConerBottom << dash << dash << dash << dash << dash << dash << dash << rightConerBottom << endl;
		cout << "\nYOU" << l << "WIN \nCOMPUTER" << l << "LOST\n" << endl;
		*you = 1;
	}
	else if (player < computer) {
		cout << leftConerTop << dash << dash << dash << dash << dash << dash << dash << rightConerTop << "                " << leftConerTop << dash << dash << dash << dash << dash << dash << dash << rightConerTop << "                " << endl;
		cout << line << diamond << " " << " " << " " << " " << " " << heart << line << "                " << line << diamond << " " << " " << " " << " " << " " << heart << line << endl;
		cout << line << " " << " " << "Y" << "O" << "U" << " " << " " << line << "                " << line << " " << " " << "C" << "O" << "M" << " " << " " << line << endl;
		cout << line << " " << " " << " " << player << " " << " " << " " << line << "        <       " << line << " " << " " << " " << computer << " " << " " << " " << line << endl;
		cout << line << " " << " " << " " << " " << " " << " " << " " << line << "                " << line << " " << " " << " " << " " << " " << " " << " " << line << endl;
		cout << line << club << " " << " " << " " << " " << " " << spade << line << "                " << line << club << " " << " " << " " << " " << " " << spade << line << endl;
		cout << leftConerBottom << dash << dash << dash << dash << dash << dash << dash << rightConerBottom << "                " << leftConerBottom << dash << dash << dash << dash << dash << dash << dash << rightConerBottom << endl;
		cout << "\nCOMPUTER" << l << "WINS \nYOU" << l << "LOST \n" << endl;
		*comp = 1;
	}
	else {
		cout << "TIE\n" << endl;
		cout << "PLAY AGAIN" << endl;
		game();
	}
}

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


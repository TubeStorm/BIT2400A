/*Title: Assignment 4
Author: Favour Diokpo
Objective: To create An Interactive game, using classes, objects, and virtul functions
Algorithm: The program is going to display 5 different boat from the Battleship game.
           user should be allowed to select where they want to place said ships, using N, W , S, E
           THE FIRST PLAYER TO sink all the ship of their opponents wins
           the program should present an AI self played game and a player on ai or player on player game

*/

#include "boat.h"
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;


/*Notes: My code is formatted to look like the example that we where given on CuLearn
* so all the boats arf already hard coded on the grid, all the players have to do is hit the opponents ship.
*/

const int arraySize = 10;
//5 Boats Player 
static Derived * aircraftCarrier = new Derived(5, 1, 'a', 0, 0, false);
static Derived * battleShip = new Derived(4, 1, 'b', 0, 0, false);
static Derived * cruiser = new Derived(3, 1, 'c', 0, 0, false);
static Derived * destroyer = new Derived(2, 2, 'd', 0, 0, false);
static Derived * submarine = new Derived(3, 1, 's', 0, 0, false);


enum States { GAME1 = 1, GAME2, CREDIT, END };
void menu();
void game1();
void ai();
void credit();
int playerEntry(int array[][10], int x, int y, int array2[][10]);
int compEntry(int array[][10], int array2[][10]);
int aiEntry(int array[][10], int array2[][10]);
int aiEntry2(int array2[][10], int array[][10]);


void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 10;
	SetConsoleCursorInfo(hStdout, &cursorInfo);
}

void DrawGrid(int offsetX, int offsetY, int array[arraySize][arraySize], WORD textColour, WORD waterColour)
{

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, textColour);

	for (int i = 0; i < arraySize; i++)
	{
		gotoXY(i + offsetX, offsetY - 1);
		cout << i;
		gotoXY(offsetX - 1, i + offsetY);
		cout << i;
	}

	SetConsoleTextAttribute(ConsoleHandle, waterColour);

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			gotoXY(i + offsetX, j + offsetY);
			cout << (char)array[i][j];
		}
	}


}

int main() {

	srand(time(NULL));

	menu();
	return 0;
}

void menu() {
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, 12);
	cout << ".########.....###....########.########.##.......########..######..##.....##.####.########.\n.##.....##...##.##......##.......##....##.......##.......##....##.##.....##..##..##.....##\n.##.....##..##...##.....##.......##....##.......##.......##.......##.....##..##..##.....##\n.########..##.....##....##.......##....##.......######....######..#########..##..########.\n.##.....##.#########....##.......##....##.......##.............##.##.....##..##..##.......\n.##.....##.##.....##....##.......##....##.......##.......##....##.##.....##..##..##.......\n.########..##.....##....##.......##....########.########..######..##.....##.####.##......." << endl;


	SetConsoleTextAttribute(ConsoleHandle, 7);

	int entry = 0;
	cout << "\nSelect an option from the main menu \n\n";
	cout << " Press 1 for New Game \n";
	cout << " Press 2 for an AI Game  \n";
	cout << " Press 3 to Roll Credits \n";
	cout << " Press 4 to Quit Game \n";
	cin >> entry;

	switch (entry) {
	case GAME1:  system("CLS"); game1(); system("pause");
		break;
	case GAME2:  system("CLS"); ai(); system("pause");
		break;
	case CREDIT:  system("CLS"); credit(); system("pause");
		break;
	case END:  exit(0);
		break;
	default: cout << "ERROR: READ MENU CAREFULLY\n\n";
		system("CLS");
		menu();
		break;
	}
}

void game1() {
	//prints out you vs comp
	cout << ".##....##..#######..##.....##....##.....##..######......######...#######..##.....##.########.\n..##..##..##.....##.##.....##....##.....##.##....##....##....##.##.....##.###...###.##.....##\n...####...##.....##.##.....##....##.....##.##..........##.......##.....##.####.####.##.....##\n....##....##.....##.##.....##....##.....##..######.....##.......##.....##.##.###.##.########.\n....##....##.....##.##.....##.....##...##........##....##.......##.....##.##.....##.##.......\n....##....##.....##.##.....##......##.##...##....##....##....##.##.....##.##.....##.##.......\n....##.....#######...#######........###.....######......######...#######..##.....##.##.......\n" << endl;
	system("CLS");

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int initialOffset = 10;


	int myArray[arraySize][arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			myArray[i][j] = 219;
		}
	}

	//aircraftCarrier
	myArray[4][2] = 97;
	myArray[4][3] = 97;
	myArray[4][4] = 97;
	myArray[4][5] = 97;
	myArray[4][6] = 97;

	//submarine
	myArray[0][2] = 115;
	myArray[0][3] = 115;
	myArray[0][4] = 115;

	//cruiser
	myArray[6][7] = 99;
	myArray[6][8] = 99;
	myArray[6][9] = 99;


	//destroyer
	myArray[4][0] = 100;
	myArray[5][0] = 100;
	myArray[7][0] = 100;
	myArray[8][0] = 100;

	//battle shipmyArray
	myArray[3][7] = 98;
	myArray[3][8] = 98;
	myArray[3][9] = 98;
	myArray[3][10] = 98;



	int myArray2[arraySize][arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			myArray2[i][j] = 219;
		}
	}

	//aircraftCarrier
	myArray2[2][4] = 97;
	myArray2[3][4] = 97;
	myArray2[4][4] = 97;
	myArray2[5][4] = 97;
	myArray2[6][4] = 97;

	//submarine
	myArray2[2][0] = 115;
	myArray2[3][0] = 115;
	myArray2[4][0] = 115;

	//cruiser
	myArray2[7][6] = 99;
	myArray2[8][6] = 99;
	myArray2[9][6] = 99;


	//destroyer
	myArray2[0][4] = 100;
	myArray2[0][5] = 100;
	myArray2[0][6] = 100;
	myArray2[0][7] = 100;

	//battle ship
	myArray2[7][3] = 98;
	myArray2[8][3] = 98;
	myArray2[9][3] = 98;
	myArray2[10][3] = 98;


	DrawGrid(10, 2, myArray, FOREGROUND_GREEN, 7);
	DrawGrid(25, 2, myArray2, 7, FOREGROUND_GREEN);
	cout << endl;
	cout << "              P1           " << " P2" << endl;
	cout << endl;


	SetConsoleTextAttribute(ConsoleHandle, 7);
	int x = 0;
	int y = 0;
	int player = 0;
	int comp = 0;

	cout << "X = SUNK SHIP \n" << char(176) << "= MISS\n";
	//loop for taking players entry and deciding on if ship was sunk or a miss
	for (int i = 0; i < 19; i++) {
		cout << "Enter x: " << endl; cin >> x;
		cout << "Enter y: " << endl; cin >> y;
		player = playerEntry(myArray, x, y, myArray2);
		comp = compEntry(myArray, myArray2);

	}
	if (player > comp) {
		if (player == 19) {
			cout << "YOU ARE THE WINNER " << endl;
		}
	}
	else if (comp > player){
		if (comp == 19) {
			cout << "THE COMPUTER WON " << endl;
		}
	}


	cout << " Thank you for playing this DEMO " << endl;
	cout << " would you like to go back to main menu y/n " << endl;
	char ent = '0';
	cin >> ent;

	if (ent == 'y') {
		menu();
		system("CLS");
	}
	else if (ent == 'n') {
		cout << "SO WHAT EXACTLY ARE YOU DOING, JUST GO BACK TO MENU " << endl;
		menu();
		system("CLS");
	}


}

void ai() {
	//prints out p1 vs p2
	cout << ".########.....##......##.....##..######.....########...#######.\n.##.....##..####......##.....##.##....##....##.....##.##.....##\n.##.....##....##......##.....##.##..........##.....##........##\n.########.....##......##.....##..######.....########...#######.\n.##...........##.......##...##........##....##........##.......\n.##...........##........##.##...##....##....##........##.......\n.##.........######.......###.....######.....##........#########\n" << endl;
	system("CLS");

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int initialOffset = 10;


	int myArray2[arraySize][arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			myArray2[i][j] = 219;
		}
	}

	//aircraftCarrier
	myArray2[4][2] = 97;
	myArray2[4][3] = 97;
	myArray2[4][4] = 97;
	myArray2[4][5] = 97;
	myArray2[4][6] = 97;

	//submarine
	myArray2[0][2] = 115;
	myArray2[0][3] = 115;
	myArray2[0][4] = 115;
		   
	//cruis2er
	myArray2[6][7] = 99;
	myArray2[6][8] = 99;
	myArray2[6][9] = 99;
		   

	//destroyer
	myArray2[4][0] = 100;
	myArray2[5][0] = 100;
	myArray2[7][0] = 100;
	myArray2[8][0] = 100;

	//battle shipmyArray
	myArray2[3][7] = 98;
	myArray2[3][8] = 98;
	myArray2[3][9] = 98;
	myArray2[3][10] = 98;



	int myArray[arraySize][arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			myArray[i][j] = 219;
		}
	}

	//aircraftCarrier
	myArray[2][4] = 97;
	myArray[3][4] = 97;
	myArray[4][4] = 97;
	myArray[5][4] = 97;
	myArray[6][4] = 97;

	//submarine
	myArray[2][0] = 115;
	myArray[3][0] = 115;
	myArray[4][0] = 115;

	//cruiser
	myArray[7][6] = 99;
	myArray[8][6] = 99;
	myArray[9][6] = 99;


	//destroyer
	myArray[0][4] = 100;
	myArray[0][5] = 100;
	myArray[0][6] = 100;
	myArray[0][7] = 100;

	//battle ship
	myArray[7][3] = 98;
	myArray[8][3] = 98;
	myArray[9][3] = 98;
	myArray[10][3] = 98;


	DrawGrid(10, 2, myArray, FOREGROUND_RED, 7);
	DrawGrid(25, 2, myArray2, 7, FOREGROUND_RED);
	cout << endl;
	cout << "              ai1           " << " ai2" << endl;
	cout << endl;


	SetConsoleTextAttribute(ConsoleHandle, 7);

	int comp = 0;
	int comp2 = 0;

	//loop for taking both Ai's entry and deciding on if ship was sunk or a miss
	int i = 0;
	do{
		comp += aiEntry(myArray, myArray2);
		comp2 += aiEntry2(myArray2, myArray);
		i++;
	} while (i < 18);

	if (comp > comp2) {
			cout << "ai1 IS THE WINNER " << endl;
	}
	else if (comp2 > comp) {
			cout << "ai2 IS THE WINNER " << endl;
	}

	cout << "Thank you for playing this DEMO " << endl;
	cout << "Would you like to go back to main menu y/n " << endl;
	char ent = '0';
	cin >> ent;

	if (ent == 'y') {
		menu();
		system("CLS");
	}
	else if (ent == 'n') {
		cout << "SO WHAT EXACTLY ARE YOU DOING, JUST GO BACK TO MENU " << endl;
		menu();
		system("CLS");
	}
}

//Credits for the program
void credit() {
	cout << "\n Created by: Favour Diokpo \n";
	cout << "   BIT2400 Assignment M4   \n";
	cout << "     October 29 2017     \n\n";
	cout << "      DEMO VERSION     \n\n";
	cout << "    DO NOT STAY TUNED      \n\n";
	cout << "  FOR THE FINAL VERSION     \n\n";

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

int playerEntry(int array[][10], int x, int y, int array2[][10]) {
	int playerWin = 0;
	
HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, 7);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((array2[x][y] == char(97)) || (array2[x][y] == char(99)) || (array2[x][y] == char(98)) || (array2[x][y] == char(100)) || (array2[x][y] == char(115))) {
				cout << "You ";
				aircraftCarrier->getBoat();
				cout << " Their: " << x << ":" << y << endl;
				playerWin += 1;
				array2[x][y] = 88;
				system("pause");
			}
			if (array2[x][y] == 219) {
				array2[x][y] = 176;
			}
			
		}
	}

	

	system("CLS");
	DrawGrid(10, 2, array, FOREGROUND_GREEN, 7);
	DrawGrid(25, 2, array2, 7, FOREGROUND_GREEN);
	cout << endl;
	cout << "              P1           " << " P2" << endl;
	cout << endl;

	
	return playerWin;
}

int compEntry(int array[][10], int array2[][10]) {
	int compX = rand() % 10;
	int compY = rand() % 10;
	int compWin = 0;

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, 7);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((array[compX][compY] == char(97)) || (array[compX][compY] == char(98)) || (array[compX][compY] == char(99)) || (array[compX][compY] == char(100)) || (array[compX][compY] == char(115))) {
				cout << "They Sunk Your: " << compX << ":" << compX << endl;
				compWin += 1;
				array[compX][compY] = 88;
				system("pause");
			}
			if (array[compX][compY] = 219) {
				array[compX][compY] = 176;
			}
		}
	}

	system("CLS");
	DrawGrid(10, 2, array, FOREGROUND_GREEN, 7);
	DrawGrid(25, 2, array2, 7, FOREGROUND_GREEN);
	cout << endl;
	cout << "              P1           " << " P2" << endl;
	cout << endl;

	return compWin;
}


int aiEntry(int array[][10], int array2[][10]) {
	int compX = rand() % 10;
	int compY = rand() % 10;
	int compWin = 0;
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, 7);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((array[compX][compY] == char(97)) || (array[compX][compY] == char(98)) || (array[compX][compY] == char(99)) || (array[compX][compY] == char(100)) || (array[compX][compY] == char(115))) {
				cout << "Ai 1 Sunk Ai 2's: " << compX << ":" << compX << endl;
				compWin += 1;
				array[compX][compY] = 88;
				system("pause");
			}
			if (array[compX][compY] = 219) {
				array[compX][compY] = 176;
			}
		}
	}

	DrawGrid(10, 2, array, FOREGROUND_RED, 7);
	DrawGrid(25, 2, array2, 7, FOREGROUND_RED);
	cout << endl;
	cout << "              ai1           " << " ai2" << endl;
	cout << endl;
	SetConsoleTextAttribute(ConsoleHandle, 7);

	return compWin;
}

int aiEntry2( int array2[][10], int array[][10]) {
	int compX = rand() % 10;
	int compY = rand() % 10;
	int compWin = 0;

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((array2[compX][compY] == char(97)) || (array2[compX][compY] == char(98)) || (array2[compX][compY] == char(99)) || (array2[compX][compY] == char(100)) || (array2[compX][compY] == char(115))) {
				cout << "Ai 2 Sunk Ai 1's: " << compX << ":" << compX << endl;
				compWin += 1;
				array2[compX][compY] = 88;
				system("pause");
			}

			if (array[compX][compY] = 219) {
				array2[compX][compY] = 176;
			}

		}
	}

	DrawGrid(10, 2, array, FOREGROUND_RED, 7);
	DrawGrid(25, 2, array2, 7, FOREGROUND_RED);
	cout << endl;
	cout << "              ai1           " << " ai2" << endl;
	cout << endl;

	SetConsoleTextAttribute(ConsoleHandle, 7);
	return compWin;
}


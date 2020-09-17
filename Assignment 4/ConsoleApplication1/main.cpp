#include "Boat.h"
#include <Windows.h>
//watch the cherno projects videos on youtube

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

const int arraySize = 10;

void DrawGrid(int offsetX, int offsetY, int array[arraySize][arraySize], WORD textColour, WORD waterColour) 
{

	

	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, textColour);

	for (int i = 0; i < arraySize; i++) 
	{
		gotoXY(i + offsetX, offsetY - 1 );
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
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int initialOffset = 10;


	 int myArray[arraySize][arraySize];

	for (int i = 0; i < arraySize; i++) 
	{
		for (int j = 0; j < arraySize; j++) 
		{
			myArray[i][j] = 248;
		}
	}

	DrawGrid(10, 2, myArray, FOREGROUND_GREEN, FOREGROUND_RED);
	DrawGrid(10, 14, myArray, FOREGROUND_RED, FOREGROUND_GREEN);

	DrawGrid(25, 2, myArray, FOREGROUND_BLUE, FOREGROUND_RED);
	//DrawGrid(25, 14, myArray, FOREGROUND_RED, FOREGROUND_BLUE);

	for (int i = 0; i < 255; i++) 
	{
		DrawGrid(25, 14, myArray, i, i);
		Sleep(100);
	}

	system("pause");
	return 0;
}

void player() {
	int playerNum, playerX, playerY;
	bool playerWin;
	char playerSymbol;

	Derived * one = new Derived( playerNum , playerSymbol , playerX , playerY, playerWin);
	Derived * two = new Derived(playerNum, playerSymbol, playerX, playerY, playerWin);
	Derived * three = new Derived(playerNum, playerSymbol, playerX, playerY, playerWin);
	Derived * four = new Derived(playerNum, playerSymbol, playerX, playerY, playerWin);
	Derived * five = new Derived(playerNum, playerSymbol, playerX, playerY, playerWin);

}

void enemy() {
	int enemyNum, enemyX, enemyY;
	bool enemyWin;
	char enemySymbol;
//fix the line below
	Derived * one = new Derived(enemyNum, enemySymbol, enemyX, enemyY, enemyWin);
	one->GetPlayer = 1;

	Derived * two = new Derived(enemyNum, enemySymbol, enemyX, enemyY, enemyWin);
	Derived * three = new Derived(enemyNum, enemySymbol, enemyX, enemyY, enemyWin);
	Derived * four = new Derived(enemyNum, enemySymbol, enemyX, enemyY, enemyWin);
	Derived * five = new Derived(enemyNum, enemySymbol, enemyX, enemyY, enemyWin);

}
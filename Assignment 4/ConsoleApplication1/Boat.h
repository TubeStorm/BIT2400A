#include <iostream>
using namespace std;

class Boat {
public:
	virtual void getBoat() = 0;
};

class Derived : public Boat {
private:
	int player;
	char boatSymbol;
	int x;
	int y;
	bool win;

public:
	Derived (int player, char boatSymbol, int x, int y, bool win) : player(player), boatSymbol(boatSymbol) , x(x), y(y), win(win) {}
	void getBoat() {}

	int GetPlayer(int player);
	char GetBoatSymbol(char boatSymbol);
	int GetX(int x);
	int GetY(int y);
	bool GetWin(bool win);

};

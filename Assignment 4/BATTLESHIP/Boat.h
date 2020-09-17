#include <iostream>
using namespace std;

class Boat {
public:
	virtual void getBoat() = 0 {
		cout << "not sunk" << endl;
	}
};

class Derived : public Boat {
private:
	int size;
	int number;
	char boatName;
	int x;
	int y;
	bool sunk;

public:
	Derived(int size, int number, char boatName, int x, int y, bool sunk) : size(size), number(number), boatName(boatName), x(x), y(y), sunk(sunk) {}
	void getBoat() {
		cout << "sunk";
	}

	int GetSize();
	int GetNumber();
	char GetBoatName();
	int GetX();
	void SetX(int x);
	int GetY();
	void SetY(int y);
	bool GetSunk();
	void SetSunk(bool sunk);

};


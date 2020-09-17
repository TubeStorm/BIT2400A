#include <iostream>
using namespace std;
//
class Boat {
private:
    int size;
    int number;
    char boatName;
    int x;
    int y;
    bool sink;
    
public:
    
    Boat (int size, int number, char boatName, int x, int y, bool sink) {
        size = size;
        number = number;
        boatName = boatName;
        x = 0;
        y = 0;
        sink = false;
    }
    
    int GetSize(int size);
    int GetNumber(int number);
    char GetBoatName(char boatName);
    int GetX(int x);
    int GetY(int y);
    bool GetSink(bool sink);
};

//AircraftCarrier
class AircraftCarrier : public Boat {
private:
    int size;
    int number;
    char boatName;
    int x;
    int y;
    bool sink;
    
public:
    AircraftCarrier (int size, int number, char boatName) : size(5), number(1), boatName('a') {}
    
   // void getBoat() {}
};

//BattleShip
class BattleShip : public Boat {
private:
    int size;
    int number;
    char boatName;
    int x;
    int y;
    bool sink;
    
public:
    BattleShip (int size, int number, char boatName, int x, int y, bool sink) : size(4), number(1), boatName('b') , x(x), y(y), sink(sink) {}
};

//Cruiser
class Cruiser : public Boat {
private:
    int size;
    int number;
    char boatName;
    int x;
    int y;
    bool sink;
    
public:
    Cruiser (int size, int number, char boatName, int x, int y, bool sink) : size(3), number(1), boatName('c') , x(x), y(y), sink(sink) {}
    
   // void getBoat() {}
};

//Destroyer
class Destroyer : public Boat {
private:
    int size;
    int number;
    char boatName;
    int x;
    int y;
    bool sink;
    
public:
    Destroyer (int size, int number, char boatName, int x, int y, bool sink) : size(2), number(2), boatName('d') , x(x), y(y), sink(sink) {}

};

//Submarine
class Submarine : public Boat {
private:
    int size;
    int number;
    char boatName;
    int x;
    int y;
    bool sink;
    
public:
    Submarine (int size, int number, char boatName, int x, int y, bool sink) : size(3), number(1), boatName('s') , x(x), y(y), sink(sink) {}
 
};





#include "boat.h"
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

//5 Boats Player 1
static Derived * aircraftCarrier = new Derived (5, 1, 'a', 0, 0, false);
static Derived * battleShip = new Derived (4, 1, 'b', 0, 0, false);
static Derived * cruiser = new Derived (3, 1, 'c', 0, 0, false);
static Derived * destroyer = new Derived (2, 2, 'd', 0, 0, false);
static Derived * submarine = new Derived (3, 1, 's', 0, 0, false);

//5 boats Player 2 or Comp
static Derived * aircraftCarrier2 = new Derived (5, 1, 'a', 0, 0, false);
static Derived * battleShip2 = new Derived (4, 1, 'b', 0, 0, false);
static Derived * cruiser2 = new Derived (3, 1, 'c', 0, 0, false);
static Derived * destroyer2 = new Derived (2, 2, 'd', 0, 0, false);
static Derived * submarine2 = new Derived (3, 1, 's', 0, 0, false);

enum States { GAME1=1, GAME2, CREDIT, END };
void menu();
void game1();
void game2();
void printShipVertical();
void printShipHorizontal();
void credit();

int main() {
    /*
     cout<<battleShip->GetNumber()<<endl;
     cout<<aircraftCarrier->GetNumber()<<endl;
     cout<<cruiser->GetNumber()<<endl;
     
     cout<<battleShip->GetSize()<<endl;
     cout<<aircraftCarrier->GetSize()<<endl;
     cout<<cruiser->GetSize()<<endl;
     */
    
    
    srand (time(NULL));
    menu();
    return 0;
}

void menu(){
    cout<< ".########.....###....########.########.##.......########....########.####.########.##.......########.\n.##.....##...##.##......##.......##....##.......##..........##........##..##.......##.......##.....##\n.##.....##..##...##.....##.......##....##.......##..........##........##..##.......##.......##.....##\n.########..##.....##....##.......##....##.......######......######....##..######...##.......##.....##\n.##.....##.#########....##.......##....##.......##..........##........##..##.......##.......##.....##\n.##.....##.##.....##....##.......##....##.......##..........##........##..##.......##.......##.....##\n.########..##.....##....##.......##....########.########....##.......####.########.########.########. "<<endl;
    
    int entry = 0;
    cout << "\nSelect an option from the main menu \n\n";
    cout << " Press 1 to play a Battlefield against computer \n";
    cout << " Press 2 to play a Battlefield against Player 2 \n";
    cout << " Press 3 to roll credit \n";
    cout << " Press 4 to end game \n";
    cin >> entry;
    
    switch (entry) {
        case GAME1:  system("CLS"); game1(); system("pause");
            break;
        case GAME2:  system("CLS"); game2(); system("pause");
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

void game1(){
    //prints out you vs comp
    cout<<".##....##..#######..##.....##....##.....##..######......######...#######..##.....##.########.\n..##..##..##.....##.##.....##....##.....##.##....##....##....##.##.....##.###...###.##.....##\n...####...##.....##.##.....##....##.....##.##..........##.......##.....##.####.####.##.....##\n....##....##.....##.##.....##....##.....##..######.....##.......##.....##.##.###.##.########.\n....##....##.....##.##.....##.....##...##........##....##.......##.....##.##.....##.##.......\n....##....##.....##.##.....##......##.##...##....##....##....##.##.....##.##.....##.##.......\n....##.....#######...#######........###.....######......######...#######..##.....##.##.......\n" <<endl;
    cout<< "You have:\n 1 Air Carrier: size of 5\n 1 Battle Ship: size of 4\n 1 Cruiser: size of 3\n 2 Destroyers: size of 2\n 1 Submarine: size of 3\n " <<endl;
    //print out the board later
    
}

void game2(){
    //prints out p1 vs p2
    char position;
    cout<<".########.....##......##.....##..######.....########...#######.\n.##.....##..####......##.....##.##....##....##.....##.##.....##\n.##.....##....##......##.....##.##..........##.....##........##\n.########.....##......##.....##..######.....########...#######.\n.##...........##.......##...##........##....##........##.......\n.##...........##........##.##...##....##....##........##.......\n.##.........######.......###.....######.....##........#########\n" <<endl;
    cout<< "You both have:\n 1 Air Carrier: size of 5\n 1 Battle Ship: size of 4\n 1 Cruiser: size of 3\n 2 Destroyers: size of 2\n 1 Submarine: size of 3\n " <<endl;
    
    cout<<"\nYou can place your ships either vertically or horizontally"<<endl;
    cout<<"How yould you like to place all your ships? v or h "<<endl;
    cin>>position;
    
    if (position == 'v'){
        printShipVertical();
    }
    else{
        printShipHorizontal();
    }
}

//Credits for the program
void credit() {
    cout << "\n Created by: Favour Diokpo \n";
    cout << "   BIT2400 Assignment M4   \n";
    cout << "     October 29 2017     \n\n";
    
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

void printShipVertical(){
    //print ships on board
    int x, y;
    for (int i = 0; i < ((aircraftCarrier->GetSize())*(aircraftCarrier->GetNumber())); i++) {
        cout<<"where would you like to place your aircraftCarrier " << i+1 << " e.g. 68, x=6, y=8" <<endl;
        cin >> x; aircraftCarrier->SetX(x);
        cin >> y; aircraftCarrier->SetX(y);
    }
    for (int i = 0; i < ((battleShip->GetSize())*(battleShip->GetNumber())); i++) {
        cout<<"where would you like to place your battleShip " << i+1 << " e.g. 68, x=6, y=8" <<endl;
    }
    for (int i = 0; i < ((cruiser->GetSize())*(cruiser->GetNumber())); i++) {
        cout<<"where would you like to place your cruiser " << i+1 << " e.g. 68, x=6, y=8" <<endl;
    }
    for (int i = 0; i < ((destroyer->GetSize())*(destroyer->GetNumber())); i++) {
        cout<<"where would you like to place your destroyer " << i+1 << " e.g. 68, x=6, y=8" <<endl;
    }
    for (int i = 0; i < ((submarine->GetSize())*(submarine->GetNumber())); i++) {
        cout<<"where would you like to place your submarine " << i+1 << " e.g. 68, x=6, y=8" <<endl;
    }
}
void printShipHorizontal(){
    
}


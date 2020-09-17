#include <iostream>
#
using namespace std;



class Car
{
public:
    int wheelCount;
    string colour;
    float kilometers;
};

int main(){
    
Random:
#include <cstdlib>
#include <time.h>
    srand (time(NULL));
    v0 = rand()  //random num
    v1 = rand() % 100;           //  0 to 99
    v2 = rand() % 100 + 1;     // 1 to 100
    v3 = rand() % 30 + 1985; // 1985-2014
    
Arrays:
    int myArray[2];
    myArray[0] = 1;
    myArray[1] = 2;
    int myArray[2] = {1,2};
    
    2D Arrays:
    int my2DArray[3][3] = {{1,2,3},{1,2,3},{1,2,3}};
    
    Character Arrays:
    char a[] = “aaa ”
    char a[5] = "asdf”; //space for the \0
    char d[]{'a', 'b', '\0', 'c'};
    
    \0=null character
    \n=new line
    \t=tab
    \b=backspace
    \\=backslash
    \"=quote
    
Pointers:
    int a = 5;
    a = 5
    &a = memory address
    
    int a = 145;
    int * p = &a;
    cout << p[2]  or (*p)  // 145;
    
    Create And Delete Pointer:
    int* i = new int();
    *i = 5;
    delete i;
    i = NULL;
    if(i == 0) cout<<"i is 0"<<endl;
    i = nullptr;
    if(i == 0) cout<<"i is 0"<<endl;
    
    Dynamic Array:
    int size;
    cin >> size;
    int * lol = new int[size];
    delete [] lol;
    
    Passing Pointer as Parameter to Function:
    void printNum(int * value)
    {
        * value = 10;
        cout << *value << endl;
    }
    
    int * number= new int;
    cin>>number;
    printNum(number);
    
    
    Vectors and Double ended queue:
#include <vector>
#include <deque>
    
    int a = 2;
    vector<int> v = {7, 5, 16, 8}; {… , 2 ,13};
    v.push_back(a);
    v.push_back(13);
    cout<<v[2];         //16
    
    deque<int> d = {7, 5, 16, 8};  {13, … , 25};
    d.push_front(13);
    d.push_back(25);
    cout<<v[2];         //5
    
    Output all Ascii Characters:
#include <string>
    for (int i = 33; i < 255; i++)
    {
        cout << i << ": " << (char)i << endl;
    }
    
    Goto X Y:
#include <windows.h>
    void gotoXY(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    
Enum:
    0,       1,         2,        3
    enum Animals { Dog, Cat, Horse, Cow };
    1,        2,      3,       4
    enum class Animals { Dog=1, Cat, Horse, Cow };
    
    
Struct:
    struct Car
    {
        int wheelCount;
        float kilometers;
    };
    
    Car myCar{ 4,"Green",30500.7f };
    Car myTruck = { 4,"Blue",20500.7f };
    
Class:
    // .h file // .cpp file // main.cpp file
    class Car
    {
    private:
        int wheel;
        float kilo;
    public:
        int GetWheel();
        void SetWheel(int wheel);
        int GetKilo();
        void SetKilo(int kilo);
    };
    
Constructors:
    class Animal
    {
        int m_height;
        Animal();
        Animal(int height)
        {
            m_height = height;
        }
    }
 
    Car * myCarPtr = new Car;
    cout << myCarPtr->wheelCount << endl; //garbage data
    
    Car * myCarPtr = new Car();
    cout << myCarPtr->wheelCount << endl;// default constructor sets to zero
    
    myCar->wheelCount = 5; //Member access operator
    (*myCar).wheelCount = 5;//what its doing

    

    return 0;
}

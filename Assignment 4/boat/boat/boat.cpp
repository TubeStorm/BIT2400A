#include "boat.h"

int Derived::GetSize() {
    return size;
}
int Derived::GetNumber() {
    return number;
}
char Derived::GetBoatName() {
    return boatName;
}
int Derived::GetX() {
    return x;
}
void Derived::SetX(int X) {
    x = X;
}
int Derived::GetY() {
    return y;
}
void Derived::SetY(int Y) {
    y = Y;
}
bool Derived::GetSunk() {
    return sunk;
}
void Derived::SetSunk(bool sunk) {
    sunk = sunk;
}



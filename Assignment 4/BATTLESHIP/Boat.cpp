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
void Derived::SetX(int x1)
{
	x = x1;
}
int Derived::GetY() {
	return y;
}
void Derived::SetY(int y1) {
	y = y1;
}
bool Derived::GetSunk() {
	return sunk;
}
void Derived::SetSunk(bool sunk) {
	sunk = sunk;
}



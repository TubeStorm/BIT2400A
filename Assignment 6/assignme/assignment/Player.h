/*
 class Bombs
 {
 
 private:
 int bombSymbol;
 int size;
 
 public:
 int Bombs::getBombSymbol() {
 return bombSymbol;
 }
 void Bombs::setBombSymbol(int randValue) {
 
 switch (randValue)
 {
 case 1: bombSymbol = 64; break;
 case 2: bombSymbol = 128; break;
 case 3: bombSymbol = 143; break;
 case 4: bombSymbol = 153; break; 
 case 5: bombSymbol = 233; break;
 case 6: bombSymbol = 234; break;
 case 7: bombSymbol = 219; break;
 case 8: bombSymbol = 220; break;
 case 9: bombSymbol = 232; break;
 case 10: bombSymbol = 254; break;
 default:
 bombSymbol = char(64); break;
 break;
 }
 }
 void Bombs::setBombSize(int sizeB) {
 size = sizeB;
 }
 int Bombs::getBombSize() {
 return size;
 }
 
 };
 */

class Player
{
private:
    int playerNumber;
    int playerLife = 100;
    
public:
    int getPlayerLife() {
        return playerLife;
    }
    void setPlayerNumber(int num) {
        playerNumber = num;
    }
    int getPlayerNumber() {
        return playerNumber;
    }
};

//Title: Assignment-1
//Author: Favour Diokpo
//
//Objective: The programs objective is to learn how to use pointer and arrays
//           by displaying player options for a user.
//
//Algorithm: The program is going to display different options for a user
//           player size and player scores are collect from the user
//           a dynamic array is used to display the player scores
//           the program can be terminated, when the user choose to.
//           [everything was done in the main function]




#include <iostream>
using namespace std;


int main() {
    
    int players = 0;
    cout << "Enter number of players " << endl;
    cin >> players;
    int *array = new int[players]();
    int newPlayer = players + players;
    int *newArray = new int[newPlayer]();
    int insertpositon = 0;
    
    for (int i = 0; i < newPlayer; i++){
        int option = 0;
        cout << "select an option" << endl;
        cout <<"1. Enter a new player score\n2. See the full list of the entered scores\n3. Show the value of the highest score\n4. End the program\n" << endl;
        cin >> option;
        
        //enter new scores
        if (option == 1){
            int newScore = 0;
            
            for(int l = 0; l < players; l++){
                cout << "enter a new player score at position " << insertpositon << endl;
                insertpositon += 1;
                cin >> newScore;
                array[l] = newScore;
            }
            
            if (insertpositon == players){
                for (int m = 0; m < newPlayer; m++){
                    newArray[m] = array[m];
                    if (newArray[m] == 0){
                        newArray[m] = 0;
                    }
                }
                delete[] array;
            }
        }
        
        //display all scores
        else if (option == 2){
            cout << "You want to see the full list of the entered scores" << endl;
            for (int j = 0; j < players; j++){
                cout << newArray[j] << " ";
            }
            cout << "\n" <<endl;
        }
        
        //display highest score
        else if (option == 3){
            cout << "You want to show the value of the highest score" << endl;
            int highest = 0;
            for (int k = 0; k < players; k++){
                {
                    if (newArray[k] > highest){
                        highest = newArray[k];
                    }
                }
            }
            cout << "The highest Value is: " << highest << "\n" << endl;
        }
        
        //end program
        else if (option ==4){
            cout << "Program Has Ended\n";
            newPlayer = 0;
        }
    }
    return 0;
}

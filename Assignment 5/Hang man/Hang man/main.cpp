//NOTE: PLEASE CAN YOU RUN MY CODE WITH XCODE
//      BECAUSE WHEN I TRANSFERRED MY CODE TO THE SCHOOL COMPUTERS I WAS GETTING SO MANY ERRORS
//      DESPITE IT WORKING PERFECTLY WELL ON MY LAPTOP
//      I HAVE ATTATCHED ALL THE ERRORS I GOT FROM THE SCHOOL COMPUTERS IN THE DOCUMENT, FOR PROOF (VISUAL STUIDO SUCKS)
//Title: Assignment-5
//Author: Favour Diokpo
//
//Objective: create a hangman game that saves the players highest score to a txt file
//           and also collects date from a dictionary file


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;

enum States { GAME = 1, CREDIT, END };
void menu();
void game();
void credit();
void hangMan(int entryFail);
int charCount(string word);
void thanks();


int main() {
    srand(time(NULL));
    menu();
    return 0;
}

void game() {
    //this calls the dictionary file and also creates new file called highest_scorefile.
    fstream dictionary;
    ofstream highest_scorefile;
    string failedword, tempword, wordformat, word;
    
    highest_scorefile.open("Highest Score.txt", ios::ate);
    dictionary.open("Dictionary.txt");
    
    
    //if statement for if the file was opened
    if (!dictionary && !highest_scorefile) {
        cout << "Unable to open file..." << endl;
    }
    
    
    else {
        int fail = 0, highestScore = 0;
        cout << "The file works, continue..." << endl;
        //outputting data into .TXT file
        highest_scorefile << "Highest Score for last Game:" << setw(6) << setfill(' ') << 1<< endl;
        while (dictionary) {
            //rules
            cout << "INSTRUCTIONS\nYou have a max of 7 wrong guesses.\nThe game keeps randomly selecting words until you get hung\nAll data is stored in a Highest Score.txt file\n" << endl;
            
            do {
                int charTotal = 0, win = 0;
                char entry, oldEntry = ' ';
                
                cout << "YOUR SCORE CURRENTLY IS " << highestScore << endl;
                //collecting a random word from the dictionary file
                for (int i = 0; i < rand() % 2000 + 1; i++) {
                    dictionary >> wordformat;
                    word = wordformat;
                }
                
            
                charTotal = charCount(word);
                
                //printing out spaces for game
                cout << "\n\nThe word has ";
                for (int i = 0; i < word.size(); i++) {
                    cout << "_";
                    tempword[i] = '_';
                }
                cout << " dashes.\n" << endl;
                
                int l = 1;
                while (win != charTotal) {
                    
                    cout << "\nWhat is your #" << l++ << " guess" << endl;
                    cin >> entry;
                    system("CLS");
                    while (oldEntry != entry) {
                        oldEntry = entry;
                        size_t index = word.find(entry, 0);
                        if (true) {
                            if (index != string::npos) {
                                for (int j = 0; j < word.size(); j++) {
                                    if (word[j] == entry) {
                                        tempword[j] = entry;
                                        win++;
                                    }
                                    cout << tempword[j];
                                }
                            }
                            else if (index == string::npos) {
                                if (fail <= 7) {
                                    fail += 1;
                                    hangMan(fail);
                                    for (int j = 0; j < word.size(); j++) {
                                        cout << tempword[j];
                                    }
                                }
                            }
                        }
                    }
                }
                highestScore++;
             
            } while (fail != 7);
            
        }
        if (fail == 7) {
            failedword = word;
        }
        //outputting data into .TXT file
        highest_scorefile << "Highest Score for last Game:" << setw(6) << setfill(' ') << highestScore<< endl;
        highest_scorefile << "The word you missed was: " << failedword << endl;
        highest_scorefile.close();
        dictionary.close();
        
    }
    
    
    
    void thanks();
    
    
}

void menu() {
    //menu
    cout << " _ _ _ _ _ _ _ \n / \\ / \\ / \\ / \\ / \\ / \\ / \\\n ( H | A | N | G | M | A | N )\n \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ " << endl;
    
    int entry = 0;
    cout << "\nSelect an option from the main menu \n\n";
    cout << " Press 1 to play a Game \n";
    cout << " Press 2 to Credit \n";
    cout << " Press 3 to Quit \n";
    cin >> entry;
    
    if (entry == GAME) {
        system("CLS");
        game();
    }
    else if (entry == CREDIT) {
        system("CLS");
        credit();
    }
    else if (entry == END) {
        exit(0);
    }
    else {
        cout << "ERROR: READ MENU CAREFULLY\n\n";
        system("CLS");
        menu();
    }
}

void credit() {
    cout << "\n Created by: Favour Diokpo \n";
    cout << " BIT2400 Assignment M4 \n";
    cout << " October 29 2017 \n\n";
    cout << " DEMO VERSION \n\n";
    
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

void hangMan(int entryFail) {
    //switch statement with each hangman phase
    switch (entryFail) {
        case 1:     cout << " ____________________" << endl;
            cout << "|  __________________|" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |                      THIS IS YOUR FIRST MISS, SIX TO GO" << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |                " << endl;
            cout << "| |             " << endl;
            cout << "--------------------------|" << endl;
            cout << "| |---------------------| |" << endl;
            cout << "| |                     | |" << endl;
            cout << ": :                     : :" << endl;
            cout << ". .                     . ." << endl;
            break;
        case 2:   cout << " ____________________" << endl;
            cout << "|  __________________|" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||.--." << endl;
            cout << "| |          |/     \\" << endl;
            cout << "| |          ||     |" << endl;
            cout << "| |           \\`_ .'" << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |    " << endl;
            cout << "| |                      THIS IS YOUR SECOND MISS, FIVE TO GO" << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |                " << endl;
            cout << "| |             " << endl;
            cout << "--------------------------|" << endl;
            cout << "| |---------------------| |" << endl;
            cout << "| |                     | |" << endl;
            cout << ": :                     : :" << endl;
            cout << ". .                     . ." << endl;
            break;
        case 3:     cout << " ____________________" << endl;
            cout << "|  __________________|" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||.--." << endl;
            cout << "| |          |/     \\" << endl;
            cout << "| |          ||     |" << endl;
            cout << "| |          (\\`_ .'" << endl;
            cout << "| |         .-`--'." << endl;
            cout << "| |           . . " << endl;
            cout << "| |          |   | " << endl;
            cout << "| |          | . | " << endl;
            cout << "| |          |   | " << endl;
            cout << "| |                      THIS IS YOUR THIRD MISS, FOUR TO GO" << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |                " << endl;
            cout << "| |             " << endl;
            cout << "--------------------------|" << endl;
            cout << "| |---------------------| |" << endl;
            cout << "| |                     | |" << endl;
            cout << ": :                     : :" << endl;
            cout << ". .                     . ." << endl;
            break;
        case 4:    cout << " ____________________" << endl;
            cout << "|  __________________|" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||.--." << endl;
            cout << "| |          |/     \\" << endl;
            cout << "| |          ||     |" << endl;
            cout << "| |          (\\`_ .'" << endl;
            cout << "| |         .-`--'." << endl;
            cout << "| |        /Y . . " << endl;
            cout << "| |       // |   | " << endl;
            cout << "| |      //  | . | " << endl;
            cout << "| |     ')   |   | " << endl;
            cout << "| |                      THIS IS YOUR FOURTH MISS, THREE TO GO" << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |                " << endl;
            cout << "| |             " << endl;
            cout << "--------------------------|" << endl;
            cout << "| |---------------------| |" << endl;
            cout << "| |                     | |" << endl;
            cout << ": :                     : :" << endl;
            cout << ". .                     . ." << endl;
            break;
        case 5:  cout << " ____________________" << endl;
            cout << "|  __________________|" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||.--." << endl;
            cout << "| |          |/     \\" << endl;
            cout << "| |          ||     |" << endl;
            cout << "| |          (\\`_ .'" << endl;
            cout << "| |         .-`--'." << endl;
            cout << "| |        /Y . . Y\\" << endl;
            cout << "| |       // |   | \\\\" << endl;
            cout << "| |      //  | . |  \\\\" << endl;
            cout << "| |     ')   |   |   (`" << endl;
            cout << "| |                      THIS IS YOUR FIFTH MISS, TWO TO GO" << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |               " << endl;
            cout << "| |                " << endl;
            cout << "| |             " << endl;
            cout << "--------------------------|" << endl;
            cout << "| |---------------------| |" << endl;
            cout << "| |                     | |" << endl;
            cout << ": :                     : :" << endl;
            cout << ". .                     . ." << endl;
            break;
        case 6:       cout << " ____________________" << endl;
            cout << "|  __________________|" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||.--." << endl;
            cout << "| |          |/     \\" << endl;
            cout << "| |          ||     |" << endl;
            cout << "| |          (\\ _ .'" << endl;
            cout << "| |         .-`--'." << endl;
            cout << "| |        /Y . . Y\\" << endl;
            cout << "| |       // |   | \\\\" << endl;
            cout << "| |      //  | . |  \\\\" << endl;
            cout << "| |     ')   |   |   (`" << endl;
            cout << "| |          ||-             THIS IS YOUR SIXTH MISS, ONE MORE AND GAME OVER" << endl;
            cout << "| |          ||   " << endl;
            cout << "| |          ||   " << endl;
            cout << "| |          ||   " << endl;
            cout << "| |         / |    " << endl;
            cout << "| |         `-' " << endl;
            cout << "--------------------------|" << endl;
            cout << "| |---------------------| |" << endl;
            cout << "| |                     | |" << endl;
            cout << ": :                     : :" << endl;
            cout << ". .                     . ." << endl;
            break;
        case 7:
            cout << " ____________________" << endl;
            cout << "|  __________________|" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||" << endl;
            cout << "| |          ||.--." << endl;
            cout << "| |          |/     \\" << endl;
            cout << "| |          ||     |" << endl;
            cout << "| |          (\\`_ .'" << endl;
            cout << "| |         .-`--'." << endl;
            cout << "| |        /Y . . Y\\" << endl;
            cout << "| |       // |   | \\\\" << endl;
            cout << "| |      //  | . |  \\\\" << endl;
            cout << "| |     ')   |   |   (`" << endl;
            cout << "| |          ||-||           YOU LOST AND HAVE BEEN HUNG" << endl;
            cout << "| |          || ||" << endl;
            cout << "| |          || ||" << endl;
            cout << "| |          || ||" << endl;
            cout << "| |         / | | \\" << endl;
            cout << "----------|_`-' `-' |---|" << endl;
            cout << "| |-------\\ \\       ' | |" << endl;
            cout << "| |        \\ \\        | |" << endl;
            cout << ": :         \\ \\       : :" << endl;
            cout << ". .          `'         . ." << endl;
            thanks();
            break;
        default: cout << "ERROR GO BACK TO MAIN MENU" << endl;
            menu();
    }
    
}

int charCount(string word) {
    //this function gets the total number of different chars in a string, does not count repetetion
    int total = 1;
    int temp = 0;
    int count = 0;
    
    for (int i = 97; i < 122; i++) {
        for (int j = 0; j < word.size(); j++) {
            if (word[j] == (char)i) {
                count++;
                temp += count;
                int count = 0;
            }
        }
        if (temp > 2) {
            temp = 1;
            total += temp;
        }
    }
    return total;
}

void thanks() {
    
    cout << " Thank you for playing " << endl;
    cout << " press m for main menu, or q to quit " << endl;
    char ent = '0';
    cin >> ent;
    
    if (ent == 'm') {
        menu();
        system("CLS");
    }
    else if (ent == 'q') {
        exit(0);
    }
    else {
        menu();
        system("CLS");
    }
}

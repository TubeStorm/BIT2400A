//Title: Assignmnet-7
//Author: Favour Diokpo
//Objective: display knowledge of Singleton, Observer and Factory Design paterns in a note taking application.
#include <iostream>
#include "NoteFactory.h"

enum States { APP = 1, CREDIT, END };
enum AppStates { ADD = 1, EDIT, VIEW};

void menu();
void appmenu();
void credit();
void thanks();
void addNotes();
void editNotes();
void viewNotes();

int main() {
    menu();
    return 0;
}

void menu() {
    system("CLS");
    cout << "   _   _   _   _       _   _   _   _   _   \n  / \\ / \\ / \\ / \\     / \\ / \\ / \\ / \\ / \\\n ( N | O | T | E |   | T | A | K | E | R )\n  \\_/ \\_/ \\_/ \\_/     \\_/ \\_/ \\_/ \\_/ \\_/ " << endl;
    
    int entry = 0;
    cout << "\nSelect an option from the main menu \n\n";
    cout << " Press 1 to use the Notes App \n";
    cout << " Press 2 to Credit \n";
    cout << " Press 3 to Quit \n";
    cin >> entry;
    
    if (entry == APP) {
        system("CLS");
        appmenu();
    }
    else if (entry == CREDIT) {
        system("CLS");
        credit();
    }
    else if (entry == END) {
        exit(0);
    }
    else {
        cout << "ERROR: WRONG ENTRY NUMBER\n\n";
        system("CLS");
        menu();
    }
}

void appmenu() {
    system("CLS");
    int entry = 0;
    cout << "\nSelect an option from the Notes menu \n\n";
    cout << " Press 1 to add a new note \n";
    cout << " Press 2 to edit notes \n";
    cout << " Press 3 to view notes \n";
    cout << " Press 4 to go back to main menu \n";
    cin >> entry;
    
    if (entry == ADD) {
        system("CLS");
        addNotes();
    }
    else if (entry == EDIT) {
        system("CLS");
        editNotes();
    }
    else if (entry == VIEW) {
        system("CLS");
        viewNotes();
    }
    else if (entry == 4) {
        system("CLS");
        menu();
    }
    else {
        cout << "ERROR: WRONG ENTRY NUMBER\n\n";
        system("CLS");
        appmenu();
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

void addNotes(){
    vector<Note*> folder;
    string noteEntry;
    cout << " Add a new note (y/n) " << endl;
    char entry = '\0';
    if (entry == 'n'){
        appmenu();
    }
    else{
        string title;
        cout<<" Start typing here..."<< endl;
        system("pause");
        folder.push_back(NoteFactory::GetInstnce()->createNote(NoteTypes::Note1));
        cin>> noteEntry;
        
        cout<<" Would you like to save note y/n "<< endl;
        cin >> entry;
        if (entry == 'n') {
            cout<<" Press y to type a new note " << endl;
            cout<<" Press n to go back to applications menu " << endl;
            cin >> entry;
            if (entry == 'y') {
                addNotes();
            }
            else{
                appmenu();
            }
        }
        else{
            cout<<" What is the title of your note: " << endl;
            cin >> title;
            for (int i = 0; i < folder.size(); i++)
            {
                folder[i]->setNotes(noteEntry);
                folder[i]->setTopic(title);
            }
            cout<<" Note saved "<< endl;
            appmenu();
        }
    }
    
}
void editNotes(vector <Note*> note){
    cout<< " All notes: " <<endl;
    for (int i = 0; i < note.size(); i++)
    {
        cout<< i+1 << ".) " << note[i]->getTopic() << endl;
    }
    system("pause");
    
    cout<< " select a note number to edit" << endl;
    int entry;
    cin >> entry;
    system("CLS");
    
    if(entry >= 1){
        cout<< " press 1 to continue writing in this note " << endl;
        cout<< " press 2 to rewrite this note " << endl;
        for (int i = 0; i < note.size(); i++)
        {
            
        }
    }
}
void viewNotes(vector <Note*> note){
    for (int i = 0; i < note.size(); i++)
    {
        
    }
}

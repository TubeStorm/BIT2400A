#pragma once
#include "NoteApp.h"

class Note1 : public Note
{
public:
    Note1() {}
    
    void setNotes(string entry) {
        note = entry;
    }
    string getNotes() {
        return note;
    }
    string getTopic(){
        return topic;
    }
    void setTopic(string title){
        topic = title;
    }
};

class Note2 : public Note
{
public:
    Note2() {}
    
    void setNotes(string entry) {
        note = entry;
    }
    string getNotes() {
        return note;
    }
    string getTopic(){
        return topic;
    }
    void setTopic(string title){
        topic = title;
    }
};

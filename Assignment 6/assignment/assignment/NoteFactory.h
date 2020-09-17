#pragma once
#include "NoteApp.h"
#include "NoteType.h"

enum class NoteTypes { Note1, Note2};

class NoteFactory
{
public:
    static NoteFactory* GetInstnce();
    
    Note* createNote(NoteTypes type);
    
private:
    NoteFactory();
    static NoteFactory* m_NoteFactory;
    
};

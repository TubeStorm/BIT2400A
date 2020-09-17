#include "NoteFactory.h"

NoteFactory* NoteFactory::m_NoteFactory = 0;

NoteFactory* NoteFactory::GetInstnce()
{
    if (m_NoteFactory == 0)
        m_NoteFactory = new NoteFactory();
    return m_NoteFactory;
}

NoteFactory::NoteFactory(){}

Note* NoteFactory::createNote(NoteTypes type)
{
    switch (type)
    {
        case NoteTypes::Note1:
            return new Note1;
            break;
        case NoteTypes::Note2:
            return new Note2;
            break;
        default:
            break;
    }
}

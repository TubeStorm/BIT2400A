#pragma once
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <vector>
//#include <windows.h>

using namespace std;

class Note
{
protected:
    string note;
    string topic;
public:
    virtual string getNotes() = 0;
    virtual void setNotes(string entry) = 0;
    virtual string getTopic() = 0;
    virtual void setTopic(string title) = 0;
};

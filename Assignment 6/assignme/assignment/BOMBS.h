#pragma once
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <time.h>
//#include <windows.h>

using namespace std;

class Bombs
{
public:
    virtual int symbol() = 0;
    virtual int size() = 0;
};

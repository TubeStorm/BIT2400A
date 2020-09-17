#pragma once
#include "BOMBS.h"
#include "Barrel.h"
#include "Bouncing.h"
#include "C4.h"
#include "Glider.h"

enum class BOMBTypes { Barrel, Bouncing, Glider, C4 };

class BOMBFactory
{
public:
    static BOMBFactory* GetInstnce();
    
    Bombs* createBOMB(BOMBTypes type);
    
private:
    BOMBFactory();
    static BOMBFactory* m_BOMBFactory;
    
};

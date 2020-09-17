#include "BOMBFactory.h"

BOMBFactory* BOMBFactory::m_BOMBFactory = 0;

BOMBFactory* BOMBFactory::GetInstnce()
{
    if (m_BOMBFactory == 0)
        m_BOMBFactory = new BOMBFactory();
    return m_BOMBFactory;
}

BOMBFactory::BOMBFactory(){}

Bombs* BOMBFactory::createBOMB(BOMBTypes type)
{
    switch (type)
    {
        case BOMBTypes::Barrel:
            return new Barrel();
            break;
        case BOMBTypes::Bouncing:
            return new Bouncing();
            break;
        case BOMBTypes::Glider:
            return new Glider();
            break;
        case BOMBTypes::C4:
            return new C4();
            break;
        default:
            break;
    }
}

#include "NPCFactory.h"

NPCFactory* NPCFactory::m_NPCFactory = 0;

NPCFactory* NPCFactory::GetInstnce()
{
	if (m_NPCFactory == 0)
		m_NPCFactory = new NPCFactory();
	return m_NPCFactory;
}

NPCFactory::NPCFactory(){}

NPC* NPCFactory::createNPC(NPCTypes type)
{
	switch (type)
	{
	case NPCTypes::Butcher:
		return new Butcher();
		break;
	case NPCTypes::Baker:
		return new Baker();
		break;
	case NPCTypes::Chandler:
		return new Chandler();
		break;
	default:
		break;
	}
}
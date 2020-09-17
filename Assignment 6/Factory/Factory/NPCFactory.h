#pragma once
#include "NPC.h"
#include "Butcher.h"
#include "Baker.h"
#include "Chandler.h"

enum class NPCTypes { Butcher, Baker, Chandler };

class NPCFactory
{
public:
	static NPCFactory* GetInstnce();

	NPC* createNPC(NPCTypes type);

private:
	NPCFactory();
	static NPCFactory* m_NPCFactory;

};
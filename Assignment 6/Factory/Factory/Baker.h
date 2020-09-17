#pragma once
#include "NPC.h"

class Baker : public NPC
{
public:
	Baker() {}
	
	string getProfession() { return "I am a Baker"; }

};
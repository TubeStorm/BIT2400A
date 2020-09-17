#pragma once
#include "NPC.h"

class Butcher : public NPC
{
public:
	Butcher() {}

	string getProfession() { return "I am a Butcher"; }
};
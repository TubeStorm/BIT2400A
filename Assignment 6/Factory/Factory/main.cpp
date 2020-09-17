#include <iostream>
#include <vector>
#include "NPCFactory.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<NPC*> NPCs;
	
	NPCs.push_back(NPCFactory::GetInstnce()->createNPC(NPCTypes::Butcher));
	NPCs.push_back(NPCFactory::GetInstnce()->createNPC(NPCTypes::Baker));
	NPCs.push_back(NPCFactory::GetInstnce()->createNPC(NPCTypes::Chandler));

	for (int i = 0; i < NPCs.size(); i++)
	{
		cout << NPCs[i]->getProfession() << endl;
	}

	system("pause");

	return 0;
}

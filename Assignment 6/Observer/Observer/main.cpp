#include <iostream>
#include <conio.h>
#include "InputListener.h"
#include "InputManager.h"

using namespace std;

class Player : public InputListener
{
	InputManager* inputMgr;

	void keyDownEvent(int input) 
	{
		switch (input)
		{
		case 27:
			exit(0);
			break;
		case 'p':
			inputMgr->Detach('p');
			break;
		}

		cout << (char)input << endl; 
	}

public:
	Player(InputManager* inputMgr) : inputMgr(inputMgr) {}
};

int main()
{
	InputManager* inputMgr = new InputManager();

	Player* player = new Player(inputMgr);
		
	inputMgr->Attach('w');
	inputMgr->Attach('a');
	inputMgr->Attach('s');
	inputMgr->Attach('d');

	inputMgr->Attach('p');
	inputMgr->Attach(27);

	inputMgr->SetListeners(player);

	while (true)
	{
		if (_kbhit())
		{
			inputMgr->Notify(_getch());
		}
	}

	return 0;
}
#include <iostream>
#include "TimerMgr.h"

using namespace std;

void TimerEnd()
{
	cout << "Timer finished" << endl;
	cout << time(0) << endl;
	//TimerMgr::GetInstance()->createTimer(1000, TimerEnd);
}

int main()
{

	TimerMgr::GetInstance()->createTimer(1000, TimerEnd);
	TimerMgr::GetInstance()->createTimer(1250, TimerEnd);
	TimerMgr::GetInstance()->createTimer(1500, TimerEnd);
	TimerMgr::GetInstance()->createTimer(2000, TimerEnd);
	TimerMgr::GetInstance()->createTimer(3000, TimerEnd);
	TimerMgr::GetInstance()->createTimer(4000, TimerEnd);
	TimerMgr::GetInstance()->createTimer(5000, TimerEnd);
	TimerMgr::GetInstance()->createTimer(10000, TimerEnd);

	TimerMgr::GetInstance()->createTimer(1000, []() { cout << "Lambda Timer Finished" << endl; });


	while (true)
	{
		TimerMgr::GetInstance()->tickTimers();
	}

	return 0;
}
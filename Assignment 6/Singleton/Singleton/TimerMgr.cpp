#include "TimerMgr.h"

TimerMgr* TimerMgr::m_TimerMgr = 0;

TimerMgr* TimerMgr::GetInstance()
{
	if (m_TimerMgr == 0)
		m_TimerMgr = new TimerMgr();
	return m_TimerMgr;
}

TimerMgr::TimerMgr()
{

}

void TimerMgr::createTimer(int milliseconds, function<void()> fn /*void(*fn)()*/)
{
	Timer *timer = new Timer(milliseconds, clock(), fn);
	m_timers.push_back(timer);
}

void TimerMgr::tickTimers()
{
	for (int i = 0; i < m_timers.size(); i++)
	{
		if (m_timers[i]->tick(clock()))
		{
			delete m_timers[i];
			m_timers.erase(m_timers.begin() + i);
			i--;
		}
	}
}
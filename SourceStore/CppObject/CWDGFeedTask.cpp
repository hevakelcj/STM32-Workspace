
#include "CWDGFeedTask.h"
#include "delay.h"
#include "WatchDog.h"
#include "CDebug.h"
#include <stdio.h>

CWDGFeedTask::CWDGFeedTask()
	:CTask(TaskPrio(), TaskName())
{
}

CWDGFeedTask& CWDGFeedTask::GetInstance()
{
	static CWDGFeedTask instance;
	return instance;
}

bool CWDGFeedTask::Initialize()
{
	WATCHDOG_setTimeOut(WATCHDOG_FEED_TIME);	// 5�볬ʱ
	return true;	
}

bool CWDGFeedTask::Execution()
{
	WATCHDOG_feed();
	Delay_s(2);
	return true;
}

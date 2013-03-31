
#include "CStartTask.h"
#include "CShellTask.h"
#include "CWDGFeedTask.h"
#include "CDebug.h"
#include "misc_init.h"
#include "delay.h"

CStartTask::CStartTask()
	:CTask(TASK_PRIO_START, "CStartTask")
{
}

bool  CStartTask::Initialize()
{
	OS_CPU_SysTickInit();	//����ʱ��
	OSStatInit();			//��ʼ��ͳ������

	MISC_Init();

	return true;
}

bool  CStartTask::Execution()
{
	gShell.Create();
	gDebug.Create();

#if	WATCHDOG_ENABLE > 0
	gWatchDog.Create();
#endif

	return false;
}



#ifndef __CWDGFEEDTASK_H__
#define	__CWDGFEEDTASK_H__

#include "CTask.h"

class CWDGFeedTask : public CTask
{
public:
	CWDGFeedTask();

public:
	static CWDGFeedTask&	GetInstance();

protected:
	virtual	bool	Initialize();
	virtual	bool	Execution();

	virtual	INT8U	TaskPrio(){ return TASK_PRIO_FEEDDOG; }
	virtual	INT32U	StackSize(){ return 256;}
	virtual	const char *TaskName(){ return "CWDGFeedTask"; }  
};

#define	gWatchDog  CWDGFeedTask::GetInstance()

#endif // __CWDGFEEDTASK_H__

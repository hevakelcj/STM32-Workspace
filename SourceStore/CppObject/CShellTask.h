
#ifndef	__CSHELLTASK_H__
#define	__CSHELLTASK_H__

#include "CTask.h"

class CShellTask : public CTask
{
public:
	CShellTask();

public:
	static CShellTask&	GetInstance();
	bool isActive() {return m_bActive;}

protected:
	virtual	bool	Initialize();
	virtual	bool	Execution();

	virtual	INT8U	TaskPrio(){ return TASK_PRIO_SHELL; }
	virtual	INT32U	StackSize(){ return 256;}
	virtual	const char *TaskName(){ return "CShellTask"; }  

private:
	bool	m_bActive;
};

#define	gShell	CShellTask::GetInstance()

#endif


#ifndef __CTASK_H__
#define	__CTASK_H__

#include "includes.h"

#define	TASK_NAME_MAXSIZE	30

class CTask
{
public:
	CTask(int nPriority, const char* pTaskName="Unknow Task");
	~CTask();

	INT8U	Create(bool bRunNow=true);
	INT8U	Run();
	INT8U	Suspend();
	INT8U	Resume();
	INT8U	ChangePrio(INT8U nNewPrio);
	
	INT8U	GetPrio() const { return m_nPrio; }
	INT8U	GetId() const { return m_nId; }
	const char*	GetName() const { return m_aTaskName; }
	INT8U	GetStackUsage();
	INT32U	GetStackFree();

protected:
	virtual	bool	Initialize() = 0;
	virtual	bool	Execution() = 0;

	virtual	INT32U	StackSize(){ return 256;}
	
private:
	static void _callbackFunc( void *pData );
	static int  s_nNextId;
	
protected:
	OS_STK	*m_pTaskStack;
	INT8U	m_nPrio;
	INT8U	m_nId;
	char	m_aTaskName[TASK_NAME_MAXSIZE];
};

#endif //__CTASK_H__

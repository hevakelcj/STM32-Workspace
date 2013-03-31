
#include "CTask.h"
#include <stdio.h>

int	CTask::s_nNextId = 0;

CTask::CTask(int nPriority, const char* pTaskName)
	:m_nPrio(nPriority)
{
	INT32U nStackSize = StackSize();

	m_pTaskStack = new OS_STK[ nStackSize ];
	strncpy(m_aTaskName, pTaskName, TASK_NAME_MAXSIZE);
}

CTask::~CTask()
{
	delete [] m_pTaskStack;
	m_pTaskStack = NULL;
}

INT8U  CTask::Create(bool bRunNow)
{
	INT32U nStackSize = StackSize();
										
	m_nId = s_nNextId ++;

	OSSchedLock();	
	INT8U  errno = OSTaskCreateExt(_callbackFunc, (void*)this, 
					&m_pTaskStack[nStackSize-1],
					m_nPrio,
					m_nId,
					m_pTaskStack,
					nStackSize,
					(void*)NULL,
					OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
	if (!errno){
		OSTaskNameSet(m_nPrio, (INT8U*)m_aTaskName, &errno);
	}
	
	if (!bRunNow){
		OSTaskSuspend(m_nPrio);
	}
	OSSchedUnlock();

	return errno;
}

INT8U  CTask::Run()
{
	return OSTaskResume(m_nPrio);
}

INT8U  CTask::Suspend()
{
	return OSTaskSuspend(m_nPrio);
}

INT8U  CTask::Resume()
{
	return OSTaskResume(m_nPrio);
}

INT8U  CTask::ChangePrio(INT8U nNewPrio)
{
	INT8U	nOldPrio = m_nPrio;
	
	OSTaskChangePrio(m_nPrio, nNewPrio);
	m_nPrio = nNewPrio;
	
	return nOldPrio;
}

INT8U  CTask::GetStackUsage()
{
	OS_STK_DATA	stk;
	OSTaskStkChk(m_nPrio, &stk);

	return stk.OSUsed * 100 / (stk.OSFree + stk.OSUsed);
}

INT32U  CTask::GetStackFree()
{
	OS_STK_DATA	stk;
	OSTaskStkChk(m_nPrio, &stk);

	return stk.OSFree;
}

void CTask::_callbackFunc(void * pData)
{
	CTask* pTask = (CTask*)pData;

	if (pTask->Initialize()){
		printf("[%02d]%s is running.\n", pTask->GetPrio(), pTask->GetName());	
		while (pTask->Execution());
		printf("[%02d]%s is end.\n", pTask->GetPrio(), pTask->GetName());
	}else{
		printf("[%02d]%s initialze fail!.\n", pTask->GetPrio(), pTask->GetName());	
	}
	OSTaskDel(OS_PRIO_SELF);
}

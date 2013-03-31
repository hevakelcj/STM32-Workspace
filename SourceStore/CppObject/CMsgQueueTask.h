
#ifndef __CMSGQUEUETASK_H__
#define __CMSGQUEUETASK_H__

#include "CTask.h"
#include <string.h>

template <class MsgT>
class CMsgQueueTask : public CTask
{
public:
	CMsgQueueTask(int nPriority, const char* pTaskName="No Name MsgQueueTask")
		: CTask(nPriority, pTaskName)
		, m_pMsgQueue(NULL)
		, m_paMsgTable(NULL)
		, m_pMsgSem(NULL)
		, m_paMsgStorage(NULL)
		, m_nMsgIndex(0)
	{
		m_nQueueSize = GetQueueSize();
	}

public:
	void PostMsg( const MsgT *pMsg, int length = sizeof(MsgT) )
	{
		OS_CPU_SR   cpu_sr = 0u;

		if (OSSemAccept(m_pMsgSem) == 0 || length > sizeof(MsgT)){
			return ;
		}
		
		if (0 == OSIntNesting)
			OS_ENTER_CRITICAL();

		INT32U nIndex = m_nMsgIndex;
		m_nMsgIndex = (m_nMsgIndex + 1) % m_nQueueSize;
		
		if (0 == OSIntNesting)
			OS_EXIT_CRITICAL();

		memcpy(&m_paMsgStorage[nIndex], pMsg, length);

		OSQPost(m_pMsgQueue, (void*)&m_paMsgStorage[nIndex]);
	}

protected:
	virtual bool Initialize()
	{
		m_paMsgTable   = new INT32U [m_nQueueSize];
		m_paMsgStorage = new MsgT [m_nQueueSize];
		m_pMsgSem      = OSSemCreate(m_nQueueSize);
		m_pMsgQueue    = OSQCreate((void **)&m_paMsgTable, m_nQueueSize);

		return true;
	}

	virtual bool Execution()
	{
		INT8U errno = 0;

	 	MsgT *pMsg = (MsgT *) OSQPend(m_pMsgQueue, 0, &errno);
		
		ProcessMsg(pMsg);
		OSSemPost(m_pMsgSem);

		return true;
	}

	virtual void ProcessMsg( const MsgT *pMsg ) = 0;
	virtual int  GetQueueSize() const { return 16; }

private:
	int       m_nQueueSize;
	OS_EVENT *m_pMsgQueue;
	INT32U   *m_paMsgTable;
	OS_EVENT *m_pMsgSem;
	MsgT     *m_paMsgStorage;
	INT32U    m_nMsgIndex;
};

#endif //__CMSGQUEUETASK_H__

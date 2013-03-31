
#ifndef __CSTARTTASK_H__
#define __CSTARTTASK_H__

#include "CTask.h"

class CStartTask : public CTask
{
public:
	CStartTask();
protected:
	virtual bool	Initialize();
	virtual bool	Execution();
};

#endif //__CSTARTTASK_H__



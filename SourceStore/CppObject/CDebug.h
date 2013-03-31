
#ifndef	__CDEBUG_H__
#define	__CDEBUG_H__

#include "CMsgQueueTask.h"

#define	DEDUG_STR_MAXSIZE 128

typedef enum{
	DebugCmd_PrintString,
	DebugCmd_PrintChar,
	DebugCmd_Other,
}DebugCmd;

typedef struct{
	DebugCmd  Cmd;
	union{
		char aString[DEDUG_STR_MAXSIZE];
		int  nChar;
	}Data;	
}tagDebugMsg;

class CDebug : public CMsgQueueTask<tagDebugMsg>
{
public:
	CDebug();

	static CDebug& GetInstance();
		
	int  Printf(const char *pFormat, ...);
	void Puts(const char *pString);
	int  Putchar(int ch);

protected:
	virtual bool Initialize();
	virtual void ProcessMsg( const tagDebugMsg *pMsg );

private:
	virtual	INT8U TaskPrio(){ return TASK_PRIO_DEBUG_MSG; }
	virtual	const char *TaskName(){ return "CDebug"; } 
	virtual int  GetQueueSize() const { return 3; }
};

#define	gDebug	CDebug::GetInstance()

#endif // __CDEBUG_H__

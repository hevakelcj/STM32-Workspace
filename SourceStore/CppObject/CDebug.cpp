																	 
#include "CDebug.h"
#include "CShellTask.h"
#include <stdio.h>
#include <stdarg.h>

CDebug::CDebug()
	:CMsgQueueTask(TaskPrio(), TaskName())
{
}

CDebug& CDebug::GetInstance()
{
	static CDebug instance;
	return instance;
}

bool CDebug::Initialize()
{
	CMsgQueueTask::Initialize();
	return true;
}

void CDebug::ProcessMsg( const tagDebugMsg *pMsg )
{
	if (gShell.isActive()){	// ���shell���ڽ��������ܴ�ӡ��Ϣ��
		return;	
	}

	switch (pMsg->Cmd){
		case DebugCmd_PrintString:{
			const char *str = pMsg->Data.aString;
			while (*str){
				putchar(*str++);
			}
			break;
		}
		case DebugCmd_PrintChar:
			putchar(pMsg->Data.nChar);
			break;
	default: break;
	}
}

int CDebug::Printf(const char *pFormat, ...)
{
	tagDebugMsg	msg;
	va_list	argp;
	int	ret = 0 ;

	va_start(argp,pFormat);
	ret = vsnprintf(msg.Data.aString, DEDUG_STR_MAXSIZE, pFormat, argp);
	va_end(argp);

	msg.Data.aString[DEDUG_STR_MAXSIZE-1] = '\0';	// ����ַ������������Է�û�������ִ������
	
	msg.Cmd = DebugCmd_PrintString;
	PostMsg(&msg);

	return ret;
}

void CDebug::Puts(const char *pString)
{
	tagDebugMsg	msg;

	strncpy(msg.Data.aString, pString, DEDUG_STR_MAXSIZE);
	msg.Data.aString[DEDUG_STR_MAXSIZE-1] = '\0';	// ����ַ������������Է�û�������ִ������
	
	msg.Cmd = DebugCmd_PrintString;
	PostMsg(&msg);
}

int CDebug::Putchar(int ch)
{
	tagDebugMsg	msg;
	msg.Data.nChar = ch;
	msg.Cmd = DebugCmd_PrintChar;
	PostMsg(&msg);
	return ch;
}


#include "CShellTask.h"
#include "Shell.h"
#include "delay.h"
#include <stdio.h>

CShellTask::CShellTask()
	:CTask(TaskPrio(), TaskName())
	,m_bActive(false)
{
}

CShellTask& CShellTask::GetInstance()
{
	static CShellTask instance;
	return instance;
}

bool CShellTask::Initialize()
{
	Delay_ms(100);
	return true;	
}

bool CShellTask::Execution()
{
	puts("Press any key to enter tinySH...");
	getchar(); 		//等待从标准数据IO口输入数据 
	m_bActive = true;
	puts("\n====[ Welcome to tinySH ]====");
	ShellEntry();		//进入控制台
	puts("====[ Exit tinySH ]====");
	m_bActive = false;

	return true;
}

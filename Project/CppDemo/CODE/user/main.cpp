
#include "CStartTask.h"
#include "bsp_init.h"

int main()
{
	BSP_Init();	// Ӳ����ʼ��
	OSInit(); 	// ϵͳ��ʼ��

	CStartTask start;
	start.Create();
	
	OSStart();

	return 0;
}



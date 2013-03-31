
#include "CStartTask.h"
#include "bsp_init.h"

int main()
{
	BSP_Init();	// 硬件初始化
	OSInit(); 	// 系统初始化

	CStartTask start;
	start.Create();
	
	OSStart();

	return 0;
}



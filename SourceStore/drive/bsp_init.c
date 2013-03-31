
#include <stdio.h>
#include <rt_heap.h>	//_init_alloc
#include "bsp_init.h"
#include "fsmc_sram.h"
#include "watchdog.h"
#include "type.h"
#include "app_cfg.h"
#include "usart.h"
#include "delay.h"

#if	USING_SRAM_AS_HEAP > 0
	#define	HEAP_BASE	Bank1_SRAM3_ADDR
	#define	HEAP_TOP	(Bank1_SRAM3_ADDR+0x100000)
#else
	#define	HEAP_SIZE	0xE900
	char	__heap_zone__[HEAP_SIZE];
	
	#define	HEAP_BASE	(unsigned int)&__heap_zone__[0]
	#define	HEAP_TOP	(unsigned int)&__heap_zone__[HEAP_SIZE-1]
#endif

void NVIC_Configuration(void);

void	BSP_Init()
{
	NVIC_Configuration();

#if	USING_SRAM_AS_HEAP > 0
	FSMC_SRAM_Init();
#endif

#if	WATCHDOG_ENABLE > 0
	WATCHDOG_setTimeOut(15);	//如果15秒仍未启动完成，那么就复位
	WATCHDOG_enable();			//调试时要屏蔽
#endif

	_init_alloc(HEAP_BASE, HEAP_TOP);

	USART1_Init();
	USART2_Init();
	USART3_Init();

#ifdef STM32F10X_CL
	UART4_Init();
	UART5_Init();
#endif //STM32F10X_CL

	Delay_ms(10);
}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configure the nested vectored interrupt controller.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
#ifdef  VECT_TAB_RAM  
  	/* Set the Vector Table base location at 0x20000000 */ 
  	NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
#else  /* VECT_TAB_FLASH  */
  	/* Set the Vector Table base location at 0x08000000 */ 
  	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
#endif

  	/* Configure one bit for preemption priority */
  	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}

#ifndef	__APP_CFG_H__
#define	__APP_CFG_H__

/**
  **********************************************************************************
  *	 在 OS_CFG.H 文件中已明确规定最低优先级为63
  *  #define OS_LOWEST_PRIO           63
  **********************************************************************************
  */

//优先级
enum{
	TASK_PRIO_START = 0,
	TASK_PRIO_SHELL,
	TASK_PRIO_DEBUG_MSG,
	TASK_PRIO_FEEDDOG,	// 看门狗的优先级要放最后
};

#define	WATCHDOG_ENABLE			0		//看门狗使能，（调试时要关闭）
#define	WATCHDOG_FEED_TIME		5		//喂IWDG周期，秒（小于10S） 

#define	USING_SRAM_AS_HEAP		1		//是否将SRAM作为堆
/**
 ====================================================================================
 |                        LOOK FOR MISSING #define CONSTANTS  						|
 |																					|
 |																					|
 | NOTE :																			|
 |																					|
 | This section is used to generate ERROR messages at compile time if certain   	|
 | #define constants are MISSING in OS_CFG.H.  This allows you to quickly 			|
 | determine the source of the error.												|
 |																					|
 | You SHOULD NOT change this section UNLESS you would like to add more comments 	|
 | as to the source of the compile time error.										|
 ====================================================================================
 */

#endif	//__APP_CFG_H__

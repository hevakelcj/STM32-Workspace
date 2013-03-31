#ifndef	__APP_CFG_H__
#define	__APP_CFG_H__

/**
  **********************************************************************************
  *	 �� OS_CFG.H �ļ�������ȷ�涨������ȼ�Ϊ63
  *  #define OS_LOWEST_PRIO           63
  **********************************************************************************
  */

//���ȼ�
enum{
	TASK_PRIO_START = 0,
	TASK_PRIO_SHELL,
	TASK_PRIO_DEBUG_MSG,
	TASK_PRIO_FEEDDOG,	// ���Ź������ȼ�Ҫ�����
};

#define	WATCHDOG_ENABLE			0		//���Ź�ʹ�ܣ�������ʱҪ�رգ�
#define	WATCHDOG_FEED_TIME		5		//ιIWDG���ڣ��루С��10S�� 

#define	USING_SRAM_AS_HEAP		1		//�Ƿ�SRAM��Ϊ��
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
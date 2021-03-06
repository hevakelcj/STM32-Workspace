#ifndef	__UTILITY_H__
#define	__UTILITY_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 ====================================================================================
 |  							   文  件  包  含									|
 |																					|
 |  NOTE: 																			|
 ====================================================================================
 */
#include "type.h"

/**
 ====================================================================================
 |  							  变 量 类 型 定 义									|
 |																					|
 |  NOTE: 																			|
 ====================================================================================
 */
typedef struct{
	INT16U	days;
	INT8U	hours;
	INT8U	minutes;
	INT8U	seconds;	
}run_time;

typedef enum{
	ENDIAN_LITTLE,ENDIAN_BIG,
}Endian;

//字符串监听信息结构体
struct listen_unit{
    const char *stringListen;
    INT8U      pos ;
};

/**
 ====================================================================================
 |  							   变  量  声  明									|
 |																					|
 |  NOTE: 																			|
 ====================================================================================
 */
extern	Endian	CPU_Endian ;

/**
 ====================================================================================
 |  							   函  数  声  明									|
 |																					|
 |  NOTE: 																			|
 ====================================================================================
 */

/**
 ***********************************************************************************
 * Function: GetRunTime;
 *
 * Description: 获取运行时间;
 *           
 * Input: 	--ticks   运行嘀嗒;
 *
 * Output:	--ptime   时间;
 *          		
 * Return:	int       返回值;
 *
 * Note: 
 ***********************************************************************************
 */
void	GetRunTime( INT32U ticks , run_time * ptime );

/***********************************************************************************
* Function: CheckCPUEndian;
*
* Description: 检查CPU的数据存储模式;
*           
* Input: 	none;
*
* Output:	g_isChangeEndian    是否需要存储模式切换;
*          		
* Return:	无
*
* Note:  	使用union实现
************************************************************************************/
void	CheckCPUEndian(void);

/***********************************************************************************
* Function: ExchangeEndian;
*
* Description: 转换数据存储模式;
*           
* Input: 	p		要转换的数据指针
*			size	数据所占的存储空间大小
*
* Output:	无;
*          		
* Return:	无
*
* Note:  	由于上位机是采用小端存储模式，而本机可能采用大端存储模式。故在信息交互时需要
*			转换。
************************************************************************************/
void	ExchangeEndian( void* p , INT8U size );

/***********************************************************************************
* Function: Listen;
*
* Description: 监听字符串
*           
* Input:    pl  监听信息
*           Data	串口接收的值;
*      		
* Output: none;
*          		
* Return: 如果监听到一个完整的串，返回TRUE，否则返回FALSE;
*
* Note:   
************************************************************************************/
bool	Listen( struct listen_unit *pl , BYTE Data );

/***********************************************************************************
 * Function: ResetSystem;
 *
 * Description: 软件复位系统;
 *           
 * Input: 	none;
 *
 * Output:	none;
 *          		
 * Return:	none;
 *
 * Note: 	none;
 ***********************************************************************************
 */
void	ResetSystem(void);

/***********************************************************************************
 * Function: Halt;
 *
 * Description: 停机;
 *           
 * Input: 	none;
 *
 * Output:	none;
 *          		
 * Return:	none;
 *
 * Note: 	none;
 ***********************************************************************************
 */
void	Halt(void);

/***********************************************************************************
* Function: YesOrNo;
*
* Description:	用户确定选择
*           
* Input: 	comment	选择说明
*           default_ret	默认值，如果用户既没有输入y与没有输n时返回该值
*      		
* Output: none;
*          		
* Return: bool	用户的选择;
*
* Note:   
************************************************************************************/
bool    YesOrNo( const char * comment , bool default_ret );

/***********************************************************************************
* Function: PrintClock;
*
* Description:	打印各个系统时钟频率
*           
* Input:  none;
*      		
* Output: none;
*          		
* Return: none;
*
* Note:   
************************************************************************************/
void	PrintClock( void );

/**
 ***********************************************************************************
 * Function: PrintData;
 *
 * Description: 打印数据;
 *           
 * Input: 	--name	数据名称
 *          --pData	数据首地址
 *          --size	数据大小
 *
 * Output:	none;
 *          		
 * Return:	none;
 *
 * Note: 
 ***********************************************************************************
 */
void	PrintData( const char *name , const void* pData , int size );

//#define	PRINT_VALUE(value)	PrintData(#value,&value,sizeof(value))
#define	PRINT_POINT(point)	PrintData(#point,point,sizeof(*point))

/**
 ***********************************************************************************
 * Function: Panic;
 *
 * Description: 在出现异常时打印调试信息;
 *           
 * Input: 	--r_sp	寄存器SP的值
 *
 * Output:	none;
 *          		
 * Return:	none;
 *
 * Note: 
 ***********************************************************************************
 */
void	Panic( INT32U r_sp );

/**
 ***********************************************************************************
 * Function: TurnOffPowerOffAlarm;
 *
 * Description: 关闭掉电报警;
 *           
 * Input: 	none;
 *
 * Output:	none;
 *          		
 * Return:	none;
 *
 * Note: 	将PA12配置成推挽输出，并输出高电平
 ***********************************************************************************
 */
void	TurnOffPowerOffAlarm(void);

#ifdef __cplusplus
}
#endif

#endif	//__UTILITY_H__

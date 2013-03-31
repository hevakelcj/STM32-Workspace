
#ifndef	__USART_H__
#define	__USART_H__

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
#include "stream.h"
#include "stm32f10x_usart.h"

/**
 ===================================================================================
 |               	 USARTx的初始化波特率											|
 ===================================================================================
 */
#define	USART1_INIT_BAUDRATE	19200
#define	USART1_REMAP			0
#define	USART1_DR				1

#define	USART2_INIT_BAUDRATE	9600
#define	USART2_REMAP			0
#define	USART2_DR				1

#define	USART3_INIT_BAUDRATE	9600
#define	USART3_REMAP			0

#define	UART4_INIT_BAUDRATE     9600
#define	UART4_REMAP				0

#define	UART5_INIT_BAUDRATE		9600
#define	UART5_REMAP				0

 /**
  ====================================================================================
  | 								类	型	定	义									 |
  | 																				 |
  |  NOTE:																			 |
  ====================================================================================
  */
 typedef enum {
	USART_1, USART_2, USART_3, UART_4, UART_5, USART_MAX
}USART_TypeEnum;

/**
 ====================================================================================
 |  							   变  量  声  明									|
 |																					|
 |  NOTE: 																			|
 ====================================================================================
 */

/**
 ====================================================================================
 |  							   函  数  声  明									|
 |																					|
 |  NOTE: 																			|
 ====================================================================================
 */

/**
  *********************************************************************************
  * @Function: SetUART1ConnectWith;
  *
  * @Description:	设置与USART1对连的串口
  *           
  * @Input:  --uart 串口号;
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:
  ***********************************************************************************
  */
void	SetUART1ConnectWith( USART_TypeEnum uart);

/**
  *********************************************************************************
  * @Function: GetUART1ConnectWith;
  *
  * @Description:	获取与USART1对连的串口
  *           
  * @Input:  none;
  *
  * @Output: none;
  *          		
  * @Return: USART_TypeDef 串口模块地址;
  *
  * @Note:
  ***********************************************************************************
  */
USART_TypeDef* GetUART1ConnectWith(void);

/**
  *********************************************************************************
  * @Function: USART_SetBaudRate;
  *
  * @Description:	设置波特率
  *           
  * @Input:  --usart ;
  *          --baudRate   波特率	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   none;
  ***********************************************************************************
  */
void	USART_SetBaudRate(USART_TypeDef *usart , INT32U baudRate);

/**
  *********************************************************************************
  * @Function: USART_GetBaudRate;
  *
  * @Description:	获取波特率
  *           
  * @Input:  --usart ;
  *
  * @Output: none;
  *          		
  * @Return: INT32U	波特率;
  *
  * @Note:   none;
  ***********************************************************************************
  */
INT32U	USART_GetBaudRate(USART_TypeDef *usart);

/**
  ===================================================================================
  |																					|
  |             USART1模块  														|
  |																					|
  |---------------------------------------------------------------------------------|
  | @ 全局变量 :																	|
  |		file_usart1		USART1文件 													|
  | 																				|
  | @ 函数列表 :																	|
  |     void	USART1_Init()														|
  |		void	USART1_SendData( char ch )											|
  | 	char	USART1_ReceiveData( void )											|
  ===================================================================================
  */

/**
  *********************************************************************************
  * @Function: USART1_init;
  *
  * @Description:	初始化USART1串行接口，配置相关的引脚
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   TX-->PA9
  *          RX-->PA10
  ***********************************************************************************
  */
extern	void	USART1_Init(void);

/**
  *********************************************************************************
  * @Function: USART1_SendData;
  *
  * @Description:	从USART1串行接口发送1个字节数据
  *           
  * @Input:  ch         要发送的数据	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	void	USART1_SendData( char ch );

/**
  *********************************************************************************
  * @Function: USART1_ReceiveData;
  *
  * @Description:	从USART2接口接收1个字节数据
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: char       接收到的数据;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	char	USART1_ReceiveData( void );

/**
  ===================================================================================
  |																					|
  |             USART2模块  														|
  |																					|
  |---------------------------------------------------------------------------------|
  | @ 全局变量 :																	|
  |		file_usart2		USART2文件 													|
  | 																				|
  | @ 函数列表 :																	|
  |     void	USART2_Init()														|
  |		void	USART2_SendData( char ch )											|
  | 	char	USART2_ReceiveData( void )											|
  ===================================================================================
  */

/**
  *********************************************************************************
  * @Function: USART2_Init;
  *
  * @Description:	初始化USART2串行接口，配置相关的引脚
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   TX-->PD5
  *          RX-->PD6
  ***********************************************************************************
  */
extern	void	USART2_Init(void);

/**
  *********************************************************************************
  * @Function: USART2_SendData;
  *
  * @Description:	从USART2串行接口发送1个字节数据
  *           
  * @Input:  ch         要发送的数据	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	void	USART2_SendData( char ch );

/**
  *********************************************************************************
  * @Function: USART2_ReceiveData;
  *
  * @Description:	从USART2接口接收1个字节数据
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: char       接收到的数据;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	char	USART2_ReceiveData( void );

/**
  ===================================================================================
  |																					|
  |             USART3模块  														|
  |																					|
  |---------------------------------------------------------------------------------|
  | @ 全局变量 :																	|
  |		file_usart3		USART3文件 													|
  | 																				|
  | @ 函数列表 :																	|
  |     void	USART3_Init()														|
  |		void	USART3_SendData( char ch )											|
  | 	char	USART3_ReceiveData( void )											|
  ===================================================================================
  */

/**
  *********************************************************************************
  * @Function: USART3_Init;
  *
  * @Description:	初始化USART3串行接口，配置相关的引脚
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   TX-->PD5
  *          RX-->PD6
  ***********************************************************************************
  */
extern	void	USART3_Init(void);

/**
  *********************************************************************************
  * @Function: USART3_SendData;
  *
  * @Description:	从USART3串行接口发送1个字节数据
  *           
  * @Input:  ch         要发送的数据	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	void	USART3_SendData( char ch );

/**
  *********************************************************************************
  * @Function: USART3_ReceiveData;
  *
  * @Description:	从USART3接口接收1个字节数据
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: char       接收到的数据;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	char	USART3_ReceiveData( void );

#ifdef STM32F10X_CL
/**
  ===================================================================================
  |																					|
  |             UART4模块  															|
  |																					|
  |---------------------------------------------------------------------------------|
  | @ 全局变量 :																	|
  |		file_uart4	UART4文件 														|
  | 																				|
  | @ 函数列表 :																	|
  |     void	UART4_Init()														|
  |		void	UART4_SendData( char ch )											|
  | 	char	UART4_ReceiveData( void )											|
  ===================================================================================
  */

/**
  *********************************************************************************
  * @Function: UART4_Init;
  *
  * @Description:	初始化UART4串行接口，配置相关的引脚
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   TX-->PD5
  *          RX-->PD6
  ***********************************************************************************
  */
extern	void	UART4_Init(void);

/**
  *********************************************************************************
  * @Function: UART4_SendData;
  *
  * @Description:	从UART4串行接口发送1个字节数据
  *           
  * @Input:  ch         要发送的数据	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	void	UART4_SendData( char ch );

/**
  *********************************************************************************
  * @Function: UART4_ReceiveData;
  *
  * @Description:	从UART4接口接收1个字节数据
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: char       接收到的数据;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	char	UART4_ReceiveData( void );

/**
  ===================================================================================
  |																					|
  |             UART5模块  															|
  |																					|
  |---------------------------------------------------------------------------------|
  | @ 全局变量 :																	|
  |		file_uart5	UART5文件 														|
  | 																				|
  | @ 函数列表 :																	|
  |     void	UART5_Init()														|
  |		void	UART5_SendData( char ch )											|
  | 	char	UART5_ReceiveData( void )											|
  ===================================================================================
  */

/**
  *********************************************************************************
  * @Function: UART5_Init;
  *
  * @Description:	初始化UART5串行接口，配置相关的引脚
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   TX-->PD5
  *          RX-->PD6
  ***********************************************************************************
  */
extern	void	UART5_Init(void);

/**
  *********************************************************************************
  * @Function: UART5_SendData;
  *
  * @Description:	从UART5串行接口发送1个字节数据
  *           
  * @Input:  ch         要发送的数据	
  *
  * @Output: none;
  *          		
  * @Return: none;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	void	UART5_SendData( char ch );

/**
  *********************************************************************************
  * @Function: UART5_ReceiveData;
  *
  * @Description:	从UART5接口接收1个字节数据
  *           
  * @Input:  none;	
  *
  * @Output: none;
  *          		
  * @Return: char       接收到的数据;
  *
  * @Note:   none;
  ***********************************************************************************
  */
extern	char	UART5_ReceiveData( void );

#endif //STM32F10X_CL

#ifdef __cplusplus
}
#endif

#endif	//__USART_H__

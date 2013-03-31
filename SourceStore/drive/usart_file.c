
#include "usart_file.h"
#include "usart.h"

FILE	file_usart1 = {USART1_SendData,USART1_ReceiveData};
FILE	file_usart2 = {USART2_SendData,USART2_ReceiveData};
FILE	file_usart3 = {USART3_SendData,USART3_ReceiveData};
#ifdef STM32F10X_CL
FILE	file_uart4 = {UART4_SendData,UART4_ReceiveData};
FILE	file_uart5 = {UART5_SendData,UART5_ReceiveData};
#endif 

void	USART_File_Init()
{
	file_usart1.semaphore = OSSemCreate(0);	
	file_usart2.semaphore = OSSemCreate(0);	
	file_usart3.semaphore = OSSemCreate(0);
#ifdef STM32F10X_CL	
	file_uart4.semaphore = OSSemCreate(0);	
	file_uart5.semaphore = OSSemCreate(0);	
#endif
}


#ifndef __USART_FILE_H__
#define	__USART_FILE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stream.h"

extern	FILE	file_usart1;
extern	FILE	file_usart2;
extern	FILE	file_usart3;
extern	FILE	file_uart4;
extern	FILE	file_uart5;

void	USART_File_Init(void);

#ifdef __cplusplus
}
#endif

#endif //__USART_FILE_H__

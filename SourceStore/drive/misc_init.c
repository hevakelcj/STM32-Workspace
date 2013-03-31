
#include "misc_init.h"
#include "usart_file.h"
#include "stream.h"

void	PrintTitle( void )
{
	puts("\n\n");
	puts("+[ Stm32 C++ Demo ]---------------------------+");
	puts("|                                             |");
	puts("| Author  : Lichunjun                         |");
	puts("| E-mail  : hevake_lcj@126.com                |");
	puts("| QQ      : 527020730                         |");
	puts("+---------------------------------------------+");
}

void	MISC_Init( void )
{
	USART_File_Init();
	STDIO_Init();	//������USARTx��ʼ��֮��

	PrintTitle();	//��ӡ����
	puts("Initialize complete.");
}

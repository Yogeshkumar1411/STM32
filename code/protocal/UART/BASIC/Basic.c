#include<stm32f10x.h>
/*#define RS 1<<14
#define EN 1<<15
void delay(unsigned int ms)
{
	int i,j;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<65535;j++);
	}
}
void pulse()
{
	GPIOC->ODR|=EN;
	delay(2);
	GPIOC->BRR|=EN;
	delay(2);
}
void lcd_cmd(char cmd)
{	
	
	GPIOA->BRR|=0X000000FF;
	GPIOC->BRR|=RS;//rs=1;
	GPIOA->ODR|=(cmd & 0XF0)>>3;	
	pulse();
	
	GPIOA->BRR|=0X000000FF;
	GPIOC->BRR|=RS;//rs=1;
	GPIOA->ODR|=(cmd & 0X0F)<<1;
	pulse();
}


void lcd_dat(char data)
{	
	GPIOA->BRR|=0X000000FF;
	GPIOC->ODR|=RS;//rs=1;
	GPIOA->ODR|=(data & 0XF0)>>3;	
	pulse();
	
	GPIOA->BRR|=0X000000FF;
	GPIOC->ODR|=RS;//rs=1;
	GPIOA->ODR|=(data & 0X0F)<<1;
	pulse();	
}*/

void rc()
{
	char data1;
	while(!(USART1->SR&1<<5));
	data1=USART1->DR;
	USART1->SR=0;
	//lcd_dat(data1);
}
void tx(char *data)
{
	while(*data)
	{
	USART1->DR=*data++;
	while(!(USART1->SR&1<<7));
	USART1->SR=0;
	}
}
int main()
{
	RCC->APB2ENR|=1<<0|1<<2|1<<4|1<<14;
	GPIOA->CRL=0X00022220;
	GPIOA->CRH=0X000008A0;
	GPIOC->CRH=0X22200000;
	USART1->CR1=0X0000200C;
	USART1->BRR=0X00001D48;
	//lcd_cmd(0X02);
	//lcd_cmd(0X28);
	//lcd_cmd(0X0E);
	while(1)
	{
		tx("STM key dhushman, unable to remember easily. It is too hard to understand. Side by side Mock interview also going on. What to we do? It's all fate.");
		while(1);
	}
}
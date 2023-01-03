#include<stm32f10x.h>
void delay(unsigned int ms)
{
	while(ms--);
}
void pulse()
{
	GPIOC->ODR=1<<15;
	delay(65000);
	GPIOC->BRR=1<<15;
	delay(65000);	
}
void type()
{
	GPIOC->BRR=1<<13;
	GPIOC->BRR=1<<14;
	GPIOA->ODR=0X38;
	delay(65000);
	GPIOA->BRR=0X38;
	delay(65000);
	pulse();
}
void on()
{
	GPIOC->BRR=1<<13;
	GPIOC->BRR=1<<14;
	GPIOA->ODR=0X0F;
	delay(65000);
	GPIOA->BRR=0X0F;
	delay(65000);
	pulse();
}
void address()
{
	GPIOC->BRR=1<<13;
	GPIOC->BRR=1<<14;
	GPIOA->ODR=0X80;
	delay(65000);
	GPIOA->BRR=0X80;
	delay(65000);
	pulse();
}
void display()
{
	GPIOC->ODR=1<<13;
	delay(65000);
	GPIOC->ODR=1<<13;
	delay(65000);
	GPIOC->BRR=1<<14;
	GPIOA->ODR='A';
	delay(65000);
	GPIOA->BRR='A';
	delay(65000);
	pulse();
}
/*void lcd_cmd1(char a,char b, char c);
{
	GPIOC->ODR=a;
	delay(65000);
	GPIOC->BRR=a;
	delay(65000);
	GPIOC->BRR=b;
	

void lcd_cmd(char a,char b,char c);
{

	GPIOC->BRR=a;	
	GPIOC->BRR=b;
	delay(65000);
	GPIOC->BRR=b;
	delay(65000);*/
	
	
	
	
	
int main()
{
	RCC->APB2ENR=1<<2|1<<4;
	GPIOA->CRL=0X22222222;
	GPIOC->CRH=0X22200000;
	type();
	on();
	while(1)
	{
		address();
		display();
	}
}
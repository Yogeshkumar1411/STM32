#include<stm32f10x.h>
void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
	for(j=0;j<65000;j++);
	}
}
int main()
{
	RCC->APB2ENR=1<<2;
	GPIOA->CRL=0X22222222;
	GPIOA->CRH=0X22222222;
	while(1)
	{
		GPIOA->ODR=0X00005555;
		delay(50);
		GPIOA->BRR=0X00005555;
		delay(50);
		GPIOA->ODR=0X0000AAAA;
		delay(50);
		GPIOA->BRR=0X0000AAAA;
		delay(50);
	}
}
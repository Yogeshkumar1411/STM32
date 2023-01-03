#include<stm32f10x.h>
void delay(long int ms)
{
	while(ms--);
}
int main()
{
	int i,j,k,l;
	RCC->APB2ENR=1<<2;
	GPIOA->CRL=0X22222222;
	//GPIOA->CRH=0X22222222;
	//GPIOB->CRL=0X00000000;
	while(1)
	{
		for(i=3,j=4;i>=0,j<=7;i--,j++)
		{
			GPIOA->ODR|=1<<i|1<<j;
			delay(3000000);
		}
		for(k=0,l=7;k<=3,l>=4;k++,l--)
		{
			GPIOA->BRR|=1<<k|1<<l;
			delay(3000000);
		}
	}
}
	
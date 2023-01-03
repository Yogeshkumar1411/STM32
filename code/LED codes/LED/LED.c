#include<stm32f10x.h>
int main()
{
	RCC->APB2ENR|=1<<2;
	GPIOB->CRH=0X00000002;
	while(1)
	{
		GPIOB->ODR=1<<8;
		//GPIOB->BRR=1<<8;
	}
}
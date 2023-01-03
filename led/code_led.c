#include<stm32f10x.h>
void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
		for(j=0;j<65000;j++);
}
int main()
{
	RCC->APB2ENR|=0x00000010;
	
	
	GPIOC->CRH=0x00200000;
	while(1)
	{
		GPIOC->ODR|=1<<13;
		delay(1);
		GPIOC->BRR|=1<<13;
		delay(1);
	}
}
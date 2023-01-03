#include<stm32f10x.h>
void master(char data)
{
	SPI1->DR=data;
	while((SPI1->SR&1<<7));
}
int main()
{
	RCC->APB2ENR|=RCC_APB2ENR_IOPAEN|RCC_APB2ENR_AFIOEN|RCC_APB2ENR_SPI1EN;
	GPIOA->CRL=0XA8AA0000;
	SPI1->CR1=0X0037;
	
	SPI1->CR2|=1<<2;
	SPI1->CR1|=1<<6;
	while(1)
	{
		master('A');
	}
}
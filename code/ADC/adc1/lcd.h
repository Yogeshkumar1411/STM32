
#define RS 1<<14
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
}


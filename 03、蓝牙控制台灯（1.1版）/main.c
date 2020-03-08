#include<reg51.h>
//sbit led=P1^0;
bit flag = 0;
unsigned char fig = 0;
/********函数声明********/
void LED1();
void LED2();
void LED3();
void LED4();
void set();


void main()
{
set();
while(1)
{
	if (flag == 1 && fig == 0)
	{
		LED1();
	}
	else if(flag == 0)
	{		
		LED2();
	}
	if (flag == 1 && fig == 1  )
	{
	LED3();
	}
	else if (flag == 1 && fig == 2)
	{
		LED4();
	}
}
} 


void set()
{
TMOD=0x20 ; //设置定时器工作方式2
TH1=0xFd ; //设置波特率
TL1=0xFd ;
SCON=0x50; // 工作方式1，SM2=0
PCON= 0x00;// 波特率不加倍 
EA=1;//打开串口中断
ES=1;
TR1=1; //打开定时器

}

void interruptf() interrupt 4
{
switch (SBUF)
{
case 0x01:flag = ~flag;break;      //灯亮，12个白灯
case 0x02:fig = 1;break;			//灯全灭
case 0x03:fig = 2;break;			//灯全灭
}
RI=0;//复位
}

void LED1()   	//灯亮，12个白灯
{
	P0=0X00;
	P1=0Xf0;
	P2=0xff;
}

void LED2()			//灯全灭
{
	P0=0Xff;
	P1=0Xff;
	P2=0xff;
	fig = 0;

}
void LED3()				//12个暖灯亮
{
	P0=0Xff;
	P1=0X0f;
	P2=0x00;

}
void LED4()			//24个灯全亮
{
		P0=0X00;
		P1=0X00;
		P2=0x00;
}
#include<reg51.h>
sbit led=P1^0;
void set();
void main()
{
set();
while(1)
{
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
case 0x01:P1=0X00; break;
case 0x02:P1=0XFF;break;
}
RI=0;//复位
}

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
TMOD=0x20 ; //���ö�ʱ��������ʽ2
TH1=0xFd ; //���ò�����
TL1=0xFd ;
SCON=0x50; // ������ʽ1��SM2=0
PCON= 0x00;// �����ʲ��ӱ� 
EA=1;//�򿪴����ж�
ES=1;
TR1=1; //�򿪶�ʱ��

}

void interruptf() interrupt 4
{


switch (SBUF)
{
case 0x01:P1=0X00; break;
case 0x02:P1=0XFF;break;
}
RI=0;//��λ
}

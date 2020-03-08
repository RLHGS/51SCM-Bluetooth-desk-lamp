#include<reg51.h>
//sbit led=P1^0;
bit flag = 0;
unsigned char fig = 0;
/********��������********/
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
case 0x01:flag = ~flag;break;      //������12���׵�
case 0x02:fig = 1;break;			//��ȫ��
case 0x03:fig = 2;break;			//��ȫ��
}
RI=0;//��λ
}

void LED1()   	//������12���׵�
{
	P0=0X00;
	P1=0Xf0;
	P2=0xff;
}

void LED2()			//��ȫ��
{
	P0=0Xff;
	P1=0Xff;
	P2=0xff;
	fig = 0;

}
void LED3()				//12��ů����
{
	P0=0Xff;
	P1=0X0f;
	P2=0x00;

}
void LED4()			//24����ȫ��
{
		P0=0X00;
		P1=0X00;
		P2=0x00;
}
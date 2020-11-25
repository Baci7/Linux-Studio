#include<stdio.h>

#define MAXLEN 10

typedef struct

{

    int data[MAXLEN];//������������ 

    int front,rear;//�����ͷ����β 

}csequeue;

   csequeue q;

void IniQueue()              //��ʼ������ 

{

   q.front=q.rear=MAXLEN-1;

}

void InQueue()              //��Ӻ��� 

{

   int x;

   printf("\n\t\t����һ����ӵ��������ݣ�");

   scanf("%d",&x);

if (q.front==(q.rear+1)%MAXLEN)

{

    printf("\n\t\t������������ӣ�\n");

    return;

}

    q.rear=(q.rear+1)%MAXLEN;

    q.data[q.rear]=x;

    printf("\n\t\t��ӳɹ�!\n");

}

void Outsequeue()                 //���Ӻ��� 

{

    if (q.front==q.rear)

{

    printf("\n\t\t�˶���Ϊ��!");

    return;

}                              //�ӿղ��ܳ��� 

else                                

{

    q.front=(q.front+1)%MAXLEN;

    printf("\n\t\t����Ԫ��Ϊ��%d\n",q.data[q.front]);      //�����ͷԪ�� 

    return;}

}
void ShowQueue()                   //��ʾ���� 

{

    int k=q.front;

if (k==q.rear)

{

    printf("\n\t\t�˶���Ϊ��!\n");

    return;

}

printf("\n\t\t�˶���Ԫ��Ϊ��");

do

{

    k=(k+1)%MAXLEN;

    printf("%4d",q.data[k]);

}while(k!=q.rear);

printf("\n");

}

int length()

{

    int k;

    k=(q.rear-q.front+MAXLEN)%MAXLEN;

    return k;

}

int main()

{

    int i=1;

    int choice;

    IniQueue();

while (i)

{

printf("\n\t\t                           ѭ������                             \n");

printf("\n\t\t******************************************************************");

printf("\n\t\t*                   1----------------��      ��                   ");

printf("\n\t\t*                   2----------------��      ��                   ");

printf("\n\t\t*                   3----------------��      ʾ                   ");

printf("\n\t\t*                   4----------------����г���                   ");

printf("\n\t\t*                   0----------------��      ��                   ");

printf("\n\t\t******************************************************************");

printf("\n\t\t������˵��ţ�");

scanf("%d",&choice);

switch(choice)

{

case 1:

   InQueue();

   break;

case 2:

   Outsequeue();

   break;

case 3:

   ShowQueue();

   break;

case 4:

   printf("\n\t\t���г���Ϊ��%d\n",length());

   break;

case 0:

   i=0;

   break;
}

}

}


#include<stdio.h>

#define MAXLEN 10

typedef struct

{

    int data[MAXLEN];//定义数据类型 

    int front,rear;//定义队头，队尾 

}csequeue;

   csequeue q;

void IniQueue()              //初始化队列 

{

   q.front=q.rear=MAXLEN-1;

}

void InQueue()              //入队函数 

{

   int x;

   printf("\n\t\t输入一个入队的整数数据：");

   scanf("%d",&x);

if (q.front==(q.rear+1)%MAXLEN)

{

    printf("\n\t\t队满，不能入队！\n");

    return;

}

    q.rear=(q.rear+1)%MAXLEN;

    q.data[q.rear]=x;

    printf("\n\t\t入队成功!\n");

}

void Outsequeue()                 //出队函数 

{

    if (q.front==q.rear)

{

    printf("\n\t\t此队列为空!");

    return;

}                              //队空不能出队 

else                                

{

    q.front=(q.front+1)%MAXLEN;

    printf("\n\t\t出队元素为：%d\n",q.data[q.front]);      //输出队头元素 

    return;}

}
void ShowQueue()                   //显示函数 

{

    int k=q.front;

if (k==q.rear)

{

    printf("\n\t\t此队列为空!\n");

    return;

}

printf("\n\t\t此队列元素为：");

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

printf("\n\t\t                           循环队列                             \n");

printf("\n\t\t******************************************************************");

printf("\n\t\t*                   1----------------进      队                   ");

printf("\n\t\t*                   2----------------出      队                   ");

printf("\n\t\t*                   3----------------显      示                   ");

printf("\n\t\t*                   4----------------求队列长度                   ");

printf("\n\t\t*                   0----------------返      回                   ");

printf("\n\t\t******************************************************************");

printf("\n\t\t请输入菜单号：");

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

   printf("\n\t\t队列长度为：%d\n",length());

   break;

case 0:

   i=0;

   break;
}

}

}


#include <stdio.h>
#define STACKMAX 100

typedef struct stacknode
{  int data;
   struct stacknode *next;
}stacknode;

typedef struct
{  stacknode *top;
}linkstack;


void push(linkstack *s,int x)   //进栈操作
{  stacknode *p=new stacknode;
   p->data=x;
   p->next=s->top;
   s->top=p;
}

int pop(linkstack *s)  //出栈操作
{  int x;
   stacknode *p=s->top;
   x=p->data;
   s->top=p->next;
   delete p;
   return x;
}

void showstack(linkstack *s)  //显示栈内容
{  stacknode *p=s->top;
   if (p==NULL)
	 printf("\n\t\t  栈为空   \n");
   else
   { printf("\n\t\t  栈元素为:  ");
     while(p!=NULL)
     {
		 printf("%d",p->data);
		 p=p->next;
	 }
	 printf("\n");
   }
}

void conversion(int n)   //二-----十进制转换
{  linkstack s;  //定义一个结构变量的同时其存储单元已确定
   int x;
   s.top=NULL;   //置栈空
   do
   { x=n%2;       //取余数
     n=n/2;       //取新的商
	 stacknode *p=new stacknode;  //申请新结点
	 p->next=s.top;
	 s.top=p;
	 s.top->data=x;  //余数进栈
   } while(n);

   printf("\n\t\t 转换后的二进制数值为:  ");
   while(s.top)
   { printf("%d",s.top->data);
     stacknode *p=s.top;
	 s.top=s.top->next;
	 delete p;       //出栈一个余数，收回一个结点
   }
   printf("\n");
   getchar();
}

int main()
{  linkstack *s=new linkstack;
   int i=1,j=1,choice,val,n;
   s->top=NULL;
   while(i)
   {
	   printf("\n");
	   printf("\n\t\t                   栈子系统                     ");
	   printf("\n\t\t************************************************");
	   printf("\n\t\t*          1----------------进栈               *");
	   printf("\n\t\t*          2----------------出栈               *");
	   printf("\n\t\t*          3----------------显示               *");
	   printf("\n\t\t*          4----------------数值转换           *");
	   printf("\n\t\t*          0----------------返回               *");
	   printf("\n\t\t************************************************");
	   printf("\n\t\t    请选择菜单号(0-----4):     ");
	   choice=getchar();
	   getchar();
	   switch (choice)
	   {
	      case '1':
			   j=1;
			   while(j)
			   {
				   printf("\n\t\t 输入一个整数 (0表示结束) 并按回车：");
				   scanf("%d",&val);
				   getchar();
				   if(val!=0)
					   push(s,val);
				   else
					   j=0;
			   };
			   break;
	      case '2':
	 	       if(s->top!=NULL)
				   printf("\n\t\t 出栈元素为:     %6d\n",pop(s) );
			   else
				   printf("\n\t\t 栈已空，不能出栈！     \n");
			   break;

	      case '3':
		       showstack(s);
			   break;
          case '4':
		       printf("\n\t\t 请输入一个十进制正整数: ");
			   scanf("%d",&n);
			   conversion(n);
			   break;
	      case '0':
		       i=0;
			   break;
	   }
   }
}


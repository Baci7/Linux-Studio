#include <stdio.h>
#define STACKMAX 100

typedef struct stacknode
{  int data;
   struct stacknode *next;
}stacknode;

typedef struct
{  stacknode *top;
}linkstack;


void push(linkstack *s,int x)   //��ջ����
{  stacknode *p=new stacknode;
   p->data=x;
   p->next=s->top;
   s->top=p;
}

int pop(linkstack *s)  //��ջ����
{  int x;
   stacknode *p=s->top;
   x=p->data;
   s->top=p->next;
   delete p;
   return x;
}

void showstack(linkstack *s)  //��ʾջ����
{  stacknode *p=s->top;
   if (p==NULL)
	 printf("\n\t\t  ջΪ��   \n");
   else
   { printf("\n\t\t  ջԪ��Ϊ:  ");
     while(p!=NULL)
     {
		 printf("%d",p->data);
		 p=p->next;
	 }
	 printf("\n");
   }
}

void conversion(int n)   //��-----ʮ����ת��
{  linkstack s;  //����һ���ṹ������ͬʱ��洢��Ԫ��ȷ��
   int x;
   s.top=NULL;   //��ջ��
   do
   { x=n%2;       //ȡ����
     n=n/2;       //ȡ�µ���
	 stacknode *p=new stacknode;  //�����½��
	 p->next=s.top;
	 s.top=p;
	 s.top->data=x;  //������ջ
   } while(n);

   printf("\n\t\t ת����Ķ�������ֵΪ:  ");
   while(s.top)
   { printf("%d",s.top->data);
     stacknode *p=s.top;
	 s.top=s.top->next;
	 delete p;       //��ջһ���������ջ�һ�����
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
	   printf("\n\t\t                   ջ��ϵͳ                     ");
	   printf("\n\t\t************************************************");
	   printf("\n\t\t*          1----------------��ջ               *");
	   printf("\n\t\t*          2----------------��ջ               *");
	   printf("\n\t\t*          3----------------��ʾ               *");
	   printf("\n\t\t*          4----------------��ֵת��           *");
	   printf("\n\t\t*          0----------------����               *");
	   printf("\n\t\t************************************************");
	   printf("\n\t\t    ��ѡ��˵���(0-----4):     ");
	   choice=getchar();
	   getchar();
	   switch (choice)
	   {
	      case '1':
			   j=1;
			   while(j)
			   {
				   printf("\n\t\t ����һ������ (0��ʾ����) �����س���");
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
				   printf("\n\t\t ��ջԪ��Ϊ:     %6d\n",pop(s) );
			   else
				   printf("\n\t\t ջ�ѿգ����ܳ�ջ��     \n");
			   break;

	      case '3':
		       showstack(s);
			   break;
          case '4':
		       printf("\n\t\t ������һ��ʮ����������: ");
			   scanf("%d",&n);
			   conversion(n);
			   break;
	      case '0':
		       i=0;
			   break;
	   }
   }
}


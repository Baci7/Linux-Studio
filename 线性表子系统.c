#include<stdio.h>
typedef struct linknode

{

char data;                                //数据是字符型 

struct linknode *next;

}linnode;

linnode *head;

int n;                                        //n为线性表长度 

void creatlist()

{

char x;

int z=1;

linnode *p,*s;

n=0;

head=(linnode*)malloc(sizeof(linnode));                    //先申请一个头结点 

p=head;                                                    //p也指向头结点 

printf("\n\t\t请逐个输入结点，以'x'为结束标记！\n");

printf("\n");

while(z)

{

printf("\n\t\t请输入1个字符数据，并按回车：\n");

scanf("\n%c",&x);

if(x!='x')                                         //后插法建单链表 

{

s=(linnode*)malloc(sizeof(linnode));

n++;

s->data=x;

p->next=s;

s->next=NULL;

p=s;

}

else z=0;                                        //遇'x'结束建表循环 

}

}

void inslist(int i,char x)                        //插入结点元素 

{

linnode *s,*p;

int j=0;

p=head;

while(p!=NULL  && j<i)                     //在结点范围之内并且j<i时循环执行   从头结点开始顺 

{

j++;

p=p->next;                                //后移指针 

}               //当j==i时循环结束 

if(p!=NULL)                     //如果p还在结点范围之内，肯定j==i  说明找到了位置为i的结点 

{

s=(linnode*)malloc(sizeof(linnode));

s->data=x;

s->next=p->next;

p->next=s;                           //将新结点插在位置为i的结点p的后面 

n++;                                    //表的长度加1 

}

else

printf("\n\t\t线性表为空或插入位置超界!\n");

}

void dellist(char x)                   //删除数据域为x的结点元素 
{
	linnode *p,*q;
	if(head==NULL)
	{
		printf("\n\t\t链表下溢！");
		return;
	}
	if(head->next==NULL)                //线性表只剩下头结点 
	{
		printf("\n\t\t线性表已经为空!");
		return;
	}
	q=head;                              //从头结点开始，q指向头结点 
	p=head->next;                        //p指向下一节点 
	while(p!=NULL&&p->data!=x)
	{
		q=p;
		p=p->next;
	}                              //顺链查找，直到p->data==x,循环终止。当前p即为数据域为x 的 
	if(p!=NULL)                      //如果p还在结点范围内，肯定p->data==x 
	{
		q->next=p->next;
		free p;
		n--;                           //表的长度减1 
		printf("\n\t\t结点%c已经被删除!",x); 
	}
	else
	printf("\n\t\t抱歉，没有找到你要删除的结点");
}
void showlist()                 //显示线性表 
{
	linnode *p=head;
	printf("\n\t\t显示线性表的所有元素：");
	if(head->next==NULL||p==NULL)
	printf("\n\t\t链表为空！");
	else
	{
		printf("\n\t\t");
		while(p->next!=NULL)
		{
			printf("%5c",p->next->data);
			p=p->next;
		}
	}
}
void searchlist(char x)
{
	linnode *p;
	int i;
	if(head=NULL)
	{
		printf("\n\t\t链表下溢！");
		return;
	}
	if(head->next==NULL)
	{
		printf("\n\t\t线性表为空，没有任何结点！");
		return;
	}
	i=1;
	p=head->next;             //从第一个结点开始 
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		i++;
	}
	if(p!=NULL)
	printf("\n\t\t在表的地%d的位上找到值为%c的结点！",i,x);
	else
	printf("\n\t\t抱歉，未找到值为%c的结点",x);
}
void main()
{
	int choice,i,j=1;
	char x;
	head=NULL;
	while(j)
	{
		printf("\n");
		printf("\n\t\t                    线性表子系统                         ");
		printf("\n\t\t*********************************************************");
		printf("\n\t\t*           1-------建表                                *");
		printf("\n\t\t*           2-------插入                                *");
		printf("\n\t\t*           3-------删除                                *");
		printf("\n\t\t*           4-------显示                                *");
		printf("\n\t\t*           5-------查找                                *");
		printf("\n\t\t*           6-------求表长                              *");
		printf("\n\t\t*           0-------返回                                *");
		printf("\n\t\t*********************************************************");
		printf("\n\t\t   请选择菜单号（0~6）：  ");
		scanf("%d",&choice);
		if(choice==1)         /*用if语句实现菜单选择*/ 
		creatlist();
		else if(choice==2)
		{
			printf("\n\t\t请输入插入的位置i和插入的数据（输入格式i,x):"); scanf("%d,%c",&i,&x);
			scanf("%d,%c",&i,&x);
			inslist(i,x);
		}
		else if(choce==3)
		{
			printf("\n\t\t 请输入要删除的数值：");
			scanf("\n%c",&x);
			dellist(x);
		}
		else if(choice==4)
		{
			if(head==NULL)
			printf("\n\t\t 请先建立线性表！");
			else
			showlist();
		}
		else if(choice==5)
		{
			printf("\n\t\t 请输入要查找的元素：");
			scanf("\n%c",&x);
			searchlist(x); 
		}
		else if(choice==6)
		    printf("\n\t\t 线性表的长度为：");
			else if(choice==0)
			j=0;
			else
			printf("\n\t\t 输入错误！请重新输入！"); 
		
	}
}

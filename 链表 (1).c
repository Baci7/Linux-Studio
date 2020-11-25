#include <stdio.h>
#include <malloc.h>

typedef struct linknode// 定义一个结构体 
{
char data;
struct linknode *next;
}linnode;

linnode *head; // 定义head指针指向结构体linknode 
int n; // n为线性表的长度 

void creatlist() // 创建链表 
{
char x;
int z=1; // 循环标记 
linnode *p,*s; // 结构体类型指针 
n=0; // 记录表长 
head=(linnode*)malloc(sizeof(linnode)); // 申请地址并让head指针指向此地址 
p=head; // 指针p指向头结点 
printf("\n\t\t请逐个输入结点，以'x'为结束标记！\n");
printf("\n");
while(z)
{
 printf("\n\t\t请输入%d个字符数据，并按回车:\n",n+1);
 printf("\t\t");
 scanf("%s",&x);
 if(x!='x')
 {
 s=(linnode*)malloc(sizeof(linnode));
 n++;
 s->data=x;
 p->next=s;
 s->next=NULL;
 p=s;
 }
 else z=0;
} 

}

void inslist(int i,char x) // 插入结点元素 
{
linnode *s,*p;
int j=1;
p=head;
while(p!=NULL && j<i) // 通过循环寻找要插入结点的前驱 
{
 j++;
 p=p->next; // 移动指针 
}
if(p!=NULL)
{
 s=(linnode*)malloc(sizeof(linnode)); // 创建新的结点 
 s->data=x;
 s->next=p->next; 
 p->next=s; // 将新的结点插在位置为i的结点前面 
 n++;  // 表长加1 
}
else printf("\n\t\t 链表为空或插入位置超界！\n"); 
}

void dellist(char x) // 删除数据域为x的结点元素
{
linnode *p,*q;
if(head==NULL)
{
 printf("\n\t\t链表下溢！");
 return; 
}
if(head->next==NULL) // 单项链表只剩头结点 
{
 printf("\n\t\t线性表已经为空！");
 return; 
}
q=head;
p=head->next;
while(p!=NULL && p->data!=x)
{
 q=p;
 p=p->next;
}
if(p!=NULL)
{
 q->next=p->next;
 free(p);
 n--;
 printf("\n\t\t 结点 %c 已经被删除！",x);
}
} 

void After_showlist() // 操作后显示链表
{
linnode *p=head;
printf("\n\t\t 操作后链表元素有：");
printf("\n\t\t");
while(p->next!=NULL)
{
 printf("%5c",p->next->data);
 p=p->next;
} 
} 

void showlist() // 显示链表
{
linnode *p=head;
printf("\n\t\t 显示链表的所有元素：");
if(head->next==NULL||p==NULL)
{
 printf("\n\t\t 链表为空");
}
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

void searchlist(char x) // 查找
{
linnode *p;
int i;
if(head==NULL)
{
 printf("\n\t\t 链表下溢!");
 return; 
}
if(head->next==NULL)
{
 printf("\n\t\t 线性表为空，没有任何结点！");
 return;
}
i=1;
p=head->next;
while(p!=NULL && p->data!=x)
{
 p=p->next;
 i++;
}
if(p!=NULL)
{
 printf("\n\t\t 在表的第 %d 位上找到值为 %c 的结点！",i,x);
}
else
{
 printf("\n\t\t 抱歉,未找到值为 %c 的结点！",x);
}
}

void Menu() // 功能菜单 
{
 printf("\n");
printf("\n\t\t               链表的各种操作                         "); 
printf("\n\t\t******************************************************");
printf("\n\t\t*           1------建表                              *"); 
printf("\n\t\t*           2------插入                              *");
printf("\n\t\t*           3------删除                              *");
printf("\n\t\t*           4------显示                              *");
printf("\n\t\t*           5------查找                              *");
printf("\n\t\t*           6------求表长                            *");
printf("\n\t\t*           0------返回                              *");
printf("\n\t\t******************************************************");
printf("\n\t\t 请选择菜单号(0-6): ");
}

void main()
{
int i,j=1;
char x,choice;
head=NULL;
while(j)
{ 
 Menu();
 scanf("%s",&choice);
 if(choice=='1')
 {
 creatlist();
 After_showlist();} 
 else if(choice=='2')
 {
 printf("\n\t\t? 请输入插入位置 i 和插入的数据(输入格式i,x):");
 scanf("%d,%c",&i,&x); 
 inslist(i,x);
 After_showlist();
 }

else if(choice=='3')
 {
 printf("\n\t\t 请输入要删除的数值:");
 scanf("\n%c",&x);
 dellist(x);
 After_showlist();
 }
 else if(choice=='4')
 {
 if(head==NULL)
 printf("\n\t\t? 请先建立线性表！");
 else
 showlist(); 
}
 else if(choice=='5')
 {
 printf("\n\t\t? 请输入要查找的元素:");
 scanf("\n%c",&x);
 searchlist(x); 
 }
 else if(choice=='6')
 {
 printf("\n\t\t? 线性表长度为: %d ",n);
 }
 else if(choice=='0')
 j=0;
 else
 printf("\n\t\t? 输入错误！ 请重新输入！");
}
}


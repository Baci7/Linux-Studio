#include <stdio.h>
#include <malloc.h>

typedef struct linknode// ����һ���ṹ�� 
{
char data;
struct linknode *next;
}linnode;

linnode *head; // ����headָ��ָ��ṹ��linknode 
int n; // nΪ���Ա�ĳ��� 

void creatlist() // �������� 
{
char x;
int z=1; // ѭ����� 
linnode *p,*s; // �ṹ������ָ�� 
n=0; // ��¼�� 
head=(linnode*)malloc(sizeof(linnode)); // �����ַ����headָ��ָ��˵�ַ 
p=head; // ָ��pָ��ͷ��� 
printf("\n\t\t����������㣬��'x'Ϊ������ǣ�\n");
printf("\n");
while(z)
{
 printf("\n\t\t������%d���ַ����ݣ������س�:\n",n+1);
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

void inslist(int i,char x) // ������Ԫ�� 
{
linnode *s,*p;
int j=1;
p=head;
while(p!=NULL && j<i) // ͨ��ѭ��Ѱ��Ҫ�������ǰ�� 
{
 j++;
 p=p->next; // �ƶ�ָ�� 
}
if(p!=NULL)
{
 s=(linnode*)malloc(sizeof(linnode)); // �����µĽ�� 
 s->data=x;
 s->next=p->next; 
 p->next=s; // ���µĽ�����λ��Ϊi�Ľ��ǰ�� 
 n++;  // ����1 
}
else printf("\n\t\t ����Ϊ�ջ����λ�ó��磡\n"); 
}

void dellist(char x) // ɾ��������Ϊx�Ľ��Ԫ��
{
linnode *p,*q;
if(head==NULL)
{
 printf("\n\t\t�������磡");
 return; 
}
if(head->next==NULL) // ��������ֻʣͷ��� 
{
 printf("\n\t\t���Ա��Ѿ�Ϊ�գ�");
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
 printf("\n\t\t ��� %c �Ѿ���ɾ����",x);
}
} 

void After_showlist() // ��������ʾ����
{
linnode *p=head;
printf("\n\t\t ����������Ԫ���У�");
printf("\n\t\t");
while(p->next!=NULL)
{
 printf("%5c",p->next->data);
 p=p->next;
} 
} 

void showlist() // ��ʾ����
{
linnode *p=head;
printf("\n\t\t ��ʾ���������Ԫ�أ�");
if(head->next==NULL||p==NULL)
{
 printf("\n\t\t ����Ϊ��");
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

void searchlist(char x) // ����
{
linnode *p;
int i;
if(head==NULL)
{
 printf("\n\t\t ��������!");
 return; 
}
if(head->next==NULL)
{
 printf("\n\t\t ���Ա�Ϊ�գ�û���κν�㣡");
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
 printf("\n\t\t �ڱ�ĵ� %d λ���ҵ�ֵΪ %c �Ľ�㣡",i,x);
}
else
{
 printf("\n\t\t ��Ǹ,δ�ҵ�ֵΪ %c �Ľ�㣡",x);
}
}

void Menu() // ���ܲ˵� 
{
 printf("\n");
printf("\n\t\t               ����ĸ��ֲ���                         "); 
printf("\n\t\t******************************************************");
printf("\n\t\t*           1------����                              *"); 
printf("\n\t\t*           2------����                              *");
printf("\n\t\t*           3------ɾ��                              *");
printf("\n\t\t*           4------��ʾ                              *");
printf("\n\t\t*           5------����                              *");
printf("\n\t\t*           6------���                            *");
printf("\n\t\t*           0------����                              *");
printf("\n\t\t******************************************************");
printf("\n\t\t ��ѡ��˵���(0-6): ");
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
 printf("\n\t\t? ���������λ�� i �Ͳ��������(�����ʽi,x):");
 scanf("%d,%c",&i,&x); 
 inslist(i,x);
 After_showlist();
 }

else if(choice=='3')
 {
 printf("\n\t\t ������Ҫɾ������ֵ:");
 scanf("\n%c",&x);
 dellist(x);
 After_showlist();
 }
 else if(choice=='4')
 {
 if(head==NULL)
 printf("\n\t\t? ���Ƚ������Ա�");
 else
 showlist(); 
}
 else if(choice=='5')
 {
 printf("\n\t\t? ������Ҫ���ҵ�Ԫ��:");
 scanf("\n%c",&x);
 searchlist(x); 
 }
 else if(choice=='6')
 {
 printf("\n\t\t? ���Ա���Ϊ: %d ",n);
 }
 else if(choice=='0')
 j=0;
 else
 printf("\n\t\t? ������� ���������룡");
}
}


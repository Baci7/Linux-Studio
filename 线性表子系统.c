#include<stdio.h>
typedef struct linknode

{

char data;                                //�������ַ��� 

struct linknode *next;

}linnode;

linnode *head;

int n;                                        //nΪ���Ա��� 

void creatlist()

{

char x;

int z=1;

linnode *p,*s;

n=0;

head=(linnode*)malloc(sizeof(linnode));                    //������һ��ͷ��� 

p=head;                                                    //pҲָ��ͷ��� 

printf("\n\t\t����������㣬��'x'Ϊ������ǣ�\n");

printf("\n");

while(z)

{

printf("\n\t\t������1���ַ����ݣ������س���\n");

scanf("\n%c",&x);

if(x!='x')                                         //��巨�������� 

{

s=(linnode*)malloc(sizeof(linnode));

n++;

s->data=x;

p->next=s;

s->next=NULL;

p=s;

}

else z=0;                                        //��'x'��������ѭ�� 

}

}

void inslist(int i,char x)                        //������Ԫ�� 

{

linnode *s,*p;

int j=0;

p=head;

while(p!=NULL  && j<i)                     //�ڽ�㷶Χ֮�ڲ���j<iʱѭ��ִ��   ��ͷ��㿪ʼ˳ 

{

j++;

p=p->next;                                //����ָ�� 

}               //��j==iʱѭ������ 

if(p!=NULL)                     //���p���ڽ�㷶Χ֮�ڣ��϶�j==i  ˵���ҵ���λ��Ϊi�Ľ�� 

{

s=(linnode*)malloc(sizeof(linnode));

s->data=x;

s->next=p->next;

p->next=s;                           //���½�����λ��Ϊi�Ľ��p�ĺ��� 

n++;                                    //��ĳ��ȼ�1 

}

else

printf("\n\t\t���Ա�Ϊ�ջ����λ�ó���!\n");

}

void dellist(char x)                   //ɾ��������Ϊx�Ľ��Ԫ�� 
{
	linnode *p,*q;
	if(head==NULL)
	{
		printf("\n\t\t�������磡");
		return;
	}
	if(head->next==NULL)                //���Ա�ֻʣ��ͷ��� 
	{
		printf("\n\t\t���Ա��Ѿ�Ϊ��!");
		return;
	}
	q=head;                              //��ͷ��㿪ʼ��qָ��ͷ��� 
	p=head->next;                        //pָ����һ�ڵ� 
	while(p!=NULL&&p->data!=x)
	{
		q=p;
		p=p->next;
	}                              //˳�����ң�ֱ��p->data==x,ѭ����ֹ����ǰp��Ϊ������Ϊx �� 
	if(p!=NULL)                      //���p���ڽ�㷶Χ�ڣ��϶�p->data==x 
	{
		q->next=p->next;
		free p;
		n--;                           //��ĳ��ȼ�1 
		printf("\n\t\t���%c�Ѿ���ɾ��!",x); 
	}
	else
	printf("\n\t\t��Ǹ��û���ҵ���Ҫɾ���Ľ��");
}
void showlist()                 //��ʾ���Ա� 
{
	linnode *p=head;
	printf("\n\t\t��ʾ���Ա������Ԫ�أ�");
	if(head->next==NULL||p==NULL)
	printf("\n\t\t����Ϊ�գ�");
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
		printf("\n\t\t�������磡");
		return;
	}
	if(head->next==NULL)
	{
		printf("\n\t\t���Ա�Ϊ�գ�û���κν�㣡");
		return;
	}
	i=1;
	p=head->next;             //�ӵ�һ����㿪ʼ 
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		i++;
	}
	if(p!=NULL)
	printf("\n\t\t�ڱ�ĵ�%d��λ���ҵ�ֵΪ%c�Ľ�㣡",i,x);
	else
	printf("\n\t\t��Ǹ��δ�ҵ�ֵΪ%c�Ľ��",x);
}
void main()
{
	int choice,i,j=1;
	char x;
	head=NULL;
	while(j)
	{
		printf("\n");
		printf("\n\t\t                    ���Ա���ϵͳ                         ");
		printf("\n\t\t*********************************************************");
		printf("\n\t\t*           1-------����                                *");
		printf("\n\t\t*           2-------����                                *");
		printf("\n\t\t*           3-------ɾ��                                *");
		printf("\n\t\t*           4-------��ʾ                                *");
		printf("\n\t\t*           5-------����                                *");
		printf("\n\t\t*           6-------���                              *");
		printf("\n\t\t*           0-------����                                *");
		printf("\n\t\t*********************************************************");
		printf("\n\t\t   ��ѡ��˵��ţ�0~6����  ");
		scanf("%d",&choice);
		if(choice==1)         /*��if���ʵ�ֲ˵�ѡ��*/ 
		creatlist();
		else if(choice==2)
		{
			printf("\n\t\t����������λ��i�Ͳ�������ݣ������ʽi,x):"); scanf("%d,%c",&i,&x);
			scanf("%d,%c",&i,&x);
			inslist(i,x);
		}
		else if(choce==3)
		{
			printf("\n\t\t ������Ҫɾ������ֵ��");
			scanf("\n%c",&x);
			dellist(x);
		}
		else if(choice==4)
		{
			if(head==NULL)
			printf("\n\t\t ���Ƚ������Ա�");
			else
			showlist();
		}
		else if(choice==5)
		{
			printf("\n\t\t ������Ҫ���ҵ�Ԫ�أ�");
			scanf("\n%c",&x);
			searchlist(x); 
		}
		else if(choice==6)
		    printf("\n\t\t ���Ա�ĳ���Ϊ��");
			else if(choice==0)
			j=0;
			else
			printf("\n\t\t ����������������룡"); 
		
	}
}

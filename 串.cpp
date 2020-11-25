#include<stdio.h>

#define MAXSIZE 100     /*˳�򴮴洢�ռ���ܷ�����*/

typedef struct          /*���ṹ����*/

{

    char ch[MAXSIZE];

    int len;

}string;

int strlength(string *s)/*�������*/

{

    int i=0;                       

    while(s->ch[i]!='\0')

    i++;

    s->len=i;

    return (s->len);

}

void creatstr(string *s)

{

    gets(s->ch);              /*����һ���´�*/

    s->len=strlength(s);

}

int  substring(string *s,string *sub,int pos,int len)/*���Ӵ�����*/

{

    int j;            

    if(pos<1  ||  pos>s->len  ||  len<1  ||  len>s->len-pos+1)

{

    sub->len=0;

    printf("��������!\n");

    return 0;

}

 else

{

    for(j=0;j<len;j++)

    sub->ch[j]=s->ch[pos+j-1];

    sub->ch[j]='\0';

    sub->len=len;

    return 1;

}

}

int strdelete(string *s,int i,int l) /*�ڴ�s��ɾ����ָ��λ��i��ʼ������j���ַ�*/

{

    int k;                 

if(i+l-1>s->len)

{

    printf("��Ҫɾ�����Ӵ�����!");

    return 0;

}

else

{

    for(k=i+l-1;k<s->len;k++,i++)

      s->ch[i-1]=s->ch[k];

    s->len=s->len-l;

    s->ch[s->len]='\0';

    return 1;

}

}

int strinsert(string *s,string *s1,int i) /*�ڴ�s�в����Ӵ�s1����*/

{

    int k;         

    if(i>s->len+1)

{

    printf("����λ�ô���!");

    return 0;

}

else if(s->len+s1->len>MAXSIZE)

{

    printf("�������ȳ����洢�ռ䳤��!");

    return 0;

}

else

{

    for(k=s->len-1;k>=i-1;k--)

     s->ch[s1->len+k]=s->ch[k];

    for(k=0;k<s1->len;k++)

     s->ch[i+k-1]=s1->ch[k];

    s->len=s->len+s1->len;

    s->ch[s->len]='\0';

    return 1;

}



}

int strindex(string *s,string *t) /*���Ķ�λ����*/

{

    int i=0,j=0,k;               

    while(i<s->len  &&  j<t->len)

{

if(s->ch[i]==t->ch[j])

{

    i++;

    j++;

}

else

{

    i=i-j+1;

    j=0;

}

}

if(j>=t->len)

    k=i-t->len+1;

else

    k=-1;

    return k;

}

int strcompare(string *s1,string *s2)

{

    int i=0,flag=0;             /*�������ж��Ƿ����*/

    while(s1->ch[i]!='\0'  &&  s2->ch[i]!='\0')

{

if(s1->ch[i]!=s2->ch[i])
{flag=1;break; }
else
i++; 
}
if(flag==0&&s1->len==s2->len)/*����������ͬ�������ַ�����ͬ���������*/ 
return 0;
else
return s1->ch[i]-s2->ch[i];
}
int strcat(string *s,string *t)  /* �������Ӻ��� */
{
	int i,flag;/*����t�����ڴ�s�ĺ���*/
	if(s->len+t->len<=MAXSIZE)/*���Ӻ󴮳�С��MAXLEN*/
	{
		for(i=s->len;i<s->len+t->len;i++)
		s->ch[i]=t->ch[i-s->len];
		s->ch[i]='\0';
		s->len+=t->len;
		flag=1;
	 } 
	 else if(s->len<MAXSIZE)
	 {/*���Ӻ󴮳�����MAXLEN,����s�ĳ���С��MAXLEN�������Ӻ�t���ǲ����ַ����б�����*/ 
	 	for(i=s->len;i<MAXSIZE;i++)
	 	s->ch[i]=t->ch[i-s->len];
	 	s->len=MAXSIZE;
	 	flag=0;
	 }
	 else
	 flag=0;/*��s�ĳ��ȵ���MAXLEN����t��������*/
	 return(flag); 
}
void strreplace(string *s,string *t,string *v)/*�Ӵ��滻����*/ 
{
	int i,m,n,p,q;
	n=s->len;
	m=t->len;
	q=v->len;
	p=1;
	do
	{
		i=strindex(s,t);/*���ö�λ�����õ��Ӵ�t������s��λ��*/
		if(i!=-1)
		{
			strdelete(s,i,m);/*����ɾ���Ӵ�����ɾ�����Ӵ�t*/
			strinsert(s,v,i);/*���ò����Ӵ����������Ӵ�v*/
			 p=i+q;
			 s->len=s->len+q-m;/*�޸�����s�ĳ���*/
			 n=s->len; 	 
		 } 
	}while((p<=n-m+1)&&(i!=-1));
}
void menustring()
{/*��ʾ�˵��Ӻ���*/
    printf("\n                  ����ϵͳ"); 
    printf("\n================================================");
    printf("\n|              1-----�����´�����ʾ�ô�����    |");
    printf("\n|              2-----���Ӵ�                    |");
    printf("\n|              3-----ɾ���Ӵ�                  |");
    printf("\n|              4-----�����Ӵ�                  |");
    printf("\n|              5-----�����Ӵ�                  |");
    printf("\n|              6-----�Ƚ��������Ĵ�С          |");
    printf("\n|              7-----����������                |");
    printf("\n|              8-----�Ӵ��滻                  |");
    printf("\n|              0-----����                      |"); 
    printf("\n================================================");
    printf("\n������˵��ţ�0-8����");
}
main()
{
	int i,len,flag;
	string x,y,z;
	string *s=&x,*s1=&y,*s2=&z;
	char ch1,ch2,a;
	ch1='y';
	while(ch1=='y'||ch1=='Y')
	{
		menustring();
		scanf("%c",&ch2);
		getchar();
		switch(ch2)
		{
			case '1':
				printf("������һ���ַ�����");
				creatstr(s);
				printf("�ô�ֵΪ��");
				if(s->ch[0]=='\0')
				printf("�մ�");
				else
				{
					puts(s->ch);
					printf("�ô�����Ϊ��%d",s->len);
				}
				break;
				case '2':
					printf("������ӵڼ����ַ���ʼ���Ӵ���");
					scanf("%d",&i);
					printf("������ȡ�����Ӵ����ȣ�");
					scanf("%d",&len);
					flag=substring(s,s1,i,len);
					if(flag)
					{
						printf("���Ӵ��ɹ���ԭ������Ϊ��");
						puts(s->ch);
						printf("�����Ӵ�Ϊ��");
						puts(s1->ch);
						
					 } 
					 else
					 printf("���Ӵ�ʧ��!");
					 break;
					 case '3':
					 	printf("������Ҫɾ�����ִ�����ʼλ�ã�");
					 	scanf("%d",&i);
					 	printf("������Ҫɾ�����ִ��ĳ��ȣ�");
					 	scanf("%d",&len);
					 	printf("ԭ����Ϊ��");
					 	puts(s->ch);
					 	if(flag=strdelete(s,i,len))
					 	{
					 		printf("ɾ���Ӵ��ɹ���ɾ������µĴ�Ϊ��");
					 		puts(s->ch);
						 }
						 else
						 printf("ɾ���Ӵ�ʧ�ܣ�");
						 break;
						 case '4':
						 	printf("������Ҫ�����Ӵ��������е�λ�ã�");
						 	scanf("%d",&i);
						 	printf("������һ���Ӵ���");
						    getchar();
						 	creatstr(s1);
						 	printf("ԭ������Ϊ��");
						 	puts(s->ch);
						 	if(flag=strinsert(s,s1,i))
						 	{printf("�����Ӵ��ɹ�!�������µ�����Ϊ��");
						 	puts(s->ch);
							 }else
							 printf("�����Ӵ�ʧ��");
							 break;
							 case '5':
							 	printf("�������һ������");
							 	creatstr(s);
							 	printf("������ڶ�����");
							 	creatstr(s1);
								  i=strindex(s,s1);
								  if(i==-1)
								printf("����ʧ�ܣ�������û�и��Ӵ���");
								else
								printf("���ҳɹ������Ӵ��������е�һ�γ��ֵ�λ��Ϊ%d��",i);
								break;
								case '6':
								printf("�������һ������");
								creatstr(s);
								printf("������ڶ�������");
								creatstr(s1) ;
								flag=strcompare(s,s1);
								if(flag>0)
								printf("��һ������");
								else if(flag<0)
								printf("�ڶ�������");
								else
								printf("��������ȣ�");
								break;
								case '7':
									printf("�������һ������");
									creatstr(s);
									printf("������ڶ�������");
									creatstr(s1);
									 flag=strcat(s,s1);
									 if(flag)
									 {printf("�����Ժ���´�ֵΪ��");
									 puts(s->ch); 
									 }
									 else
									 printf("����ʧ�ܣ�");
									 break;
									 case '8':
									 	printf("������������");
									 	creatstr(s);
									 	printf("���������������ҵ��Ӵ���");
									 	creatstr(s1);
									 	printf("������Ҫ�滻���Ӵ���");
									 	creatstr(s2);
									 	strreplace(s,s1,s2);
									 	printf("�滻�������Ϊ��");
										 puts(s->ch) ;
										 break;
										 case '0':
										 	ch1='n';
										 	break;
										 	default:
										 		printf("��������������0-9����ѡ��");
		if(ch2!='0')
		{printf("\n���س�����������������������˵���");
		a=getchar();
		if(a!='\xA')
		{
			getchar();
			ch1='n';
		}
		}
	}
}
}
  



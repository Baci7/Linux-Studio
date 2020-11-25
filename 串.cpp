#include<stdio.h>

#define MAXSIZE 100     /*顺序串存储空间的总分配量*/

typedef struct          /*串结构定义*/

{

    char ch[MAXSIZE];

    int len;

}string;

int strlength(string *s)/*求表串长度*/

{

    int i=0;                       

    while(s->ch[i]!='\0')

    i++;

    s->len=i;

    return (s->len);

}

void creatstr(string *s)

{

    gets(s->ch);              /*建立一个新串*/

    s->len=strlength(s);

}

int  substring(string *s,string *sub,int pos,int len)/*求子串函数*/

{

    int j;            

    if(pos<1  ||  pos>s->len  ||  len<1  ||  len>s->len-pos+1)

{

    sub->len=0;

    printf("参数错误!\n");

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

int strdelete(string *s,int i,int l) /*在串s中删除从指定位置i开始连续的j个字符*/

{

    int k;                 

if(i+l-1>s->len)

{

    printf("所要删除的子串超界!");

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

int strinsert(string *s,string *s1,int i) /*在串s中插入子串s1函数*/

{

    int k;         

    if(i>s->len+1)

{

    printf("插入位置错误!");

    return 0;

}

else if(s->len+s1->len>MAXSIZE)

{

    printf("两串长度超过存储空间长度!");

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

int strindex(string *s,string *t) /*串的定位函数*/

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

    int i=0,flag=0;             /*两个串判断是否相等*/

    while(s1->ch[i]!='\0'  &&  s2->ch[i]!='\0')

{

if(s1->ch[i]!=s2->ch[i])
{flag=1;break; }
else
i++; 
}
if(flag==0&&s1->len==s2->len)/*两串长度相同且所有字符都相同，两串相等*/ 
return 0;
else
return s1->ch[i]-s2->ch[i];
}
int strcat(string *s,string *t)  /* 串的连接函数 */
{
	int i,flag;/*将串t连接在串s的后面*/
	if(s->len+t->len<=MAXSIZE)/*连接后串长小于MAXLEN*/
	{
		for(i=s->len;i<s->len+t->len;i++)
		s->ch[i]=t->ch[i-s->len];
		s->ch[i]='\0';
		s->len+=t->len;
		flag=1;
	 } 
	 else if(s->len<MAXSIZE)
	 {/*连接后串长大于MAXLEN,但串s的长度小于MAXLEN，即连接后串t的那部分字符序列被舍弃*/ 
	 	for(i=s->len;i<MAXSIZE;i++)
	 	s->ch[i]=t->ch[i-s->len];
	 	s->len=MAXSIZE;
	 	flag=0;
	 }
	 else
	 flag=0;/*串s的长度等于MAXLEN，串t不被连接*/
	 return(flag); 
}
void strreplace(string *s,string *t,string *v)/*子串替换函数*/ 
{
	int i,m,n,p,q;
	n=s->len;
	m=t->len;
	q=v->len;
	p=1;
	do
	{
		i=strindex(s,t);/*调用定位函数得到子串t在主串s的位置*/
		if(i!=-1)
		{
			strdelete(s,i,m);/*调用删除子串函数删除该子串t*/
			strinsert(s,v,i);/*调用插入子串函数插入子串v*/
			 p=i+q;
			 s->len=s->len+q-m;/*修改主串s的长度*/
			 n=s->len; 	 
		 } 
	}while((p<=n-m+1)&&(i!=-1));
}
void menustring()
{/*显示菜单子函数*/
    printf("\n                  串子系统"); 
    printf("\n================================================");
    printf("\n|              1-----建立新串并显示该串长度    |");
    printf("\n|              2-----求子串                    |");
    printf("\n|              3-----删除子串                  |");
    printf("\n|              4-----插入子串                  |");
    printf("\n|              5-----查找子串                  |");
    printf("\n|              6-----比较两个串的大小          |");
    printf("\n|              7-----连接两个串                |");
    printf("\n|              8-----子串替换                  |");
    printf("\n|              0-----返回                      |"); 
    printf("\n================================================");
    printf("\n请输入菜单号（0-8）：");
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
				printf("请输入一个字符串：");
				creatstr(s);
				printf("该串值为：");
				if(s->ch[0]=='\0')
				printf("空串");
				else
				{
					puts(s->ch);
					printf("该串长度为：%d",s->len);
				}
				break;
				case '2':
					printf("请输入从第几个字符开始求子串：");
					scanf("%d",&i);
					printf("请输入取出的子串长度：");
					scanf("%d",&len);
					flag=substring(s,s1,i,len);
					if(flag)
					{
						printf("求子串成功，原来主串为：");
						puts(s->ch);
						printf("所得子串为：");
						puts(s1->ch);
						
					 } 
					 else
					 printf("求子串失败!");
					 break;
					 case '3':
					 	printf("请输入要删除的字串的起始位置：");
					 	scanf("%d",&i);
					 	printf("请输入要删除的字串的长度：");
					 	scanf("%d",&len);
					 	printf("原来串为：");
					 	puts(s->ch);
					 	if(flag=strdelete(s,i,len))
					 	{
					 		printf("删除子串成功，删除后的新的串为：");
					 		puts(s->ch);
						 }
						 else
						 printf("删除子串失败！");
						 break;
						 case '4':
						 	printf("请输入要插入子串在主串中的位置：");
						 	scanf("%d",&i);
						 	printf("请输入一个子串：");
						    getchar();
						 	creatstr(s1);
						 	printf("原来主串为：");
						 	puts(s->ch);
						 	if(flag=strinsert(s,s1,i))
						 	{printf("插入子串成功!插入后的新的主串为：");
						 	puts(s->ch);
							 }else
							 printf("插入子串失败");
							 break;
							 case '5':
							 	printf("请输入第一个串：");
							 	creatstr(s);
							 	printf("请输入第二个串");
							 	creatstr(s1);
								  i=strindex(s,s1);
								  if(i==-1)
								printf("查找失败，主串中没有该子串！");
								else
								printf("查找成功，该子串在主串中第一次出现的位置为%d。",i);
								break;
								case '6':
								printf("请输入第一个串：");
								creatstr(s);
								printf("请输入第二个串：");
								creatstr(s1) ;
								flag=strcompare(s,s1);
								if(flag>0)
								printf("第一个串大！");
								else if(flag<0)
								printf("第二个串大！");
								else
								printf("两个串相等！");
								break;
								case '7':
									printf("请输入第一个串：");
									creatstr(s);
									printf("请输入第二个串：");
									creatstr(s1);
									 flag=strcat(s,s1);
									 if(flag)
									 {printf("连接以后的新串值为：");
									 puts(s->ch); 
									 }
									 else
									 printf("连接失败！");
									 break;
									 case '8':
									 	printf("请输入主串：");
									 	creatstr(s);
									 	printf("请输入在主串查找的子串：");
									 	creatstr(s1);
									 	printf("请输入要替换的子串：");
									 	creatstr(s2);
									 	strreplace(s,s1,s2);
									 	printf("替换后的主串为：");
										 puts(s->ch) ;
										 break;
										 case '0':
										 	ch1='n';
										 	break;
										 	default:
										 		printf("输入有误，请输入0-9进行选择！");
		if(ch2!='0')
		{printf("\n按回车键继续，按任意键返回主菜单！");
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
  



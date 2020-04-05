#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define ERROR 0
typedef char ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

int InitStack(LinkStack **s)
{
	*s=(LinkStack*)malloc(sizeof(LinkStack));
	if(s==NULL)
	{
		return ERROR;
	}
	(*s)->top=NULL;
	(*s)->count=0;
	return SUCCESS;
}

void Push(LinkStack*s,char e)
{
	if(s==NULL)
	{
		return;
	}
	StackNode *p1=(StackNode*)malloc(sizeof(StackNode));
	p1->data = e;
	p1->next =s->top;
	s->top = p1;
	s->count++;

}

int judge(char *a)
{	int i=0;int num1;int num2;
	while(a[i]!='\0')
	{
		if(a[i]==a[i+1])return ERROR;
		if(a[i]<40||a[i]>57)return ERROR;
		if(a[i]==44||a[i]==46)return ERROR;
		if(a[i]==40)num1++;
		if(a[i]==41)num2++;
	}
	if(num1!=num2)return ERROR;
	return SUCCESS;
}
char GetChar(int s)
{
	return s+'0';
}

int GetNum(char s)
{
	return s-'0';
}



char GetTop(LinkStack*s)
{
	if(s->top==NULL)
	{
		return ERROR;
	}
	return (s->top->data);
}

int Priority (char ch)
{
	switch(ch)
	{
	case '(':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}
char Pop(LinkStack*s)
{
	char e;
	if(s->top == NULL)
	{
		return ERROR;
	}
	StackNode*p=s->top;
	e=p->data;
	s->top = p->next;
	free(p);
	s->count--;
	return e;
}

int main()
{	LinkStack* s=NULL;
	char a[100] = {0};
	char b[100] = {0};
	int i=0,j=0,num=0;
	int flag = 0;
	int run=1;
   InitStack(&s);

   //get********************************************************************************************************
   while(run)
	{
	printf("输入0退出程序\n输入1启动四则个位数运算器\n");
	if(!scanf("%d",&run)){rewind(stdin);continue;}

	//防止输入错误
	if(run==1){

	printf("输入算术式子:\n");
	scanf("%s",a);//防止乱七八糟的字符*************************************
	if(!judge(a)){printf("含有非法字符！不能同时出现两个相连的字符！\n");continue;}
   //change
   while(a[i]!='\0')
   {
   	flag=0;
   	if(a[i]>='0'&&a[i]<='9'&&flag!=1)//judge num
	{
		b[j++]=a[i];
		flag=1;


	}
	if(a[i]=='('&&flag!=1)//left
	{
		Push(s,a[i]);
		flag=1;

	}
	if(a[i]==')'&&flag!=1)//right
	{
		while(GetTop(s)!='(')
		{
			b[j++]=Pop(s);
		}
		Pop(s);
		flag=1;
	}
	if((a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')&&flag!=1)//otr
	{
	if(Priority(a[i])>Priority(GetTop(s))||GetTop(s)=='(')
	{
		Push(s,a[i]);
	}
	else
	{
		b[j++]=Pop(s);
		while(Priority(a[i])<=Priority(GetTop(s)))
		{
			b[j++]=Pop(s);
		}
		Push(s,a[i]);
	}
	flag=1;
	}
	i++;
   }

	while(s->count!=0)
	{
		b[j++]=Pop(s);
	}
	printf("后缀表达式：%s\n",b);

	//计算************************************************************************************************************
	i=0;
	while(b[i]!='\0')
	{	flag=0;
		if(b[i]>='0'&&b[i]<='9'&&flag!=1)
		{
			Push(s,b[i]);
			num++;
			flag=1;

		}
		if((b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/')&&flag!=1)
		{
			if(b[i]=='+')
			{
				num=GetNum(Pop(s))+GetNum(Pop(s));
				Push(s,GetChar(num));
			}

			if(b[i]=='-')
			{
				num=GetNum(Pop(s))-GetNum(Pop(s));
				if(num<0)num=-1*num;
				Push(s,GetChar(num));

			}

			if(b[i]=='*')
			{
				num=GetNum(Pop(s))*GetNum(Pop(s));
				Push(s,GetChar(num));
			}

			if(b[i]=='/')
			{

				num=GetNum(Pop(s));
				j=GetNum(Pop(s));
				if(num<j) {num=num^j;j=num^j;num=num^j;}
				num=num/j;
				Push(s,GetChar(num));
			}

		}
		i++;
	}
	num=GetNum(Pop(s));
	printf("结果是%d\n",num);

	}
	rewind(stdin);



	}
 return 0;
}

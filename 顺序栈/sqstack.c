#include"../QG训练营第二次培训/栈以及栈的应用/栈/代码和头文件/head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>


Status initStack(SqStack *s,int sizes)//初始化栈
{
	if(s==NULL)return ERROR;
	s->elem=(ElemType*)malloc(sizeof(int)*sizes);
	s->top=-1;
	s->size=sizes;
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if(s->top==-1) return SUCCESS;
	return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
	if(s->top==-1) return ERROR;
	*e=s->elem[s->top];
	return SUCCESS;
}
Status clearStack(SqStack *s)//清空栈
{
	if(s->top==-1)return ERROR;
	s->top=-1;return SUCCESS;
}
Status destroyStack(SqStack *s)//销毁栈
{
	if(s==NULL)return ERROR;
	s->top=-1;
	free(s->elem);
	s->size=0;
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)//检测栈长度
{
	if(s==NULL) return ERROR;
	printf("栈长%d\n",s->top+1);
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)//入栈
{
	if(s->size==1+s->top) return ERROR;
	s->top+=1;
	s->elem[s->top]=data;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)//出栈
{
	if(s->top==-1) return ERROR;
	*data=s->elem[s->top];
	s->top-=1;
	return SUCCESS;
}

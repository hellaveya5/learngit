#include"../QGѵ��Ӫ�ڶ�����ѵ/ջ�Լ�ջ��Ӧ��/ջ/�����ͷ�ļ�/head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>


Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	if(s==NULL)return ERROR;
	s->elem=(ElemType*)malloc(sizeof(int)*sizes);
	s->top=-1;
	s->size=sizes;
	return SUCCESS;
}
Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1) return SUCCESS;
	return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	if(s->top==-1) return ERROR;
	*e=s->elem[s->top];
	return SUCCESS;
}
Status clearStack(SqStack *s)//���ջ
{
	if(s->top==-1)return ERROR;
	s->top=-1;return SUCCESS;
}
Status destroyStack(SqStack *s)//����ջ
{
	if(s==NULL)return ERROR;
	s->top=-1;
	free(s->elem);
	s->size=0;
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)//���ջ����
{
	if(s==NULL) return ERROR;
	printf("ջ��%d\n",s->top+1);
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if(s->size==1+s->top) return ERROR;
	s->top+=1;
	s->elem[s->top]=data;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(s->top==-1) return ERROR;
	*data=s->elem[s->top];
	s->top-=1;
	return SUCCESS;
}

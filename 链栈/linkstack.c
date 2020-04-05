#include"../QGѵ��Ӫ�ڶ�����ѵ/ջ�Լ�ջ��Ӧ��/ջ/�����ͷ�ļ�/head/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
Status initLStack(LinkStack *s)//��ʼ��ջ
{	if(s==NULL)return ERROR;

        s->count=0;

        return SUCCESS;
}
Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{	if(s->top!=NULL)return ERROR;
	return SUCCESS;

}
Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(s->top==NULL)return ERROR;
	*e=s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack *s)//���ջ
{

	if(s->top==NULL)return ERROR;
	LinkStack*p1;
	p1=s;
	while(s->top->next!=NULL){
	s->top=s->top->next;
	free(p1);
	}
	free(s->top);
	s->count=0;
	return SUCCESS;


}
Status destroyLStack(LinkStack *s)//����ջ
{	if(s==NULL)return ERROR;
        clearLStack(s);
        free(s);
        return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)//���ջ����
{	if(s==NULL)return ERROR;
        *length=s->count;
        printf("ջ��%d\n",*length);
        return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
        if(s==NULL)return ERROR;
        if(s->top==NULL)
	{s->top=(StackNode*)malloc(sizeof(StackNode));
        s->top->data=data;
        s->count+=1;
        s->top->next=NULL;
	}
	else {
		StackNode *p1=(StackNode*)malloc(sizeof(StackNode));
		p1->data=data;
		p1->next=s->top;
		s->top=p1;
		s->count+=1;

	}
        return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	if(s->top==NULL)return ERROR;
	StackNode *p1;
	p1=s->top;
	*data=p1->data;
	s->top=s->top->next;
	free(p1);
	s->count-=1;
	return SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include"../QGѵ��Ӫ�ڶ�����ѵ/ջ�Լ�ջ��Ӧ��/ջ/�����ͷ�ļ�/head/LinkStack.h"
int menu(LinkStack *s)
{
	int num=9;
	printf("************��ջ*************\n");
	printf("1.��ʼ����ջ\n");
	if(s!=NULL)
	{
		printf("2.�ж�ջ�Ƿ�Ϊ��\n");
		printf("3.�õ�ջ��Ԫ��\n");
		printf("4.��ջ\n");
		printf("5.��ջ\n");
		printf("6.���ջ����\n");
		printf("7.����ջ\n");
		printf("8.���ջ\n");
	}
	printf("0.exit\n");
	printf("*******************************\n");
	scanf("%d",&num);
	if(s==NULL&&num!=0&&num!=1)
		return 9;
	return num;
}
int main()
{	int e;
	LinkStack *s;
	s=NULL;
	int run=9;
    while(run)
	switch(run=menu(s))
    {
    	case 0:printf("�˳�\n");break;
	case 1:{
		if(s!=NULL){printf("�������ٴ���\n");break;}
		s=(LinkStack*)malloc(sizeof(LinkStack));
		s->top=NULL;
		if(!initLStack(s)){printf("�������ٴ���\n");break;}
		printf("�����ɹ�\n");break;
	}

	case 2:{
		if(!isEmptyLStack(s)){printf("���ǿյ�\n");break;}
		printf("�յ�\n");break;
	}
	case 3:{

                if(!getTopLStack(s,&e)){printf("��\n");break;}
		printf("ջ��Ԫ��%d\n",e);break;
	}
	case 4:{
		e=0;
		if(!popLStack(s,&e)){printf("��ջ\n");break;}
		printf("�ɹ���ջ%d\n",e);break;

	}
	case 5:{
		e=0;
		printf("��������\n");
		if(!scanf("%d",&e)){printf("����Ĳ�������\n");break;}
		if(pushLStack(s,e)){printf("%d�ɹ���ջ\n",e);break;}
		printf("��ô�ͻ���ջʧ���أ�����\n");break;
	}
	case 6:{
		e=0;
		LStackLength(s,&e);break;

	}
	case 7:{
		destroyLStack(s);printf("�ݻ�ջ�ɹ�\n");s=NULL;break;
	}
	case 8:{
		if(!clearLStack(s)){printf("�Ѿ��ǿ�ջ\n");break;}
			printf("��ջ�ɹ�\n");break;
	}
	default: rewind(stdin);printf("��������\n");break;
    }
    return 0;
}

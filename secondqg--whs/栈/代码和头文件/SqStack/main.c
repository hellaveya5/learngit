#include<stdio.h>
#include<stdlib.h>
#include"../QGѵ��Ӫ�ڶ�����ѵ/ջ�Լ�ջ��Ӧ��/ջ/�����ͷ�ļ�/head/SqStack.h"
int menu(SqStack *s)
{	int num=9;
	printf("************˳��ջ************\n");
	printf("1.��ʼջ\n");
	if(s!=NULL)
	{
		printf("2.��ջ\n");
		printf("3.��ջ\n");
		printf("4.�ж�Ϊ��\n");
		printf("5.�õ�ջ��\n");
		printf("6.���ջ\n");
		printf("7.����ջ\n");
		printf("8.��ⳤ��\n");
	}
	printf("0.�˳�����\n");
	printf("*****************************\n");
	printf("����Ҫ�Ĺ���\n");
	scanf("%d",&num);
	if(s==NULL&&num!=0&&num!=1)
		return 9;
	return num;
}

int main (){
	SqStack *s;
	s=NULL;
	int run=1;
	int sizes=0;
	while(run)
	{
		switch(run=menu(s))
		{
			case 0: printf("�˳�����\n");break;

			case 1:
				{
				printf("ջ����\n");
				if(!scanf("%d",&sizes)){printf("��������\n");break;}
				s=(SqStack*)malloc(sizeof(SqStack));
				if(!initStack(s,sizes)){printf("�������ٳ�ʼ��\n");break;}
				printf("��ʼ���ɹ�%d����ջ\n",sizes);break;
			}
			case 2:
				{
				int e;
				printf("��ջ��ֵ�ǣ�\n");
				if(!scanf("%d",&e)){printf("����Ĳ�������\n");break;}
                                if(!pushStack(s,e)){printf("ʧ��\n");break;}
                                printf("�ɹ�\n");break;
			}
			case 3: {
				int e;
				if(!popStack(s,&e)){printf("ʧ��\n");break;}
                                printf("�ɹ���ջ,ջֵΪ%d\n",e);
                                break;
			}
			case 4: {
				if(!isEmptyStack(s)){printf("���ǿյ�\n");break;}
				printf("�յ�\n");break;
			}
			case 5 :{
				int e=0 ;
				if(getTopStack(s,&e)){printf("�õ�ջ��%d\n",e);break;}
				printf("�Ѿ��ǿյ�ջ\n");break;
			}
                        case 6: {
				if(!clearStack(s)){printf("�Ѿ��ǿյ�ջ\n");break;}
				printf("����ɹ� \n");break;
                        }
			case 7: {
				if(!destroyStack(s)){printf("����ʧ��\n");break;}
				printf("���ٳɹ�\n");
				free(s);
				s=NULL;
				break;
			}
                        case 8: {
                        	int *len=&s->top;
                        	stackLength(s,len);break;
                        }
                        default: rewind(stdin);
				printf("��������\n");break;
			}

	}

return 0;

}

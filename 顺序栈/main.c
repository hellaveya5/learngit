#include<stdio.h>
#include<stdlib.h>
#include"../QG训练营第二次培训/栈以及栈的应用/栈/代码和头文件/head/SqStack.h"
int menu(SqStack *s)
{	int num=9;
	printf("************顺序栈************\n");
	printf("1.初始栈\n");
	if(s!=NULL)
	{
		printf("2.入栈\n");
		printf("3.出栈\n");
		printf("4.判断为空\n");
		printf("5.得到栈顶\n");
		printf("6.清空栈\n");
		printf("7.销毁栈\n");
		printf("8.检测长度\n");
	}
	printf("0.退出程序\n");
	printf("*****************************\n");
	printf("你想要的功能\n");
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
			case 0: printf("退出程序\n");break;

			case 1:
				{
				printf("栈长？\n");
				if(!scanf("%d",&sizes)){printf("不是数字\n");break;}
				s=(SqStack*)malloc(sizeof(SqStack));
				if(!initStack(s,sizes)){printf("先销毁再初始化\n");break;}
				printf("初始化成功%d长的栈\n",sizes);break;
			}
			case 2:
				{
				int e;
				printf("入栈数值是？\n");
				if(!scanf("%d",&e)){printf("输入的不是数字\n");break;}
                                if(!pushStack(s,e)){printf("失败\n");break;}
                                printf("成功\n");break;
			}
			case 3: {
				int e;
				if(!popStack(s,&e)){printf("失败\n");break;}
                                printf("成功出栈,栈值为%d\n",e);
                                break;
			}
			case 4: {
				if(!isEmptyStack(s)){printf("不是空的\n");break;}
				printf("空的\n");break;
			}
			case 5 :{
				int e=0 ;
				if(getTopStack(s,&e)){printf("得到栈顶%d\n",e);break;}
				printf("已经是空的栈\n");break;
			}
                        case 6: {
				if(!clearStack(s)){printf("已经是空的栈\n");break;}
				printf("清除成功 \n");break;
                        }
			case 7: {
				if(!destroyStack(s)){printf("销毁失败\n");break;}
				printf("销毁成功\n");
				free(s);
				s=NULL;
				break;
			}
                        case 8: {
                        	int *len=&s->top;
                        	stackLength(s,len);break;
                        }
                        default: rewind(stdin);
				printf("重新输入\n");break;
			}

	}

return 0;

}

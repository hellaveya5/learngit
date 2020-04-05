#include <stdio.h>
#include <stdlib.h>
#include"../QG训练营第二次培训/栈以及栈的应用/栈/代码和头文件/head/LinkStack.h"
int menu(LinkStack *s)
{
	int num=9;
	printf("************链栈*************\n");
	printf("1.初始化链栈\n");
	if(s!=NULL)
	{
		printf("2.判断栈是否为空\n");
		printf("3.得到栈顶元素\n");
		printf("4.出栈\n");
		printf("5.入栈\n");
		printf("6.检测栈长度\n");
		printf("7.销毁栈\n");
		printf("8.清空栈\n");
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
    	case 0:printf("退出\n");break;
	case 1:{
		if(s!=NULL){printf("先销毁再创建\n");break;}
		s=(LinkStack*)malloc(sizeof(LinkStack));
		s->top=NULL;
		if(!initLStack(s)){printf("先销毁再创建\n");break;}
		printf("创建成功\n");break;
	}

	case 2:{
		if(!isEmptyLStack(s)){printf("不是空的\n");break;}
		printf("空的\n");break;
	}
	case 3:{

                if(!getTopLStack(s,&e)){printf("空\n");break;}
		printf("栈顶元素%d\n",e);break;
	}
	case 4:{
		e=0;
		if(!popLStack(s,&e)){printf("空栈\n");break;}
		printf("成功出栈%d\n",e);break;

	}
	case 5:{
		e=0;
		printf("输入数字\n");
		if(!scanf("%d",&e)){printf("输入的不是数字\n");break;}
		if(pushLStack(s,e)){printf("%d成功入栈\n",e);break;}
		printf("怎么就会入栈失败呢？？？\n");break;
	}
	case 6:{
		e=0;
		LStackLength(s,&e);break;

	}
	case 7:{
		destroyLStack(s);printf("摧毁栈成功\n");s=NULL;break;
	}
	case 8:{
		if(!clearLStack(s)){printf("已经是空栈\n");break;}
			printf("清栈成功\n");break;
	}
	default: rewind(stdin);printf("重新输入\n");break;
    }
    return 0;
}

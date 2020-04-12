#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"../QG训练营第三次培训/QG训练营第三次培训/代码和头文件/LQueue/LQueue.h"

int menu(LQueue*Q)
{	int num = 10;
	printf("**********LQueue************\n");
	printf("******3119004979************\n");
	printf("1.init the LQueue\n");
	if(Q!=NULL)
	{
	printf("2.destory the LQueue\n");
	printf("3.if LQueue is empty\n");
	printf("4.get the head node of LQueue\n");
	printf("5.the length of LQueue\n");
	printf("6.input a data in LQueue\n");
	printf("7.output a data of LQueue\n");
	printf("8.clear the LQueue\n");
	printf("9.print the LQueue\n");

	}
	printf("0.back to choose \n");
	printf("***********created by whs**************\n");
	fflush(stdin);
	scanf("%d",&num);
	if(Q==NULL&&num!=0&&num!=1)
		return 10;
	return num;
}
int main()
{	while(1){
	int run=10;
	void*e=NULL;
	void*data=NULL;
	LQueue*Q;
	Q=NULL;
	char c = '\0';
	printf("input # to exit or intput someting else to continue\n ");
	fflush(stdin);
	if(getchar()=='#')break;
	printf("the datatype you want\n");
	printf("i.int\nd.double\nc.char\n");
	while(c!='i'&&c!='d'&&c!='c')
	{
	fflush(stdin);
	c=getchar();
	switch(c)
	{
	case 'i':
		{
			for(int i=0;i<4;i++)
				datatype[i]='a';
			printf("%d\n",strlen(datatype));
			break;
		}
	case 'd':
		{
			for(int i=0;i<8;i++)
				datatype[i]='d';
			printf("%d\n",strlen(datatype));
			break;
		}
	case 'c':
		{
			for(int i=0;i<1;i++)
				datatype[i]='c';
			printf("%d\n",strlen(datatype));
			break;
		}

	default :rewind(stdin);break;
}
}
while(run)
 {
 	switch(run=menu(Q))
 	{
		case 0: printf("back to choose type\n");break;
		case 1: InitLQueue(&Q);break;
		case 2: DestoryLQueue(&Q);break;
		case 3: IsEmptyLQueue(Q);break;
		case 4 :
			{
				e = (void*)malloc(sizeof(strlen(datatype)));
				if(!GetHeadLQueue(Q,e))break;
				printf("the head data is :");
				if(strlen(datatype) == 8)printf("%lf\n",*(double*)e);
				if(strlen(datatype) == 1)printf("%c\n",*(char*)e);
				if(strlen(datatype) == 4)printf("%d\n",*(int*)e);
				break;
			}

		case 5: LengthLQueue(Q);break;
		case 6:{
			printf("intput your data\n");
			if(c=='i'){
				 e=(int*)malloc(sizeof(int));
				if(!scanf("%d",(int*)e)){printf("wrong datatype\n");break;}
			}
			if(c=='d'){
				 e=(double*)malloc(sizeof(double));
				if(!scanf("%lf",(double*)e)){printf("wrong datatype\n");break;}
			}
			if(c=='c'){
					fflush(stdin);
				 e=(char*)malloc(sizeof(char));
				if(!scanf("%c",(char*)e)){printf("wrong datatype\n");break;}
			}
			data=(void*)malloc(sizeof(strlen(datatype)));
			memcpy(data,e,strlen(datatype));
			EnLQueue(Q,data);break;
		}
		case 7:DeLQueue(Q);break;
		case 8:ClearLQueue(Q);break;
		case 9:TraverseLQueue(Q,e);
			printf("\n");break;
		default: rewind (stdin);break;
 	}

 }
}
 return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../QGѵ��Ӫ��������ѵ/QGѵ��Ӫ��������ѵ/�����ͷ�ļ�/AQueue/AQueue.h"
int menu(AQueue *Q){
	fflush(stdin);
	printf("***********˳�����***********\n");
	printf("1.����\n");
	if(Q!=NULL){
		printf("2.���ٶ���\n");
		printf("4.������������\n");
		printf("5.��ն���\n");
		printf("6.���Ӳ���\n");
		printf("7.��Ӳ���\n");
		printf("8.ȷ�����г���\n");
		printf("9.�鿴��ͷԪ��\n");
		printf("10.�������Ƿ�Ϊ��\n");
		printf("11.�������Ƿ�����\n");
	}
	printf("0.����ѡ������\n");
	printf("****************************\n");
	int num;
	scanf("%d",&num);
	if(Q==NULL&&num!=1&&num!=0)
		return 12;
	else return num;

}
int main()
{	while(1){
	int run=12;
	void*e=NULL;
	void*data=NULL;
	AQueue*Q;
	Q=NULL;
	char c = '\0';
	printf("input # to exit or intput sometingelse to continue\n ");
	fflush(stdin);
	if(getchar()=='#')break;
	printf("the datatype you want\n");
	printf("i.int\nd.double\nc.char\n");
	while(c!='i'&&c!='d'&&c!='c')
	{

	c=getchar();
	switch(c)
	{
		case 'i':
			{
				for(int i=0;i<4;i++)
					datatype[i]='a';
				printf("%d",strlen(datatype));
				break;
			}
		case 'd':
			{
				for(int i=0;i<8;i++)
					datatype[i]='d';
				printf("%d",strlen(datatype));
				break;
			}
		case 'c':
			{
				for(int i=0;i<1;i++)
					datatype[i]='c';
				printf("%d",strlen(datatype));
				break;
			}

		default :rewind(stdin);break;
	}
	}

	 while(run&&c!='e')
	 {
	 	switch(run=menu(Q))
	 	{
			case 0: printf("back to choose type\n");break;
			case 1: InitAQueue(&Q);break;
			case 2: DestoryAQueue(&Q);break;
			case 11:IsFullAQueue(Q);break;
			case 10: IsEmptyAQueue(Q);break;
			case 9 :
				{
					e = (void*)malloc(sizeof(strlen(datatype)));
					if(!GetHeadAQueue(Q,e))break;
					if(strlen(datatype) == 8)printf("%lf\n",*(double*)e);
					if(strlen(datatype) == 1)printf("%c\n",*(char*)e);
					if(strlen(datatype) == 4)printf("%d\n",*(int*)e);
					break;
				}

			case 8: LengthAQueue(Q);break;
			case 7:{//aaaaaaaa
				printf("intput your data\n");
				if(c=='i'){
					 e=(int*)malloc(sizeof(int));
					if(!scanf("%d",(int*)e)){printf("wrong datatype\n");break;}
				}
				if(c=='d'){
					 e=(double*)malloc(sizeof(double));
					if(!scanf("%lf",(double*)e)){printf("%2.lf\n",*(double*)e);
							fflush(stdin);printf("wrong datatype\n");break;}
				}
				if(c=='c'){
						fflush(stdin);
					 e=(char*)malloc(sizeof(char));
					if(!scanf("%c",(char*)e)){printf("wrong datatype\n");break;}
				}
				data=(void*)malloc(sizeof(strlen(datatype)));
				memcpy(data,e,strlen(datatype));
				EnAQueue(Q,data);break;
			}
			case 6:DeAQueue(Q);break;
			case 5:ClearAQueue(Q);break;
			case 4:TraverseAQueue(Q,e);break;
			default: rewind (stdin);break;
	 	}

	 }
	}
	 return 0;
}

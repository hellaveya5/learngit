#include<stdio.h>
#include"../head/duLinkedList.h"
#include<stdlib.h>

void visit(ElemType e){
	printf("%d\n",e);
}
int menu(DuLinkedList*L){

	printf("***********双向链表***********\n");
	printf("1.创建链表\n");
	if((*L)!=NULL){
		printf("2.删除链表\n");
		printf("3.插入第n个节点前面\n");
		printf("4.插入第n个节点后面\n");
		printf("5.删除第n个节点\n");
		printf("6.打印链表\n");
	}
	printf("0.退出程序\n");
	printf("****************************\n");
	int num;
	scanf("%d",&num);
	if((*L)==NULL&&num!=1&&num!=0)
		return 10;
	else return num;
}
int main(){
	int len=0,e=0,run=1;
	DuLinkedList L=NULL;
	while(run)
		{
		switch(run=menu(&L))
		{
			case 0: {//exit
				printf("退出程序\n");break;
				}

			case 1: {//创建链表
				int n;
				if(!InitList_DuL(&L)){printf("先销毁再创建\n");break;}
				printf("你想要的值？\n");
				scanf("%d",&n);
				L->data=n;
				printf("创建成功\n");len+=1;break;
			}
			case 2: {//摧毁链表
				DestroyList_DuL(&L);printf("SUCCESS\n");len=0;break;
				}
			case 3:	{//再第n个节点前插入
				DuLNode*q=(DuLNode*)malloc(sizeof(DuLNode));
				q->next=q->prior=NULL;
				DuLNode*p=L;
				printf("你想插入的数值是\n");
				if(!scanf("%d",&q->data)){printf("不是数字\n"); break;}
				printf("在第几个节点插入\n");
				if(!scanf("%d",&e)){printf("不是数字\n"); break;}
				if(e<1||e>len){printf("无该节点\n");break;}
				for(int i=1;i<len;i++)
				{
					p=p->next;
				}
				if(!InsertBeforeList_DuL(p,q)){printf("插入失败\n");break;}
				printf("插入成功\n");len+=1;break;
			}
			case 4:
			{
				DuLNode*q=(DuLNode*)malloc(sizeof(DuLNode));
				q->next=q->prior=NULL;
				DuLNode*p=L;
				printf("你想插入的数值是\n");
				if(!scanf("%d",&q->data)){printf("不是数字\n"); break;}
				printf("在第几个节点插入\n");
				if(!scanf("%d",&e)){printf("不是数字\n"); break;}
				//寻找第p个节点
				if(e<1||e>len){printf("无该节点\n");break;}
				for(int i=1;i<len;i++){
					p=p->next;
				}
				if(!InsertAfterList_DuL(p,q)){printf("插入失败\n");break;}
				printf("插入成功\n");len+=1;break;

			}
			case 5:{
				DuLNode*p=L;
				int n=0;
				printf("你想要删除第几个节点？\n");
				if(!scanf("%d",&n)){printf("不是数字\n");break;}
				if(n<1||n>len){printf("无该节点\n");break;}
				for(int i=1;i<len;i++){
				p=p->next;
				}
				DeleteList_DuL(p,&e);
				printf("删除了第%d含有%d的链表\n",n,e);
				len-=1;
				if(len==0)L=NULL;
				break;
			}
			case 6: {//print
				printf("************链表内容**************\n");
				TraverseList_DuL(L,visit);
				printf("**********************************\n");
			break;
			}
			default:rewind(stdin);break;

		}
		}
             return 0;
}


















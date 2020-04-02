#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void visit(ElemType e){
	printf("%d\n",e);
}
int menu(LinkedList *L){
	printf("****************************************\n");
	printf("1、创建链表\n");
	if((*L)!=NULL)
	{       printf("2、查找节点\n");
		printf("3、反转链表\n");
		printf("4、插入节点\n");
		printf("5、删除节点\n");
		printf("6、清空链表\n");
		printf("7、打印链表\n");
		printf("8、查找链表中间节点\n");
		printf("9、反转奇偶\n");
		printf("10、判断环形\n");
	}
	printf("输入0以退出程序\n");
	printf("请输入要使用的功能(数字):\n");
	printf("****************************************\n");
	int num=11;
	scanf("%d",&num);
	if(    (*L)==NULL&&num!=1&&num!=0 ){printf("重新输入");return 11;}
	return num;
}
int main(){
	int run=1,len=0,e=0;

	LinkedList L=NULL;
	while(run){
		switch(run=menu(&L)){
			case 0:{//退出
			printf("退出程序\n");break;
			}//创建链表
			case 1:{//建造链表
				if(!InitList(&L)){printf("先销毁了才能再创建\n");break;}
				printf("你想要的链表长度？\n");
				if(!scanf("%d",&len))printf("输入的并不是数字！！！\n");
				LNode*p1,*p2;
				p1=p2=(LNode*)malloc(sizeof(LNode));

				for(int i=0;i<len;i++)
				{	printf("输入你想储存的数值\n");

					if(!scanf("%d",&p1->data))printf("输入的并不是数字！！！\n");
					if(i==0)
						L->next=p1;
					else p2->next=p1;
						p2=p1;
						p1=(LNode*)malloc(sizeof(LNode));
				}
				p2->next=NULL;
				free(p1);
				printf("成功创建长度为%d的链表\n",len);
				break;}
			case 2:{//是否存在这个节点
				printf("你想要找的所储存的数值是？\n") ;
				if(!scanf("%d",&e))printf("输入的并不是数字！！！\n");
				if(!SearchList(L,e))printf("不存在存放该数值的节点\n");
				else printf("存在存放该数值的节点\n");
				break;}
			case 3:{//反转链表
				if(!ReverseList(&L))printf("反转链表失败\n");
				else printf("反转链表成功\n");
				break;}
			case 4:{//插入节点
				int a;
				e=0;
				printf("你想要插入什么数字到第几个节点后面呢？");
				if(0==(scanf("%d",&a)&&scanf("%d",&e)))printf("输入有效数字");
				else{
				if(e<=0||e>len)printf("没有该节点");
				else{	LNode*p;
					LNode*q=(LNode*)malloc(sizeof(LNode));
					p=L;
					q->data=a;
					for(int i=0;i<e;i++){
						p=p->next;
					}
					if(!InsertList(p,q))printf("插入失败");
					else printf("插入成功");
				}
				}
				len+=1;
				break;}
			case 5:{//删除节点
				printf("************链表内容***********\n");
				TraverseList(L,visit);
				e=0;
				printf("你想要删除第几个节点？\n") ;
				if(!scanf("%d",&e))printf("输入的并不是数字！！！\n");
				if(e<1||e>len)printf("不存在该节点\n");
				else{LNode*p=L;
				for(int i=1;i<e;i++){
					p=p->next;
				}
				if(!DeleteList(p,&e))printf("删除失败\n");
				else printf("删除节点储存数值%d\n",e);
				len-=1;
				}break;
				}
			case 6:{//摧毁链表
				DestroyList(&L);printf("摧毁链表成功\n");len=0;break;}
			case 7:{//打印链表
				printf("************链表内容***********\n");
				TraverseList(L,visit);
				printf("*******************************\n");
				break;}

			case 8:{//查找中间节点

				LNode*p1;
				p1=FindMidNode(&L);
				printf("中间节点的数是%d\n",p1->data);
				break;}
			case 9:{//反转奇偶
				if(L=ReverseEvenList(&L)) printf("反转奇偶成功\n");
				else printf("反转奇偶失败\n");
			break;
			}
			case 10:{//判断是否环形
				if(!IsLoopList(L))printf("不是环形链表\n");
				else printf("是环形链表\n");
				break;}
			default:rewind(stdin);break;
		}



	}

return 0;
}

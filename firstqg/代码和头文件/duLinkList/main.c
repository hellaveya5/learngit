#include<stdio.h>
#include"../head/duLinkedList.h"
#include<stdlib.h>

void visit(ElemType e){
	printf("%d\n",e);
}
int menu(DuLinkedList*L){

	printf("***********˫������***********\n");
	printf("1.��������\n");
	if((*L)!=NULL){
		printf("2.ɾ������\n");
		printf("3.�����n���ڵ�ǰ��\n");
		printf("4.�����n���ڵ����\n");
		printf("5.ɾ����n���ڵ�\n");
		printf("6.��ӡ����\n");
	}
	printf("0.�˳�����\n");
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
				printf("�˳�����\n");break;
				}

			case 1: {//��������
				int n;
				if(!InitList_DuL(&L)){printf("�������ٴ���\n");break;}
				printf("����Ҫ��ֵ��\n");
				scanf("%d",&n);
				L->data=n;
				printf("�����ɹ�\n");len+=1;break;
			}
			case 2: {//�ݻ�����
				DestroyList_DuL(&L);printf("SUCCESS\n");len=0;break;
				}
			case 3:	{//�ٵ�n���ڵ�ǰ����
				DuLNode*q=(DuLNode*)malloc(sizeof(DuLNode));
				q->next=q->prior=NULL;
				DuLNode*p=L;
				printf("����������ֵ��\n");
				if(!scanf("%d",&q->data)){printf("��������\n"); break;}
				printf("�ڵڼ����ڵ����\n");
				if(!scanf("%d",&e)){printf("��������\n"); break;}
				if(e<1||e>len){printf("�޸ýڵ�\n");break;}
				for(int i=1;i<len;i++)
				{
					p=p->next;
				}
				if(!InsertBeforeList_DuL(p,q)){printf("����ʧ��\n");break;}
				printf("����ɹ�\n");len+=1;break;
			}
			case 4:
			{
				DuLNode*q=(DuLNode*)malloc(sizeof(DuLNode));
				q->next=q->prior=NULL;
				DuLNode*p=L;
				printf("����������ֵ��\n");
				if(!scanf("%d",&q->data)){printf("��������\n"); break;}
				printf("�ڵڼ����ڵ����\n");
				if(!scanf("%d",&e)){printf("��������\n"); break;}
				//Ѱ�ҵ�p���ڵ�
				if(e<1||e>len){printf("�޸ýڵ�\n");break;}
				for(int i=1;i<len;i++){
					p=p->next;
				}
				if(!InsertAfterList_DuL(p,q)){printf("����ʧ��\n");break;}
				printf("����ɹ�\n");len+=1;break;

			}
			case 5:{
				DuLNode*p=L;
				int n=0;
				printf("����Ҫɾ���ڼ����ڵ㣿\n");
				if(!scanf("%d",&n)){printf("��������\n");break;}
				if(n<1||n>len){printf("�޸ýڵ�\n");break;}
				for(int i=1;i<len;i++){
				p=p->next;
				}
				DeleteList_DuL(p,&e);
				printf("ɾ���˵�%d����%d������\n",n,e);
				len-=1;
				if(len==0)L=NULL;
				break;
			}
			case 6: {//print
				printf("************��������**************\n");
				TraverseList_DuL(L,visit);
				printf("**********************************\n");
			break;
			}
			default:rewind(stdin);break;

		}
		}
             return 0;
}


















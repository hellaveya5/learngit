#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void visit(ElemType e){
	printf("%d\n",e);
}
int menu(LinkedList *L){
	printf("****************************************\n");
	printf("1����������\n");
	if((*L)!=NULL)
	{       printf("2�����ҽڵ�\n");
		printf("3����ת����\n");
		printf("4������ڵ�\n");
		printf("5��ɾ���ڵ�\n");
		printf("6���������\n");
		printf("7����ӡ����\n");
		printf("8�����������м�ڵ�\n");
		printf("9����ת��ż\n");
		printf("10���жϻ���\n");
	}
	printf("����0���˳�����\n");
	printf("������Ҫʹ�õĹ���(����):\n");
	printf("****************************************\n");
	int num=11;
	scanf("%d",&num);
	if(    (*L)==NULL&&num!=1&&num!=0 ){printf("��������");return 11;}
	return num;
}
int main(){
	int run=1,len=0,e=0;

	LinkedList L=NULL;
	while(run){
		switch(run=menu(&L)){
			case 0:{//�˳�
			printf("�˳�����\n");break;
			}//��������
			case 1:{//��������
				if(!InitList(&L)){printf("�������˲����ٴ���\n");break;}
				printf("����Ҫ�������ȣ�\n");
				if(!scanf("%d",&len))printf("����Ĳ��������֣�����\n");
				LNode*p1,*p2;
				p1=p2=(LNode*)malloc(sizeof(LNode));

				for(int i=0;i<len;i++)
				{	printf("�������봢�����ֵ\n");

					if(!scanf("%d",&p1->data))printf("����Ĳ��������֣�����\n");
					if(i==0)
						L->next=p1;
					else p2->next=p1;
						p2=p1;
						p1=(LNode*)malloc(sizeof(LNode));
				}
				p2->next=NULL;
				free(p1);
				printf("�ɹ���������Ϊ%d������\n",len);
				break;}
			case 2:{//�Ƿ��������ڵ�
				printf("����Ҫ�ҵ����������ֵ�ǣ�\n") ;
				if(!scanf("%d",&e))printf("����Ĳ��������֣�����\n");
				if(!SearchList(L,e))printf("�����ڴ�Ÿ���ֵ�Ľڵ�\n");
				else printf("���ڴ�Ÿ���ֵ�Ľڵ�\n");
				break;}
			case 3:{//��ת����
				if(!ReverseList(&L))printf("��ת����ʧ��\n");
				else printf("��ת����ɹ�\n");
				break;}
			case 4:{//����ڵ�
				int a;
				e=0;
				printf("����Ҫ����ʲô���ֵ��ڼ����ڵ�����أ�");
				if(0==(scanf("%d",&a)&&scanf("%d",&e)))printf("������Ч����");
				else{
				if(e<=0||e>len)printf("û�иýڵ�");
				else{	LNode*p;
					LNode*q=(LNode*)malloc(sizeof(LNode));
					p=L;
					q->data=a;
					for(int i=0;i<e;i++){
						p=p->next;
					}
					if(!InsertList(p,q))printf("����ʧ��");
					else printf("����ɹ�");
				}
				}
				len+=1;
				break;}
			case 5:{//ɾ���ڵ�
				printf("************��������***********\n");
				TraverseList(L,visit);
				e=0;
				printf("����Ҫɾ���ڼ����ڵ㣿\n") ;
				if(!scanf("%d",&e))printf("����Ĳ��������֣�����\n");
				if(e<1||e>len)printf("�����ڸýڵ�\n");
				else{LNode*p=L;
				for(int i=1;i<e;i++){
					p=p->next;
				}
				if(!DeleteList(p,&e))printf("ɾ��ʧ��\n");
				else printf("ɾ���ڵ㴢����ֵ%d\n",e);
				len-=1;
				}break;
				}
			case 6:{//�ݻ�����
				DestroyList(&L);printf("�ݻ�����ɹ�\n");len=0;break;}
			case 7:{//��ӡ����
				printf("************��������***********\n");
				TraverseList(L,visit);
				printf("*******************************\n");
				break;}

			case 8:{//�����м�ڵ�

				LNode*p1;
				p1=FindMidNode(&L);
				printf("�м�ڵ������%d\n",p1->data);
				break;}
			case 9:{//��ת��ż
				if(L=ReverseEvenList(&L)) printf("��ת��ż�ɹ�\n");
				else printf("��ת��żʧ��\n");
			break;
			}
			case 10:{//�ж��Ƿ���
				if(!IsLoopList(L))printf("���ǻ�������\n");
				else printf("�ǻ�������\n");
				break;}
			default:rewind(stdin);break;
		}



	}

return 0;
}

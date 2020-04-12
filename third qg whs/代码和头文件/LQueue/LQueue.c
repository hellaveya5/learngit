  #include"../QG训练营第三次培训/QG训练营第三次培训/代码和头文件/LQueue/LQueue.h"
  #include<stdio.h>
  #include <stdlib.h>
  #include<string.h>
  void InitLQueue(LQueue **Q){
  	if((*Q)!=NULL)
	{
		printf("ALREADY INTIT\n");
		return;
	}
  	Node* p1 = (Node*)malloc(sizeof(Node));
  	p1->next = NULL;
  	(*Q) = (LQueue*) malloc(sizeof(LQueue));
  	(*Q)->front=p1;
	(*Q)->rear = p1;
	(*Q)->length = 0;
	printf("INIT SUCCESS\n");



  }
   void DestoryLQueue(LQueue **Q){
	ClearLQueue(*Q);
	free((*Q)->front);
	(*Q)->length= 0;
	free(*Q);
	(*Q)=NULL;
	(*Q)->front=(*Q)->rear =NULL;
	printf("DESTORY SUCCESS\n");
   }
    Status GetHeadLQueue(LQueue *Q, void *e)
    {
    	if(IsEmptyLQueue(Q))return FALSE;
    	memcpy(e,Q->front->next->data,strlen(datatype));
    	return TRUE;
    }
  Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length==0)
	{
		printf("lqueue is empty\n");
		return TRUE;
	}
	printf("lqueue is not empty\n");
	return FALSE;
  }
   int LengthLQueue(LQueue *Q){
	printf("the length of lqueue:%d\n",Q->length);
	return Q->length;

   }


  Status EnLQueue(LQueue *Q, void *data){
	if(Q->front==NULL) return FALSE;
	Node*p1 = (Node*)malloc(sizeof(Node));
	p1->data = (void*)malloc(strlen(datatype));
	memcpy(p1->data,data,strlen(datatype));
	p1->next=NULL;
	Q->rear->next=p1;
	Q->rear=p1;
	Q->length++;
	return TRUE;

  }
   Status DeLQueue(LQueue *Q)
   {
   	if(IsEmptyLQueue(Q))return FALSE;
   	Node*p1=NULL;
   	p1=Q->front->next;
   	Q->front->next=p1->next;
   	if(p1==Q->rear)Q->rear=Q->front;
   	free(p1);
   	Q->length--;
	return TRUE;
   }
   void ClearLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q))return ;
	Node*p1 =NULL;
	Node*p2 = NULL;
	Q->rear = Q->front ;
	p1 = Q->rear->next;
	Q->rear->next = NULL;
	while(p1->next!=NULL )
	{
		p2=p1;
		p1=p1->next;
		free(p2);
	}
	free(p1);
	Q->length = 0;
	printf("CLEAR OVER\n");
   }

    Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(IsEmptyLQueue(Q))return FALSE;
	Node*p1 =p1=Q->front->next;
	for(int i=0;i<Q->length;i++)
	{

		LPrint(p1->data);
		p1=p1->next;
	}
	return TRUE;
    }
      void LPrint(void *q){
	if(strlen(datatype)==4)printf("%d",*(int*)q);
	if(strlen(datatype)==1)printf("%c",*(char*)q);
	if(strlen(datatype)==8)printf("%f",*(double*)q);
	printf("->");
      }

#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include"../QG训练营第三次培训/QG训练营第三次培训/代码和头文件/AQueue/AQueue.h"



void InitAQueue(AQueue **Q){
	if((*Q)) {
		printf("already init\n");return;
	}
	(*Q) = (AQueue*)malloc(sizeof(AQueue));
	for(int i=0;i<MAXQUEUE;i++)
	{
		(*Q)->data[i] = malloc(sizeof(strlen(datatype)));
	}
	(*Q)->front=(*Q)->rear=(*Q)->length=0;
	printf("InitAQueue SUCCESS\n");
	return;

}

void DestoryAQueue(AQueue **Q){
        if((*Q)->data) free((*Q)->data);
        for(int i =0;i<MAXQUEUE;i++)
	{
		free((*Q)->data[i]);
	}
	free((*Q));
	(*Q)=NULL;
	printf("DestoryAQueue SUCCESS\n");

}


Status IsFullAQueue(const AQueue *Q)
{
        if(Q->front==(Q->rear+1)%MAXQUEUE)
	{
		printf("aqueue is full\n");return TRUE;
	}
	printf("aqueue is not full\n"); return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front==Q->rear)
	{
		printf("aqueue is empty\n");return TRUE;
	}
	printf("aqueue is not empty\n");return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e){

        if(Q==NULL||Q->length==0)
	{
		IsEmptyAQueue(Q);return FALSE;
        }
	memcpy(e,Q->data[Q->front],strlen(datatype));

        return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	printf("the length of aqueue is :%d\n",(Q->rear-Q->front+MAXQUEUE)%MAXQUEUE);
        return Q->length;

}

Status EnAQueue(AQueue *Q, void *data){
        if(IsFullAQueue(Q))
	{
		printf("aqueue is full\n");
		return FALSE;
	}
	memcpy(Q->data[Q->rear],data,strlen(datatype));
	Q->rear = (Q->rear+1)%MAXQUEUE;
	printf("SUCCESS ENAQUEUE\n");
	Q->length++;
	return TRUE;
}

Status DeAQueue(AQueue *Q){
	if(IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	Q->front = (Q->front+1)%MAXQUEUE;
	Q->length-=1;
	printf("SUCCESS DEAQUEUE\n");
	return TRUE;
}


void ClearAQueue(AQueue *Q){
	if(IsEmptyAQueue(Q))
	{
		printf("already empty\n");return;
	}
	Q->front=Q->length=Q->rear=0;
	printf("SUCCESS CLEAR\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(IsEmptyAQueue(Q))return FALSE;
	for(int i=0 ;i <Q->length;i++)
	{
		APrint(Q->data[i]);
	}
	printf("\n");
	return TRUE;
}
void APrint(void *q)
{
	if(strlen(datatype) == 8)printf("%lf",*(double*)q);
	if(strlen(datatype) == 1)printf("%c",*(char*)q);
	if(strlen(datatype) == 4)printf("%d",*(int*)q);
	printf("->");


}

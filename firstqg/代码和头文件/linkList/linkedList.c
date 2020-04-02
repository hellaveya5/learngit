#include "../head/linkedList.h"
#include<stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	if((*L)!=NULL) return ERROR;
	(*L) = (LinkedList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return SUCCESS;

}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode*p = (*L) ;
	while(p){
		p = p->next;
		free(*L);
		(*L) = p;
	}


}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(p == NULL||q == NULL) return ERROR;
	q->next = p->next;
	p->next = q;
	return SUCCESS;


}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p == NULL||p->next == NULL)return ERROR;
	LNode*q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return SUCCESS;


}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList (LinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL) ;
	else
	{
	LNode*p = L->next;
	while(p){
		visit(p->data);
		p=p->next;
	}
	}


}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	while(L!=NULL){
		if(L->data==e)return SUCCESS;
		L=L->next;
	}
	return ERROR;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if((*L)==NULL)return ERROR;
	LNode*p,*q,*r;
	p=(*L)->next;
	(*L)->next= NULL;
	q=r=NULL;
	while(p){
	q=p->next;
	p->next=r;
	r=p;
	p=q;
	}
	(*L)->next= r;
	return SUCCESS;



}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(L->next==NULL||L==NULL)return ERROR;
	LNode*fast,*slow;
	fast=slow=L;
	fast=fast->next->next;
	slow=slow->next;
	while(SUCCESS){
		if(!fast||!slow)return ERROR;
		if(fast==slow)return SUCCESS;
		if(fast->next!=NULL)
		{fast=fast->next->next;
		      slow=slow->next;
		}
		else fast=fast->next;

	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
		if((*L)==NULL||(*L)->next==NULL)return ERROR;
		LNode*q,*p,*r;
		q=(*L);
		p=q->next;
		r=p->next;
		while(r!=NULL){
			if((r->data)%2==0){
				p->next=r->next;//3¸öÓï¾ä½»»»Ë³Ðò
				r->next=p;
				q->next=r;//***
				q=r;
				r=p->next;

			}
			if(r!=NULL){
			q=q->next;
			p=p->next;
			r=r->next;
			}
		}
		return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
		if((*L)==NULL||(*L)->next==NULL) return *L;
		LNode*fast,*slow;
		slow=fast=*L;
		while(fast!=NULL){
			if(fast->next==NULL)fast=fast->next;
			else fast=fast->next->next;
			slow=slow->next;
		}
		return slow;
}


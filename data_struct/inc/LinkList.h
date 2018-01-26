/*
 * LinkList.h
 *
 *  Created on: Dec 14, 2017
 *      Author: yewei
 */

#ifndef DATA_STRUCT_INC_LINKLIST_H_
#define DATA_STRUCT_INC_LINKLIST_H_

#include <iostream>
#include <stack>
/*
 * 单链表
 *
 * */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;

template<typename ElemType>
struct _LNode{
	ElemType data;
	struct _LNode *next;
};

template<typename ElemType>
class LinkList{
private:
	int count;
public:
	_LNode<ElemType> *LinkHead;
	LinkList();//
	LinkList(int n, ElemType *A);//
	~LinkList();//
	Status ClearList_L();//
	Status ListEmpty_L();
	int ListLength_L();//
	_LNode<ElemType> *Search_L(ElemType e);//
	_LNode<ElemType> *NextElem_L(_LNode<ElemType> *p);//
	_LNode<ElemType> *MakeNode_L(ElemType e);//
	_LNode<ElemType> *GetHead();//
	Status InsertAfter_L(_LNode<ElemType> *p, _LNode<ElemType> *q);//
	Status DeleteAfter_L(_LNode<ElemType> *p, ElemType &e);//
	void ListTraverse_L(int (*visit)(ElemType e));//

	void InverseCurrentList();
	static int PrintList(ElemType e){
		std::cout<<e<<" ";
		return 0;
	}
};

template<typename ElemType>
Status LinkList<ElemType>::ClearList_L(){
	if(LinkHead == NULL)
		return ERROR;
	_LNode<ElemType> *q;
	while(LinkHead) {
		q = LinkHead -> next;
		delete LinkHead;
		LinkHead = q;
	}
	return OK;
}

template<typename ElemType>
Status LinkList<ElemType>::ListEmpty_L(){
	if(NULL==LinkHead->next)
		return TRUE;
	return FALSE;
}

template<typename ElemType>
LinkList<ElemType>::LinkList() : LinkHead(new _LNode<ElemType>){
	ClearList_L();
}

template<typename ElemType>
LinkList<ElemType>::~LinkList(){
	ClearList_L();
	LinkHead->next = NULL;
	count = 0;
}


template<typename ElemType>
LinkList<ElemType>::LinkList(int n, ElemType *A) : LinkHead(new _LNode<ElemType>){
	_LNode<ElemType> *q,*p;
	int i ;
	p = LinkHead;
	for(i=0;i<n;i++){
		q = MakeNode_L(A[i]);
		InsertAfter_L(p,q);
		p = q;
	}
}

template<typename ElemType>
Status LinkList<ElemType>::InsertAfter_L(_LNode<ElemType> *p, _LNode<ElemType> *q){
	if(NULL==p || NULL==q)
		return ERROR;
	q->next = p->next;
	p->next = q;
	count ++;
	return OK;
}

template<typename ElemType>
_LNode<ElemType>* LinkList<ElemType>::GetHead(){
	return LinkHead;
}

template<typename ElemType>
Status LinkList<ElemType>::DeleteAfter_L(_LNode<ElemType> *p, ElemType &e){
	_LNode<ElemType> *q;
	if(NULL=p || NULL==p->next)
		return ERROR;
	q = p->next;
	delete q;
	count --;
	return OK;
}


template<typename ElemType>
_LNode<ElemType>* LinkList<ElemType>::MakeNode_L(ElemType e){
	_LNode<ElemType> *tmp = new _LNode<ElemType>;
	if(NULL==tmp){
		return ERROR;
	}
	tmp->next = NULL;
	tmp->data = e;
	count++;
	return tmp;
}

template<typename ElemType>
int LinkList<ElemType>::ListLength_L(){
	return count;
}

template<typename ElemType>
void LinkList<ElemType>::ListTraverse_L(int (*visit)(ElemType e)){
	_LNode<ElemType> *tmp = new _LNode<ElemType>;
	tmp = LinkHead->next;
	while(tmp){
		visit(tmp->data);
		tmp = tmp -> next;
	}
}

template<typename ElemType>
_LNode<ElemType>* LinkList<ElemType>::NextElem_L(_LNode<ElemType> *p){
	if(NULL!=p->next){
		return p->next;
	}else
		return NULL;
}

template<typename ElemType>
_LNode<ElemType>* LinkList<ElemType>::Search_L(ElemType e){
	_LNode<ElemType> *tmp = new _LNode<ElemType>;
	if(NULL==LinkHead->next)
		return NULL;
	tmp = LinkHead->next;
	while(tmp!=NULL&&tmp->data!=e){
		tmp = tmp->next;
	}
	return tmp;
}


template<typename ElemType>
void LinkList<ElemType>::InverseCurrentList(){
	//判断当前的链表状态
	if(LinkHead==nullptr || LinkHead->next==nullptr){
		return;
	}
	std::stack<_LNode<ElemType> *> s;
	_LNode<ElemType> * OldHead;
	_LNode<ElemType> * NewHead = new _LNode<ElemType>;
	_LNode<ElemType> *q,*p;
	OldHead = LinkHead;
	while(OldHead->next){
		s.push(OldHead->next);
		OldHead = OldHead->next;
	}
	p = NewHead;
	while(!s.empty()){
		q = s.top();
		InsertAfter_L(p,q);
		p = q;
		s.pop();
	}
	LinkHead = NewHead;
}



void unit_test_LinkList();
void unit_test_LinkList_andSTL();
void unit_test_LinkList_2head();
void unit_test_LinkList_inv();
#endif /* DATA_STRUCT_INC_LINKLIST_H_ */

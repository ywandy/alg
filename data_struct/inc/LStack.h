/*
 * LStack.h
 *
 *  Created on: Dec 14, 2017
 *      Author: yewei
 */

#ifndef DATA_STRUCT_INC_LSTACK_H_
#define DATA_STRUCT_INC_LSTACK_H_

#include <iostream>
/*
 * 链栈
 *
 * */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;

template<typename ElemType>
class LSNode{
private:
	typedef struct _LSNode{
		ElemType data;
		struct _LSNode *next;
	}_LSNode,*_LStack;
	_LSNode *LStackTop;
public:
	LSNode(); //初始化栈
	~LSNode();
	Status Push_LS(ElemType e);
	ElemType Pop_LS();
	ElemType GetTop_LS();
	Status StackEmpty_LS(); //判断是否为空
	Status ClearStack_LS();
};

template<typename ElemType>
LSNode<ElemType>::LSNode(){
	LStackTop = NULL;
}

template<typename ElemType>
Status LSNode<ElemType>::Push_LS(ElemType e){
	_LSNode *t;
	t = new _LSNode;
	if(t==NULL)
		return OVERFLOW;
	t->data = e;
	t->next = LStackTop;
	LStackTop = t;
	return OK;
}

template<typename ElemType>
ElemType LSNode<ElemType>::Pop_LS(){
	ElemType e;
	_LSNode *t;
	if(NULL==LStackTop)
		return ERROR;
	e = LStackTop->data;
	t = LStackTop->next;
	delete LStackTop;
	LStackTop = t;
	return e;
}

template<typename ElemType>
ElemType LSNode<ElemType>::GetTop_LS(){
	if(NULL==LStackTop)
		return ERROR;
	return LStackTop->data;
}

template<typename ElemType>
Status LSNode<ElemType>::StackEmpty_LS(){
	if(NULL==LStackTop)
		return FALSE;
	else
		return TRUE;
}

template<typename ElemType>
LSNode<ElemType>::~LSNode(){
	ClearStack_LS();
	LStackTop = NULL;
}

template<typename ElemType>
Status LSNode<ElemType>::ClearStack_LS(){
	if(NULL==LStackTop)
		return ERROR;
	while(NULL!=LStackTop){
		Pop_LS();
	}
	LStackTop = NULL;
	return OK;
}

void unit_test_LStack();
#endif /* DATA_STRUCT_INC_LSTACK_H_ */

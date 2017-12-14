/*
 * SqList.h
 *
 *  Created on: Dec 12, 2017
 *      Author: yewei
 */

#ifndef DATA_STRUCT_INC_SQLIST_H_
#define DATA_STRUCT_INC_SQLIST_H_
#include <iostream>
/*
 * 顺序栈
 *
 * */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
template<typename ElemType>
class SqList{
private:
	ElemType  *elem;
	int length;
	int size;
	int increment;
public:
	SqList(int inp_size,int inc);
	~SqList();
	ElemType ListLength_Sq();
	ElemType GetElem_Sq(int pos);
	ElemType Search_Sq(ElemType e);
	Status DeleteLast_Sq(ElemType &e);
	Status ClearList_Sq();
	Status ListEmpty_Sq();
	Status PutElem_Sq(ElemType e,int pos);
	Status Append_Sq(ElemType e);
	Status ListTraverse_Sq(void(*visit)(ElemType e));

	static void PrintList(ElemType e){
		std::cout<<e<<" ";
	}

};

template<typename ElemType>
SqList<ElemType>::SqList(int inp_size,int inc){
	elem = new ElemType[inp_size];
	size = inp_size;
	increment = inc;
	length = 0;
}


template<typename ElemType>
SqList<ElemType>::~SqList(){
	delete elem;
	size = 0;
	increment = 0;
	length = 0;
}


template<typename ElemType>
Status SqList<ElemType>::DeleteLast_Sq(ElemType &e){
	if(0==length) return ERROR;
	e = elem[length-1];
	--length;
	return OK;
}

template<typename ElemType>
ElemType SqList<ElemType>::Search_Sq(ElemType e){
	int pos = 0;
	while((pos<length)&&(elem[pos]!=e))
		pos++;
	if(pos<length)
		return pos;
	else
		return -1;
}

template<typename ElemType>
Status SqList<ElemType>::ClearList_Sq(){
	length = 0;
	return OK;
}

template<typename ElemType>
Status SqList<ElemType>::ListEmpty_Sq(){
	if(length==0)
		return TRUE;
	else
		return FALSE;
}

template<typename ElemType>
ElemType SqList<ElemType>::ListLength_Sq(){
	return length;
}

template<typename ElemType>
Status SqList <ElemType>::PutElem_Sq(ElemType e,int pos){
	if((pos<0) || (pos>length))
		return ERROR;
	elem[pos] = e;
	return OK;
}

template<typename ElemType>
Status SqList <ElemType>::Append_Sq(ElemType e){
	int *newbase;
	if(length==size){
		newbase = (ElemType *)realloc(elem,(size+increment)*sizeof(ElemType));
		elem = newbase;
		size+=increment;
	}
	elem[length]=e;
	length++;
	return OK;
}

template<typename ElemType>
ElemType SqList<ElemType>::GetElem_Sq(int pos){
	if((pos<0)||(pos>length))
		return -1;
	return elem[pos];
}

template<typename ElemType>
Status SqList<ElemType>::ListTraverse_Sq(void(*visit)(ElemType e)){
	int i = 0;
	for(i=0;i<length;i++)
		visit(elem[i]);
	std::cout<<std::endl;
	return OK;
}

void unit_test_SqList();
void unit_test_SqList2();//有序顺序表归并

#endif /* DATA_STRUCT_INC_SQLIST_H_ */

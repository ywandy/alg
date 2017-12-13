/*
 * SqList.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: yewei
 */

#include <SqList.h>


SqList::SqList(int inp_size,int inc){
	elem = new ElemType[inp_size];
	size = inp_size;
	increment = inc;
	length = 0;
}


SqList::~SqList(){
	delete elem;
	size = 0;
	increment = 0;
	length = 0;
}


Status SqList::DeleteLast_Sq(ElemType &e){
	if(0==length) return ERROR;
	e = elem[length-1];
	--length;
	return OK;
}

int SqList::Search_Sq(ElemType e){
	int pos = 0;
	while((pos<length)&&(elem[pos]!=e))
		pos++;
	if(pos<length)
		return pos;
	else
		return -1;
}

Status SqList::ClearList_Sq(){
	length = 0;
	return OK;
}

Status SqList::ListEmpty_Sq(){
	if(length==0)
		return TRUE;
	else
		return FALSE;
}

int SqList::ListLength_Sq(){
	return length;
}

Status SqList::PutElem_Sq(ElemType e,int pos){
	if((pos<0) || (pos>length))
		return ERROR;
	elem[pos] = e;
	return OK;
}

Status SqList::Append_Sq(ElemType e){
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

int SqList::GetElem_Sq(int pos){
	if((pos<0)||(pos>length))
		return -1;
	return elem[pos];
}

Status SqList::ListTraverse_Sq(Status(*visit)(ElemType e)){
	int i = 0;
	for(i=0;i<length;i++)
		visit(elem[i]);
	std::cout<<std::endl;
	return OK;
}

void unit_test_SqList(){
	SqList *ts_SqList = new SqList(5,5);
	std::cout<<"length="<<(*ts_SqList).ListLength_Sq()<<std::endl;
	(*ts_SqList).Append_Sq(22);
	(*ts_SqList).Append_Sq(25);
	(*ts_SqList).Append_Sq(77);
	(*ts_SqList).Append_Sq(88);
	(*ts_SqList).Append_Sq(9);
	(*ts_SqList).Append_Sq(4);
	(*ts_SqList).Append_Sq(6);
	std::cout<<"length="<<(*ts_SqList).ListLength_Sq()<<std::endl;
	std::cout<<"pos 4 is="<<(*ts_SqList).GetElem_Sq(4)<<std::endl;
}



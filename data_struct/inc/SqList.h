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
typedef int ElemType;
class SqList{
private:
	ElemType  *elem;
	int length;
	int size;
	int increment;
public:
	SqList(int inp_size,ElemType inc);
	~SqList();
	int ListLength_Sq();
	int GetElem_Sq(int pos);
	int Search_Sq(ElemType e);
	Status DeleteLast_Sq(ElemType &e);
	Status ClearList_Sq();
	Status ListEmpty_Sq();
	Status PutElem_Sq(ElemType e,ElemType pos);
	Status Append_Sq(ElemType e);
	Status ListTraverse_Sq(Status(*visit)(ElemType e));

};

void unit_test_SqList();


#endif /* DATA_STRUCT_INC_SQLIST_H_ */

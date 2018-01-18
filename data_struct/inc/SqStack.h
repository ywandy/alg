/*
 * SqStack.h
 *
 *  Created on: Dec 12, 2017
 *      Author: yewei
 */

#ifndef DATA_STRUCT_INC_SQSTACK_H_
#define DATA_STRUCT_INC_SQSTACK_H_
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
typedef int ElemType; //数据结构写法的规范

typedef struct{
	ElemType *elem; //存储空间的首地址
	int top;   //栈顶元素的下一个，栈顶位标
	int size;  //分配的容量
	int increment; //扩容的增量
}SqStack;//顺序栈

Status InitStack_Sq(SqStack &S,int size,int inc); //初始化栈
Status Push_Sq(SqStack &S,ElemType e);
Status Pop_Sq(SqStack &S,ElemType &e);
Status GetTop_Sq(SqStack &S,ElemType &e);
Status DestroyStack_Sq(SqStack &S);
void ClearStack_Sq(SqStack &S);
Status StackEmpty_Sq(SqStack S);
Status VisitStack_Sq(SqStack &S,void(*visit)(ElemType e));
void Unit_Test_Stack_Sq_1();
//实现的接口






#endif /* DATA_STRUCT_INC_SQSTACK_H_ */

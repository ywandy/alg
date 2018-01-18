/*
 * SqStack.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: yewei
 */
#include <SqStack.h>

/*
 * 初始化栈的操作
 * */
Status InitStack_Sq(SqStack &S,int size,int inc){
	S.elem = (ElemType *)malloc(size*sizeof(ElemType));
	if(NULL == S.elem)
		return OVERFLOW;
	S.top = 0;
	S.size = size;
	S.increment = inc;
	return OK;
}


Status Push_Sq(SqStack &S,ElemType e){
	//判断栈是否空
	ElemType *newbase; //创建一个基地址的指针
	if(S.top==S.size){
		newbase = (ElemType *)realloc(S.elem,(S.size+S.increment)*sizeof(ElemType)); //满了就重新分配空间
		if(NULL==newbase)
			return OVERFLOW;
		S.elem = newbase;
		S.size = S.size+S.increment;
	}
	S.elem[S.top] = e; //入栈
	S.top++; //栈顶增加
	return OK;
}

Status Pop_Sq(SqStack &S,ElemType &e){
	if(S.top==0)
		return ERROR;
	S.top--;
	e = S.elem[S.top];
	return OK;
}

Status GetTop_Sq(SqStack &S,ElemType &e){
	if(S.top>0){
		e = S.elem[S.top-1];
		return OK;
	}
	else
		return ERROR;
}

Status DestroyStack_Sq(SqStack &S){
	if(NULL!=S.elem){
		free(S.elem);
	}
	S.elem = NULL;
	S.size = 0;
	S.top = 0;
	S.increment = 0;
	return OK;
}

Status VisitStack_Sq(SqStack &S,void(*visit)(ElemType e)){
	int pos = S.top;
	ElemType tmp;
	if(pos==0){
		std::cout<<std::endl;
		return ERROR;
	}
	while(pos!=0){
		tmp = S.elem[pos-1];
		visit(tmp);
		pos--;
	}
	std::cout<<std::endl;
	return OK;
}

void ClearStack_Sq(SqStack &S){
	S.top = 0;
}

Status StackEmpty_Sq(SqStack S){
	if(S.top==0)
		return TRUE;
	else
		return FALSE;
}

void Converstion(int N){
	SqStack S;
	ElemType e;
	InitStack_Sq(S, 10, 5);
	std::cout<<"raw:"<<N<<"   ";
	std::cout<<"out:";
	while(N!=0){
		Push_Sq(S,N%8);
		N = N / 8;
	}
	while(FALSE==StackEmpty_Sq(S)){
		Pop_Sq(S,e);
		std::cout<<e;
	}
	std::cout<<std::endl;
}

//单元测试1 数制转换
void Unit_Test_Stack_Sq_1(){
	std::cout<<"unit test stack_sq converstion"<<std::endl;
	Converstion(10);
	Converstion(22);
	Converstion(1024);
	Converstion(1358);
}

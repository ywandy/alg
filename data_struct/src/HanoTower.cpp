/*
 * HanoTower.cpp
 *
 *  Created on: Jan 18, 2018
 *      Author: yewei
 */


#include <HanoTower.h>
#include <ctime>
//汉诺塔递归算法
SqStack X,Y,Z;

void hanoi_view(SqStack &x,SqStack &y,SqStack &z){

	std::cout<<"第一根柱子(顶端)";
	VisitStack_Sq(X,view);
	std::cout<<"第二根柱子(顶端)";
	VisitStack_Sq(Y,view);
	std::cout<<"第三根柱子(顶端)";
	VisitStack_Sq(Z,view);
	std::cout<<std::endl;
}

void move(SqStack &x,SqStack &z){
	ElemType tmp;
	if(Pop_Sq(x,tmp)==ERROR)
		return;
	Push_Sq(z,tmp);
	//hanoi_view(X,Y,Z); //显示汉诺塔步骤
}

void hanoi(int n,SqStack &x,SqStack &y,SqStack &z){
	if(n==1){
		move(x,z);
	}
	else{
		hanoi(n-1,x,z,y);
		move(x,z);
		hanoi(n-1,y,x,z);
	}
}

void view(ElemType e){
	std::cout<<e<<" ";
}


#define Hanoi_Layer 9999
#define VIEW_Hanoi_Flag 1
void HanoTower_unit_test(){
	clock_t start, finish;
	double duration;
	start = clock();
	std::cout<<"结合SqStack和汉诺塔递归问题实现的汉诺塔"<<std::endl;
	InitStack_Sq(X, 10, 5);
	InitStack_Sq(Y, 10, 5);
	InitStack_Sq(Z, 10, 5);
	for(int i=Hanoi_Layer;i>0;i--){
		Push_Sq(X,i);
	}
	hanoi_view(X,Y,Z);
	hanoi(Hanoi_Layer,X,Y,Z);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration );
}

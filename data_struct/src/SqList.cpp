/*
 * SqList.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: yewei
 */

#include <SqList.h>




void unit_test_SqList(){
	std::cout<<"init the SqList!!!"<<std::endl;
	SqList<int> *ts_SqList = new SqList<int>(5,5);
	std::cout<<"length="<<(*ts_SqList).ListLength_Sq()<<"  Empty:"<<(*ts_SqList).ListEmpty_Sq()<<std::endl;
	std::cout<<"insert enum : 22 25 77 88 9 4 6"<<std::endl;
	(*ts_SqList).Append_Sq(22);
	(*ts_SqList).Append_Sq(25);
	(*ts_SqList).Append_Sq(77);
	(*ts_SqList).Append_Sq(88);
	(*ts_SqList).Append_Sq(9);
	(*ts_SqList).Append_Sq(4);
	(*ts_SqList).Append_Sq(6);
	std::cout<<"length="<<(*ts_SqList).ListLength_Sq()<<"  Empty:"<<(*ts_SqList).ListEmpty_Sq()<<std::endl;

	std::cout<<"FUN:GetElem_Sq();  pos 4 is="<<(*ts_SqList).GetElem_Sq(4)<<std::endl;
	(*ts_SqList).ListTraverse_Sq(SqList<int>::PrintList);

	std::cout<<"FUN:PutElem_Sq() to change pos 4 into 100"<<std::endl;
	(*ts_SqList).PutElem_Sq(100,4);
	(*ts_SqList).ListTraverse_Sq(SqList<int>::PrintList);

	std::cout<<"FUN:Append_Sq()  to add a enum 200"<<std::endl;
	(*ts_SqList).Append_Sq(200);
	(*ts_SqList).ListTraverse_Sq(SqList<int>::PrintList);

}

void unit_test_SqList2(){
	SqList<int> *La = new SqList<int>(1,5);
	SqList<int> *Lb = new SqList<int>(1,5);
	SqList<int> *Lc = new SqList<int>(1,5);
	(*La).Append_Sq(2);
	(*La).Append_Sq(7);
	(*La).Append_Sq(10);
	(*La).Append_Sq(17);
	(*Lb).Append_Sq(3);
	(*Lb).Append_Sq(5);
	(*Lb).Append_Sq(7);
	(*Lb).Append_Sq(12);
	(*Lb).Append_Sq(15);
	std::cout<<"La : ";
	(*La).ListTraverse_Sq(SqList<int>::PrintList);
	std::cout<<"Lb : ";
	(*Lb).ListTraverse_Sq(SqList<int>::PrintList);
	std::cout<<"La count:"<<(*La).ListLength_Sq()<<"  Lb count:"<<(*Lb).ListLength_Sq()<<std::endl;
	int pos_a,pos_b;
	pos_a = pos_b = 0;
	while(pos_a<(*La).ListLength_Sq()&&pos_b<(*Lb).ListLength_Sq()){
		if((*La).GetElem_Sq(pos_a)<=(*Lb).GetElem_Sq(pos_b)){
			(*Lc).Append_Sq((*La).GetElem_Sq(pos_a));
			pos_a++;
		}else{
			(*Lc).Append_Sq((*Lb).GetElem_Sq(pos_b));
			pos_b++;
		}
	}
	while(pos_a<(*La).ListLength_Sq()){
		(*Lc).Append_Sq((*La).GetElem_Sq(pos_a));
		pos_a++;
	}
	while(pos_b<(*Lb).ListLength_Sq()){
			(*Lc).Append_Sq((*Lb).GetElem_Sq(pos_b));
			pos_b++;
	}
	std::cout<<"Lc : ";
	(*Lc).ListTraverse_Sq(SqList<int>::PrintList);
}



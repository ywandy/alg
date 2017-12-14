/*
 * SqList.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: yewei
 */

#include <SqList.h>




void unit_test_SqList(){
	SqList<int> *ts_SqList = new SqList<int>(5,5);
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
	(*ts_SqList).ListTraverse_Sq(SqList<int>::PrintList(ElemType e));
}



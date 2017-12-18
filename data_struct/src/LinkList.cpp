/*
 * LinkList.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: yewei
 */
#include <LinkList.h>

void unit_test_LinkList(){
	int test[5] = {1,2,3,4,5};
	LinkList<int> *ts_ = new LinkList<int>(5,test);
	(*ts_).ListTraverse_L(LinkList<int>::PrintList);
	delete ts_;
}

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


//倒数第几个链表输出
#define N 2
void unit_test_LinkList_andSTL(){
	int test[5] = {1,2,3,4,5};
	std::stack<_LNode<int> *> stack1;
	LinkList<int> *ts_ = new LinkList<int>(5,test);

	_LNode<int> *tmp;
	tmp = ((*ts_).GetHead())->next;
	while(tmp){
		stack1.push(tmp);
		tmp = tmp->next;
	}
	for(int i=0;i<N-1;i++){
		stack1.pop();
	}
	std::cout<<(stack1.top())->data<<std::endl;
	delete ts_;
}

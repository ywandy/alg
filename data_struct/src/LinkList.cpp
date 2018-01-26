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
	std::stack<_LNode<int> *> *stack1 = new  std::stack<_LNode<int> *>;
	LinkList<int> *ts_ = new LinkList<int>(5,test);
	_LNode<int> *tmp;
	tmp = ((*ts_).GetHead());
	while(tmp){
		stack1->push(tmp);
		tmp = tmp->next;
	}
	for(int i=0;i<N-1;i++){
		stack1->pop();
	}
	std::cout<<(stack1->top())->data<<std::endl;
	delete ts_;
}

void unit_test_LinkList_2head(){
	int test[5] = {1,2,3,4,5};
	LinkList<int> *ts_ = new LinkList<int>(5,test);
	_LNode<int> *head1,*head2;
	head1 = head2 = ((*ts_).GetHead());
	for(int i=0;i!=N;i++){
		if(head2==nullptr)
			std::cout<<head1->data<<std::endl;
		head2 = head2->next;
	}
	while(head2){
		head1 = head1->next;
		head2 = head2->next;
	}
	std::cout<<head1->data<<std::endl;
}

//链表倒序输出的stl实现
void unit_test_LinkList_inv(){
	int test[5] = {1,2,3,4,5};
	std::cout<<"正序的链表:"<<std::endl;
	LinkList<int> *ts_ = new LinkList<int>(5,test);
	(*ts_).ListTraverse_L(LinkList<int>::PrintList);
	std::cout<<"倒序的链表:"<<std::endl;
	(*ts_).InverseCurrentList();
	(*ts_).ListTraverse_L(LinkList<int>::PrintList);
}


void unit_test_LinkList_merge(){
	int test1[5] = {2,4,7,8,10};
	int test2[5] = {2,3,7,9,11};
	_LNode<int> *head1,*head2,*merge,*merge_head;
	LinkList<int> *ts_1 = new LinkList<int>(5,test1);
	LinkList<int> *ts_2 = new LinkList<int>(5,test2);
	head1 = (*ts_1).GetHead();
	head2 = (*ts_2).GetHead();
	std::cout<<"打印链表1:"<<std::endl;
	(*ts_1).ListTraverse_L(LinkList<int>::PrintList);
	std::cout<<std::endl;
	std::cout<<"打印链表2:"<<std::endl;
	(*ts_2).ListTraverse_L(LinkList<int>::PrintList);
	std::cout<<std::endl;

	std::cout<<"打印合并链表:"<<std::endl;
	merge = (*ts_1).Merge_1(head1->next,head2->next);
	merge_head = new _LNode<int>;
	merge_head->next = merge;
	LinkList<int>::ListTraverse_L(merge_head,LinkList<int>::PrintList);
	std::cout<<std::endl;



}

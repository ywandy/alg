/*
 * ListNodeAlg.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: yewei
 */


#include <ListNodeAlg.h>

/****链表倒序******/
std::vector<int> printListFromTailToHead(ListNode* head) {
       ListNode* p;
       p=head;
       int num=0;
       std::vector<int> out;
       while(p!=NULL){
    	   std::cout<<p->val<<std::endl;
           out[num]=p->val;
           num++;
           p=p->next;
       }
       return out;
}

/*
 *
 * 链表去重函数
 * */


ListNode* deleteDuplication(ListNode* pHead){
	ListNode *head = new ListNode(-1);
	head->next=pHead;
	ListNode *p = pHead;
	ListNode *end = head;
	int val;
	while(p!=NULL&&p->next!=NULL){
		/*判断有没有元素重复*/
		if(p->val==p->next->val){
			val = p->val;
			while(p!=NULL&&p->val==val){
				p = p->next;
			}
			end->next=p;
		}
		else{
			end=p;
			p = p->next;
		}
	}
	return head->next;
}

//链表去重复单元测试
void unit_test_deleteDuplication(){
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(3);
	ListNode *node5 = new ListNode(4);
	ListNode *node6 = new ListNode(4);
	ListNode *node7 = new ListNode(5);
	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	node4->next=node5;
	node5->next=node6;
	node6->next=node7;
	ListNode *node = deleteDuplication(node1);
	ListNode *p = node1;
	while(p != NULL)
	    {
			std::cout <<p->val <<" -=> ";
	        p = p->next;
	    }
}
/*
 *
 * 链表去重函数
 * */

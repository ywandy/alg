/*
 * ListNodeAlg.h
 *
 *  Created on: Jan 20, 2018
 *      Author: yewei
 */

#ifndef ARRAY_INC_LISTNODEALG_H_
#define ARRAY_INC_LISTNODEALG_H_
#include <iostream>
#include <vector>
struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

std::vector<int> printListFromTailToHead(ListNode* head);
ListNode* deleteDuplication(ListNode* pHead);
void unit_test_deleteDuplication();

#endif /* ARRAY_INC_LISTNODEALG_H_ */

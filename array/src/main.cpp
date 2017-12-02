#include <iostream>
#include <vector>
  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };


using namespace std;

bool find_target(int target,int cow,int cot,int array[][4]){
	int i,j,pos_cow,pos_cot;
	i=j=0;
	cout<<"cows:"<<cow<<" cots:"<<cot<<endl;
	for(i=0;i<cow;i++){
		for(j=cot-1;j>=0;j--){
			if(target>array[i][j]){
				break;
			}
			if(target==array[i][j]){
				pos_cow = i+1;
				pos_cot = j+1;
				cout<<"pos is:"<<pos_cow<<"  "<<pos_cot<<endl;
				return true;
			}
		}
	}
	return false;
}

int unit_test_findtarget(){
	int a[4][4]={
		{0,1,2,3},
		{6,7,8,9},
		{30,43,65,90},
		{78,90,1200,1300}
	};
	int cows = sizeof(a)/sizeof(int)/(sizeof(a[0])/sizeof(int));
	int cots = sizeof(a[0])/sizeof(int);
	if(find_target(65,cows,cots,a)==true)
		cout<<"有这个整数"<<endl;
	else
		cout<<"没有这个整数"<<endl;
	return 0;
}


vector<int> printListFromTailToHead(ListNode* head) {
       ListNode* p;
       p=head;
       int num=0;
       vector<int> out;
       while(p!=NULL){
           cout<<p->val<<endl;
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
	        cout <<p->val <<" -=> ";
	        p = p->next;
	    }
}


int main(){
  std::cout << "hello world" << '\n';
  unit_test_deleteDuplication();
  return 0;
}

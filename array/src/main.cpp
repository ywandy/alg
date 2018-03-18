#include <iostream>
#include <vector>
#include <cstring>
#include <2-DimensionalArray.h>
#include <ListNodeAlg.h>
#include <FibonacciArray.h>
#include <cmath>
#include <stack>
using namespace std;

/*
 * 全排列算法
 * **/
char *buf[256];
int num_pos = 0;

void view_all_str(char *bf[],int count){
	for(int loop=0;loop<count;loop++){
		cout<<bf[loop]<<endl;
	}
}


void str_swap(char str[],int pos1,int pos2){
	char tmp = str[pos1];
	str[pos1] = str[pos2];
	str[pos2] = tmp;
}

void Permutation(char str[],int from,int to){
	if(to==0)
		return;
	if(from==to){
		for(int i=0;i<num_pos;i++){
			buf[num_pos] = new char[5];
			if(strcmp(str,buf[i])!=0){
				buf[num_pos] = new char[5];
				strcpy(buf[num_pos],str);
				num_pos++;
			}
		}
		//cout<<str<<endl;
	}
	for(int loop=from;loop<=to;loop++){
		str_swap(str,loop,from);
		Permutation(str,from+1,to);
		str_swap(str,loop,from);
	}
}

void unit_test_Permutation(){
	char test[5] = "ABAB";
	Permutation(test,0,3);
	view_all_str(buf,num_pos);
}
/****全排列算法********/


/****求二进制的1的个数****/

int BitCount(unsigned int n)//这个是错误的解法
{
    unsigned int c =0 ; // 计数器
    while (n >0)
    {
        if((n &1) ==1) // 当前位是1
            ++c ; // 计数器加1
        n >>=1 ; // 移位
    }
    return c ;
}

int NumberOf1(int n) {
	int flag = 1;
	int count = 0;
	while(flag!=0){
		if(n&flag)
		   count++;
		flag = flag<<1; //利用左移而不是错解的右移

		}
	return count;
}

//调整数组使得奇数在前部分，偶数在后部分

int posOfEvenBeforeOdd(vector<int> &array){
	for(unsigned int i=0;i<array.size();++i){
		if(array[i]%2==0&&array[i+1]%2!=0&&i+1<=array.size()-1){
			return i;
		}
	}
	return -1;
}

void swapArrayElem(vector<int> &array,int pos1,int pos2){
	int tmp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = tmp;
}

void reOrderArray(vector<int> &array){
	int pos;
	while((pos = posOfEvenBeforeOdd(array))!=-1){
		swapArrayElem(array,pos,pos+1);
	}
}

void unit_test_reOrderArray(){
	vector<int> ts_array = {1,2,3,4,5,6,7};
	reOrderArray(ts_array);
	for(unsigned int i=0;i<ts_array.size();++i){
		std::cout<<ts_array[i]<<" ";
	}
	std::cout<<std::endl;
}
/***************/

//旋转数组的最小值
/*
 * 对于一般的情况，假设A为输入数组，left 和 right 为数组左右边界的坐标，
 * 考察中间位置的值A[mid] ，如果A[mid] <= A[right]，表明处于递增b，
 * 调整右边界 right = mid；如果A[mid] >= A[left]，表明处于递增a，
 * 因此调整左边界left = mid。当左右边界相邻时，较小的一个就是数组的最小值。
 * 其实，对于一般情况，右边界所指的元素为最小值。
 * */
int findMinInRotateArray(vector<int> &array){
	int posleft = 0;
	int posright = array.size()-1;
	int posmid = (0 + array.size()-1) / 2;
	while(posright - posleft != 1){
		if(array[posmid]<=array[posright])
			posright = posmid;
		else if(array[posmid]>=array[posleft])
			posleft = posmid;
		posmid = posleft + (posright - posleft) / 2;
	}
	return array[posleft]>array[posleft] ? array[posleft] : array[posright];
}

void unit_test_findMinInRotateArray(){
	vector<int> ts_array = {3,4,5,1,2};
	std::cout<<findMinInRotateArray(ts_array)<<std::endl;
}
/***********/

//栈的压入和弹出(采用stack实现)
bool IsPopOrder(vector<int> pushV,vector<int> popV){
	int pos_popV = 0;
	int pos_pushV = 0;
	stack<int> pushStack;
	while(pos_pushV!=pushV.size()){
		pushStack.push(pushV[pos_pushV]);
		if(pushStack.top()==popV[pos_popV]){
			pos_popV++;
			pushStack.pop();
		}
		pos_pushV++;
		std::cout<<pos_pushV<<std::endl;
	}
	while(!pushStack.empty()){
		int tmp;
		tmp = pushStack.top();
		if(tmp==popV[pos_popV]){
			pos_popV++;

		}
		pushStack.pop();
	}

	if(pos_popV==popV.size())
		return true;
	else
		return false;
}

void unit_test_IsPopOrder(){
	vector<int> p = {1,2,3,4,5};
	vector<int> pop = {4,5,3,2,1};
	if(IsPopOrder(p,pop)==true)
		std::cout<<"true"<<std::endl;
	else
		std::cout<<"false"<<std::endl;
}

/************/

int main(){
  std::cout << "hello world" << '\n';
  //unit_test_deleteDuplication();
  //unit_test_Permutation();
  //unit_test_Fibonacci();
  //unit_test_rotatArray();
  //unit_test_rectCover();
  //unit_test_reOrderArray();
  //unit_test_findMinInRotateArray();
  unit_test_IsPopOrder();
  return 0;
}

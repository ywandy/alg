#include <iostream>
#include <vector>
#include <cstring>
#include <2-DimensionalArray.h>
#include <ListNodeAlg.h>
#include <FibonacciArray.h>
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

int  NumberOf1(int n) {
	int flag = 1;
	int count = 0;
	while(flag!=0){
		if(n&flag)
		   count++;
		flag = flag<<1; //利用左移而不是错解的右移

		}
	return count;
}



int main(){
  std::cout << "hello world" << '\n';
  //unit_test_deleteDuplication();
  //unit_test_Permutation();
  unit_test_Fibonacci();
  return 0;
}

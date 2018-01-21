#include <iostream>
#include <vector>
#include <cstring>
#include <2-DimensionalArray.h>
#include <ListNodeAlg.h>
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


int main(){
  std::cout << "hello world" << '\n';
  //unit_test_deleteDuplication();
  unit_test_Permutation();
  return 0;
}

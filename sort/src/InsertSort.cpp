/*
 * InsertSort.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: yewei
 */
#include <InsertSort.h>

//插入排序
void InsertSort(std::vector<int> &inparray){
	unsigned int i,j;
	int tmp;
	for(i=1;i<inparray.size();i++){
		tmp = inparray[i];
		for(j=i;j>0 && tmp<inparray[j-1];j--){
			if(tmp<inparray[j-1]){
				inparray[j] = inparray[j-1];
			}
		}
		inparray[j] = tmp;
	}
}

void unit_test_InsertSort(){
	std::vector<int> ts = {1,4,5,2,3,8,9,0,7};
	show_array(ts);
	InsertSort(ts);
	show_array(ts);
}



/*
 * BubbleSort.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: yewei
 */
#include "BubbleSort.h"


void swap(std::vector<int> &inparray,unsigned int pos_a,unsigned int pos_b){
	if(pos_a>=inparray.size() && pos_b>=inparray.size())
		return;
	int tmp;
	tmp = inparray[pos_a];
	inparray[pos_a] = inparray[pos_b];
	inparray[pos_b] = tmp;
}

void BubbleSort(std::vector<int> &inparray){
	for(unsigned int i=0;i<inparray.size()-1;i++){
		for(unsigned int j=0;j<inparray.size()-1-i;j++){
			if(inparray[j]>inparray[j+1])
				swap(inparray,j,j+1);
		}
	}
}

void unit_test_BubbleSort(){
	std::vector<int> ts = {1,4,5,2,3,8,9,0,7};
	show_array(ts);
	BubbleSort(ts);
	show_array(ts);

}

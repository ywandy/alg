/*
 * 2-DimensionalArray.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: yewei
 */

#include <2-DimensionalArray.h>

/***二维数组查询******/
bool find_target(int target,int cow,int cot,int array[][4]){
	int i,j,pos_cow,pos_cot;
	i=j=0;
	std::cout<<"cows:"<<cow<<" cots:"<<cot<<std::endl;
	for(i=0;i<cow;i++){
		for(j=cot-1;j>=0;j--){
			if(target>array[i][j]){
				break;
			}
			if(target==array[i][j]){
				pos_cow = i+1;
				pos_cot = j+1;
				std::cout<<"pos is:"<<pos_cow<<"  "<<pos_cot<<std::endl;
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
		std::cout<<"有这个整数"<<std::endl;
	else
		std::cout<<"没有这个整数"<<std::endl;
	return 0;
}
/***二维数组查询******/

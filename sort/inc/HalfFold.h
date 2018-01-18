/*
 * HalfFold.h
 *
 *  Created on: Jan 18, 2018
 *      Author: yewei
 */

#ifndef SORT_INC_HALFFOLD_H_
#define SORT_INC_HALFFOLD_H_
#include <iostream>
#include <cstring>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
template<typename RcdType>
class HalfFoldSearch{
	private:
		RcdType *Array;
		RcdType FindKey;
		int ResultIndex;
		int ArraySize;
	public:
		HalfFoldSearch(RcdType Array[],int size);
		~HalfFoldSearch();
		int SearchRecursive(RcdType inp);
		int SearchIteration(RcdType inp);
	private:
		int BinSearch(RcdType Array[],RcdType key,int low,int high);
};

template<typename RcdType>
HalfFoldSearch<RcdType>::HalfFoldSearch(RcdType array[],int size){
	ArraySize = size;
	Array = new RcdType[ArraySize];
	memcpy(Array,array,size*sizeof(int));
	ResultIndex = 0;
	FindKey = 0;
}

template<typename RcdType>
HalfFoldSearch<RcdType>::~HalfFoldSearch(){
	delete Array;
}

template<typename RcdType>
int HalfFoldSearch<RcdType>::SearchRecursive(RcdType inp){
	int res;
	res = BinSearch(Array,inp,0,ArraySize-1);
	if(res==ERROR){
		ResultIndex = 0;
		return ERROR;
	}
	else{
		ResultIndex = res;
		FindKey = inp;
		return ResultIndex;
	}
}

template<typename RcdType>
int HalfFoldSearch<RcdType>::BinSearch(RcdType Array[],RcdType key,int low,int high){
	int mid = (low+high)/2;
	if(low>high) return ERROR;
	if(Array[mid]==key)
		return mid;
	else if(Array[mid]>key)
		return BinSearch(Array,key,low,mid-1);
	else
		return BinSearch(Array,key,mid+1,high);
}

template<typename RcdType>
int HalfFoldSearch<RcdType>::SearchIteration(RcdType inp){
	int mid;
	int low = 0;
	int high = ArraySize - 1;
	while(low<=high){
		mid = (low+high)/2;
		if(Array[mid]==inp){
			ResultIndex = mid;
			FindKey = inp;
			return mid; //找到索引
		}
		else if(Array[mid]>inp) high = mid - 1; //在低半区
		else low = mid + 1; //在高半区
	}
	return ERROR;
}


void HalfFold_unit_test();

#endif /* SORT_INC_HALFFOLD_H_ */

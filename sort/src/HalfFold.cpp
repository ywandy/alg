/*
 * HalfFold.cpp
 *
 *  Created on: Jan 18, 2018
 *      Author: yewei
 */

#include "HalfFold.h"
#include <ctime>
/*
 * 折半查询法 （递归实现和迭代实现）
 * */

void HalfFold_unit_test(){
	clock_t start, finish;
	int array[11];
	array[0]=6;
	array[1]=10;
	array[2]=20;
	array[3]=21;
	array[4]=49;
	array[5]=51;
	array[6]=69;
	array[7]=79;
	array[8]=82;
	array[9]=88;
	array[10]=94;
	HalfFoldSearch<int> *HS = new HalfFoldSearch<int>(array,11);
	start = clock();
	std::cout<<"index is:"<<(*HS).SearchRecursive(51)<<std::endl;
	finish = clock();
	printf( "SearchRecursive using: %f \n", (double)(finish - start) / CLOCKS_PER_SEC );
	start = clock();
	std::cout<<"index is:"<<(*HS).SearchIteration(51)<<std::endl;
	finish = clock();
	printf( "SearchIteration using: %f \n", (double)(finish - start) / CLOCKS_PER_SEC );
}

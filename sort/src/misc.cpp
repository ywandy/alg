/*
 * misc.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: yewei
 */


#include <misc.h>

void show_array(std::vector<int> &inp){
	for(auto it = inp.cbegin();it!=inp.cend();it++){
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}

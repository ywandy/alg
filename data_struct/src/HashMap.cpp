/*
 * HashMap.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: yewei
 */

#include "HashMap.h"

void unit_test_HashMap(){
	HashTable<int,int>  *ts_hash = new HashTable<int,int>(256);
	(*ts_hash).InsertHash(1,10);
	(*ts_hash).InsertHash(2,20);
	(*ts_hash).InsertHash(3,30);
	(*ts_hash).InsertHash(4,40);
	std::cout<<(*ts_hash).SearchHash(1)<<std::endl;
	std::cout<<(*ts_hash).SearchHash(2)<<std::endl;
	std::cout<<(*ts_hash).SearchHash(3)<<std::endl;
	std::cout<<(*ts_hash).SearchHash(4)<<std::endl;
}

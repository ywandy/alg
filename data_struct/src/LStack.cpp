/*
 * LStack.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: yewei
 */

#include <LStack.h>


void unit_test_LStack(){
	LSNode<int> *Ls = new LSNode<int>();
	(*Ls).Push_LS(100);
	(*Ls).Push_LS(200);
	(*Ls).Pop_LS();
	std::cout<<(*Ls).GetTop_LS()<<std::endl;
	std::cout<<(*Ls).StackEmpty_LS()<<std::endl;
	(*Ls).ClearStack_LS();
	std::cout<<(*Ls).StackEmpty_LS()<<std::endl;
	(*Ls).Push_LS(200);
	std::cout<<(*Ls).GetTop_LS()<<std::endl;
}

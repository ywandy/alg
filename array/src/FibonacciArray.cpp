/*
 * FibonacciArray.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: yewei
 */
#include <FibonacciArray.h>
//从第0项开始的Fibonacci数列
int Fibonacci(int n) {
	int a,b,result,i;
	a = 0;
	b = 1;
	if(n==0)
		return a;
	if(n==1)
		return b;
	for(i=2;i<=n;i++){
			result = a + b;
			a = b;
			b = result;
		}
	return result;
}

void unit_test_Fibonacci(){
	std::cout<<"20项的Fib序列，从0开始"<<std::endl;
	for(int i=0 ; i<20 ; i++){
		std::cout<<"第"<<i<<"项:"<<Fibonacci(i)<<std::endl;
	}
}

//普通青蛙跳台阶问题
//能够跳上1级和2级
int jumpFloor(int number) {
    return (Fibonacci(number)+Fibonacci(number-1));
}

void unit_test_jumpFloor1(){
	std::cout<<"普通跳台阶问题"<<std::endl;
	std::cout<<"n为3的时候:"<<jumpFloor(3)<<std::endl;
}

//青蛙跳台阶变态版
//n次跳跃 n个台阶

int jumpFloor2(int number){
	if(number<2)
		return 1;
	else
		return (2*jumpFloor2(number-1));
}

void unit_test_jumpFloor2(){
	std::cout<<"变态跳台阶问题"<<std::endl;
	std::cout<<"n为3的时候:"<<jumpFloor2(3)<<std::endl;
}


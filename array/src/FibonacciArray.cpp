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

//矩形覆盖问题
/*当 n=1 时候，只有一种，就是横着   1
 * 当n=2时候，可以横着放两个，或者竖着放两个   2
 * 当n=3时候，可以在2的基础上加一个横，就是2个，并且可以在1的基础上加两个竖条，因此是3个 F(2)+F(1) = 3
 * 以此类推，是一个Fibonacci数列，因此n个时候，为F(n-1)+F(n-2)
 *
 */

int rectCover(int num){
	if(num==0)
		return 0;
	else if(num==1)
		return 1;
	else if(num==2)
		return 2;
	return rectCover(num-1)+rectCover(num-2);
}

void unit_test_jumpFloor2(){
	std::cout<<"变态跳台阶问题"<<std::endl;
	std::cout<<"n为3的时候:"<<jumpFloor2(3)<<std::endl;
}

void unit_test_rectCover(){
	std::cout<<"矩形覆盖"<<std::endl;
	std::cout<<"n为3的时候:"<<rectCover(3)<<std::endl;
	std::cout<<"n为4的时候:"<<rectCover(4)<<std::endl;
	std::cout<<"n为5的时候:"<<rectCover(5)<<std::endl;
	std::cout<<"n为20的时候:"<<rectCover(20)<<std::endl;

}


/*
 * FibonacciArray.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: yewei
 */



//从第0项开始的Fibonacci数列
int Fibonacci(int n) {
	int f1,f2,t,i;
	f1 = 0;
	f2 = 1;
	if(n==0)
		return f1;
	if(n==1)
		return f2;
	if(n>1){
		for(i=2;i<=n;i++){
			t = f2;
			f2 = f1 + f2;
			f1 = t;
		}
	}
	return f2;
}

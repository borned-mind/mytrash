#include<iostream>
	/*
		delete const, volatile, __unalligned
		return type from const_cast<type>(expression)
		will be pointer, or link, or link to element of data
	*/
int main(void){
	const int * i = new int [1];
	int * b = const_cast<int*>(i);
	b[0]=667;
	std::cout << *i << std::endl;

	const int nA=123;
	int & nB = const_cast<int&>(nA);
	std::cout << nA << std::endl;

}

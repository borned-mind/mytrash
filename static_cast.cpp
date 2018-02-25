#include<iostream>


template<class T> T* fc(T*w){
	return static_cast<int*>(w);
}

int main(void){
	/*
		return type from static_cast<int>(expression)
		can be everything
		using only for static cases
		can use everything dec type, link, pointer, ...
	*/
	double b = 6667.667;
	int a = static_cast<int>(b);
	std::cout << a << std::endl;

	int * b1 = new int[1];
	b1[0]=667;
	int * b2 = fc(b1);
	std::cout << *b2 << std::endl;
	
	
	int const z = 333;
	int z1 = static_cast<int>(z);
	std::cout << z1+1 << std::endl;

}

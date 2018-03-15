#include<future>
#include<iostream>


int main(void){

	auto fut = std::async(std::launch::async, []{return 667;});
	//fut.wait();
	std::cout << fut.get() << std::endl;

}

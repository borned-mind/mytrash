#include<future>
#include<iostream>


int main(void){
	std::promise<int> p;
	std::future<int> fut = p.get_future();
	std::thread( [](std::promise<int>& p){p.set_value(228);}, std::ref(p)).detach(); // terminate called without an active exception -> without detach
//	can after get from future
//	std::future<int> fut = p.get_future();
//	fut.wait();
	std::cout << fut.get() << std::endl;
}

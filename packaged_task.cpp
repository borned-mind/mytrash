#include<future>
#include<iostream>


int main(void){
	std::packaged_task<int()> task([]{return 33;});
	auto fut = task.get_future();
	std::thread( std::move(task) ).detach();
	std::cout << fut.get() << std::endl;
}

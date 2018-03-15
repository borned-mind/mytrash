#include<chrono>
#include<iostream>
#include<ctime>
#include<thread>
#include<vector>
#include<numeric>


template<typename T>
void print_time(){
	auto tm = T::now();
	auto time_t = T::to_time_t(tm);
	std::cout << std::ctime(&time_t) << std::endl;
}

using lli = long long int;

lli sum_long(lli first, lli second){
	return first+second;
}

int main(void){

	print_time<std::chrono::system_clock>();
	//print_time<std::chrono::steady_clock>();
	print_time<std::chrono::high_resolution_clock>();


	std::vector<unsigned long long int> nanoseconds{};
	for(unsigned char i = 10;i--;){
		std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now() ;
        	std::this_thread::sleep_for( std::chrono::seconds(1) );
	        std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

		auto nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds> (end-start) . count();
		std::cout << nanosecond << std::endl;
		nanoseconds.push_back(nanosecond);
	}

	auto sum = std::accumulate(nanoseconds.begin(), nanoseconds.end(), 0, sum_long);
	std::cout << "average of nanoseconds: " <<sum / nanoseconds.size() << std::endl;

}

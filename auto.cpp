#include<array>
#include<iostream>

template <typename T, std::size_t N>
auto getArraySize( T (&)[N] ) -> decltype((int)N){
	return N;
}

template <typename T, int N>
decltype(auto) getArraySizeLink(T (&n)[N]){
	return (n[N-1]);
}



int main(void){

	int arr1[100];
	auto fl = static_cast<float>(2);
	std::cout << typeid(fl).name() << std::endl;
	std::array<int , 5> arr;
	std::cout << getArraySize(arr1) << std::endl << typeid(getArraySize(arr1)).name() << std::endl;
	getArraySizeLink(arr1)=666;
	std::cout << arr1[99] << std::endl;
	auto i={1,2,3,4,5,6,7,8,9}; // std::initializer_list
	std::initializer_list<int>::const_iterator it = i.begin();
	for(it;it!=i.end();it++){
		std::cout << *it << std::endl;
	}

	//auto doub = reinterpret_cast<double>(fl);
	//auto doub = (double)fl;
	
}

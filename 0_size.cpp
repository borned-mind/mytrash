
#include<iostream>
template<class obj, class member>
auto getoffset( member m ) noexcept -> size_t{
	return (size_t) &( ( (obj*)0 )->*m) ;
}

#pragma pack(1)
struct test{
	int a;//4 byte
	char c;//1 byte 
	int b;//4 byte // 5)) on 64 bit will not be lags))
};
#pragma pop

int main(void){
	std::cout << getoffset<test>(&test::a) << std::endl;
	std::cout << getoffset<test>(&test::b) << std::endl;
	std::cout << getoffset<test>(&test::c) << std::endl;
}

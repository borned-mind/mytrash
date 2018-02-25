#include<typeinfo>
#include<iostream>

class BaseClass{
	protected:
		int som;
	public:
		virtual void method() = 0 ;
};

class ChildClass : public BaseClass{
	void method() noexcept override{
		std::cout << "Method was called" << std::endl;
	}
};

unsigned int long fc(void*p){
	/*
		reinterpret_cast
		using for static, return from pointer(type) to dec(type other) 
		return from dec(type) to pointer(type other)
		return from pointer(type) to pointer(type other)
	*/
	unsigned int long result = reinterpret_cast<unsigned int long>(p);
	std::cout << "0x" << std::hex << result << std::endl; // result now have \
	adress of p

	std::cout << "~~~~" << std::endl;
	return ~result<<20>>time(NULL) ^ 0xff ; // = not (result / 2 ^ 20-time) ^ 256
}

int main(void){
	/*
		dynamic_cast
		using for dynamic cast ( I AM CAP)
		in runtime with RTTI(run time type indefication)
		!!! will be pointer or link !!! 
		if cast for pointer failed will return zero(0)
		if cast for link failed will return throw(std::bad_cast) 
		
	*/
	ChildClass c{};
	int i = 7;

	try{
		BaseClass & base = dynamic_cast<BaseClass&>(c);
		std::cout <<  fc(&i)%10 << std::endl;
	}catch(std::bad_cast){
		std::cerr << "Cannot\n";
	}
	std::cout << "Ok\n";

}

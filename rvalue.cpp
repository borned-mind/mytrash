#include<iostream>

void fc(int && val){
	std::cout << val << std::endl;
	val = 3; // but is rvalue, time value 2+2 as example
	std::cout << val << std::endl;
}

class contain{
	public:
		contain(double amount):amount(amount){contain();}
		contain(){std::cout << "Construct\n";}
		contain(contain && a):amount(a.amount){}
		double amount;

		~contain(){std::cout <<"Destruct\n";}
};

int main(void){
	fc(3+3);
	contain s(228);
	contain z(std::move(s)); // not construct
	z.amount=3;


	std::cout << s.amount << ":" << z.amount << " End program" << std::endl;
}

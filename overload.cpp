#include<stdio.h>
#include<stdarg.h>
#define OUTINT(i) printf("%d\n",i);

class SomeClass{
	private:
		int z;
	public:
	SomeClass(void){
		this->z=0;
	}
	SomeClass & operator+(int b){
		z+=b;
	}
	SomeClass & operator<<(int c){
		this->z+=c;
	}
	SomeClass & operator>>(int & c){
		c=this->z;
	}
	void outZ(void){
		OUTINT(this->z);
	}
	template <class T> T fcn(T a, ...){
		T count;
		va_list l;
	
		va_start(l,a);
		do{
			count++;
			OUTINT(a);
		}while(a = va_arg(l, int));
		return count;
	}
};


int main(void){
	
	SomeClass object;
	object.outZ();
	object + 2;
	object.outZ();
	object = object + 100;
	int a=300;
	{
		int a;
		a = 100;
		OUTINT(a);
	}
	OUTINT(a);
	
	object.outZ();
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	object.fcn<int>(1,2,3,4,5,6,7,8,9,123123,123,123123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,0);
	object >> a;
	OUTINT(a);
}

#include<stdio.h>
#include<stdlib.h>

#define GETOFFSET(_struct, _member) (size_t) (  &((_struct*)0)->_member)

struct test{
	//started in 0
	int a;//4 byte
	//started after 3 byte
	char c;//1 byte
	//padding 4 byte but if would me use char after then padding will not exists
	int b;//4 byte // 8
};

int main(void){
//	sizeof(size_t) == sizeof(unsigned long) ? 
//		printf("Size_t equal unsigned long!\n") : 0;
	typedef struct test test;
	printf("a in test is %d\n", GETOFFSET(test, a) ); 
	printf("c in test in %d\n", (size_t)( &( (test*)0)->c) ); // get adress of (test*)->c for 0(base) and c-style_cast to size_t
	printf("b in test is %d\n", GETOFFSET(test,b) );
}

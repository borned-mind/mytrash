#include<stdio.h>

enum somes_enum{
	Some=1<<1L,
	Some2=Some*2,
	Some3=Some2*2,
	Some4=Some3*2
};

/*
#define Some 1L<<0 // 1 * 2^0  = 1
#define Some2 1L<<1 // 1 * 2^1 = 2
#define Some3 1L<<2 // 1 * 2^2 = 4
#define Some4 1L<<3 // 1 * 2^3 = 8
*/

/*
	Some | Some2 = 3 
	3+1 = 2^2 = 1<<2
	
	Some | Some2 | Some3 = 7
	7+1 = 2^3 = 1<<3

	Some | Some2 | Some3 | Some4  = 15
	15+1 = 2^4 = 1<<4

0b1
0b10
0b100
0b1000
0b10000
& 

0<<1 | 1<<1
0b01 |  0b10

0b11 ...




*/
typedef enum{
	false,true
}bool;



void flags(long e){
	bool somes[4];

	#define SOMESSET(index, e, som) somes[index] = (e & som)==som ? true : false;
	SOMESSET(0, e, Some);
	SOMESSET(1, e, Some2);
	SOMESSET(2, e, Some3);
	SOMESSET(3, e, Some4);
	somes[0] ? printf("Some ") : 0;
	somes[1] ? printf("Some2 ") : 0;
	somes[2] ? printf("Some3 ") : 0;
	somes[3] ? printf("Some4 ") : 0;
	puts("");
}

int main(){
	flags(Some);
	flags(Some | Some2);
	flags(Some | Some3);
	flags(Some | Some4);
	
}

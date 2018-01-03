#include<stdio.h>
#include<time.h>
#include<stdlib.h>



template <typename T, class ... Args> int fcn(Args ... args){
	T i[] = {args...};
	for(int z = sizeof(i)/sizeof(T);z--;)
		printf("%d\n",i[z]);
	return sizeof(i)/sizeof(T);
}





int main(int argc, char**argv){
	fcn<int, int, int, int, int, int>(1,2,3,4,5,6,7,8,9,10,11,12,13,14);
	int a,b;
	auto z = [&] {
		srand(time(NULL));
		a= rand() % (rand() / 100);
		b = a * (rand() / 10000);
		return a/b;
	};
	z();
	//int (*check)(int) = [a]{return a*10;};
}

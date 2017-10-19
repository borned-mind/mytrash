#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
typedef long double __attribute__( ( mode(DF) ) ) __attribute__((aligned(64))) float64;
extern float64 factorial ( float64 n);
extern float64 sum(float64 b, ... );

inline float64  
factorial ( float64 n) {
//factorial(float64 n,...){
/*

        va_list l;   
 
        va_start(l,n);

        
	float64 n1
	= va_arg(l,float64);
	va_end(l);	
	if ( !n ) 
		return n1;

	printf("n1 = %f n = %f \n",n1,n);
	if( n1 != 0.0 )
		n1*=n;
	else 
		n1=n; 
	printf("n1 = %f n = %f \n",n1,n);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n",n1,n);
	return factorial(n-1,n1);
*/ // bad implementation printf("%f\n", factorial( atoi(argm[1]), 0.0 ) ); \
 because you are should add in factorial more argumentz(recursive functioion = much times)

float64 result = n;
for(n;n--;)
 result*= n > 0 ? n : 1; // REALLY FAST AND COMPACT?!
return result;
}

inline float64 sum(float64 b, ... ){

	float64 c;

        va_list l;    
        va_start(l,b);
	
	while( c = va_arg(l,float64)  )
	 b+=c;

	va_end(l);
	return b;

}

unsigned long fabinachi(unsigned long to){
	unsigned long a,b,c;
	a = b = c = 1;
	for(unsigned long t = to;to--;){
		c = a + b;
		a=b;
		b=c;
	}
	return c;
}

#define EF(n){\
printf("{");\
for(int d =1;d < n+1;d++)\
	if( d + 1 < n + 1 )\
	 printf("!%d, ",d);\
	else\
	 printf("!%d",d);\
printf("}");\
}

int main(int argc,char**argm){
/*
if(argc < 2) return 0; 
printf("%f\n", factorial( atoi(argm[1]) ) );

EF(10);
printf(" = %f\n",sum(
factorial(10), 
factorial(9),
factorial(8),
factorial(7),
factorial(6),
factorial(5),
factorial(4),
factorial(3),
factorial(2),
factorial(1)
));
*/

}

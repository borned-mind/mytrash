typedef int __attribute__((mode(QI))) byte;
typedef unsigned int __attribute__((mode(QI))) ubyte;
typedef long long __attribute__((mode(DI))) big;
typedef char __attribute__((mode(DI))) bigch;


void not(void * what);
void xor(void * what, big to);
void and(void * what, big with);
void or(void * what,big with);


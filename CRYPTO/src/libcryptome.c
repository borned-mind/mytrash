#include "libcryptome.h"

#define OPERATION(what,operation,to){\
{\
 char * tmp = (char*)what;\
 while(*tmp)\
  *tmp++ = *tmp operation to;\
}\
}


void not(void * what){
{
 char * tmp = (char*)what;
 while(*tmp){
  *tmp = ~*tmp;
  tmp++;
 }

}

}

void xor(void * what, big to){
OPERATION(what,^,to);
}

void and(void * what, big with){
OPERATION(what,&,with);
}

void or(void * what,big with){
OPERATION(what,|,with);
}


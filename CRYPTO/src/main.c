#include "libcryptome.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/*
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
*/

typedef const char * cstring;
typedef char* string;
typedef enum{false,true}bool;

FILE * create_output_file(cstring path);
void serror(string text,...);
string return_name_with_prefix(cstring name,cstring prefix);


inline void serror(string text,...){
va_list vl;
va_start(vl,text);

while(text){
 fprintf(stderr,"%s",text);
 text = va_arg(vl,string);
}

printf("\n");
va_end(vl);
exit(1);

}

string _fr_(cstring path){

//int ds = open(path, O_RDWR | O_APPEND | O_CREAT);
FILE * file = fopen(path,"rwa+");
fseek(file,0,SEEK_END); // SEEK_SET , SEEK_CUR , SEEK_END
long fs = ftell(file);
#ifndef _WIN32 && _WIN64
	char * buf = aligned_alloc(fs+1,1); // char == 1 byte
#else
	char * buf = malloc(fs+1); // char == 1 byte
#endif
void * fb = buf;
rewind(file);

for(long t = fs;t--;)
 *buf++=getc(file);

fclose(file);
*buf++='\0';
//printf("%s\n",(string)fb);
return (string)fb;
}

unsigned long long _strlen_(cstring wh){
 unsigned long long result=0;
 while(*wh++) result++;
 return result;
}



inline string return_name_with_prefix(cstring name,cstring prefix){
 char * result = malloc( _strlen_(name)+_strlen_(prefix)+2 ); //sizeof don't need, \
 because 1 char = 1 byte sizeof(char) * n = n 
 void * fresult = result;
 while(*name) 
  *result++=*name++; 
 while(*prefix)
  *result++=*prefix++;
 *result++='\0';
 return fresult;
}


#define OUTPUTNAME(a) return_name_with_prefix(a,".out");

inline FILE * create_output_file(cstring path){

char * n = OUTPUTNAME(path);
FILE * output = fopen(n,"w");
free(n);
return output;

}

bool parser(unsigned int c,char**a){
 string plaintext = _fr_(a[2]);
// printf("%s\n",plaintext);
 FILE * output = create_output_file(a[2]);
#define fnp(what) what(plaintext,atoi(a[3]));
while(*a[1]){
 switch(*a[1]){

 case '^':
  fnp(xor);
  break;
 case '&':
  fnp(and);
  break;
 case '|':
  fnp(or);
  break;
 case '~':
  for(unsigned int z = atoi(a[3]);z--;)
   not(plaintext);
  break;
 default:
  fclose(output);
  free(plaintext);
  return false;
  //break don't need because return;
 }//switch
*a[1]++;
}//while
#undef fnp
// printf("%s\n",plaintext);
 fwrite((cstring)plaintext,1,_strlen_(plaintext),output);
 free(plaintext);
 fclose(output);

 return true;
}

void main(int ArgCount, char ** Arguments)
{
 if ( ArgCount != 4 ) serror("You Are Should ",Arguments[0]," type(^/&/|/~)"," name ","num",0);
 if ( !parser(ArgCount,Arguments) ) serror("Sorry, undefined type\n");
 puts(Arguments[2]);
}


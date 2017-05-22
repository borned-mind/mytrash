#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TESTFILE "test.txt"

int main(int argcount,char**arguments)
{
//if(argcount < 3) return 0;


//int to = creat("to.txt", S_IRWXU | S_IRWXG | S_IRWXO);
int to = open("to.txt",O_APPEND | O_CREAT | O_WRONLY ,S_IRWXU | S_IRWXG | S_IRWXO);
int from = open(TESTFILE,O_RDONLY);
if(to == -1 || from == -1)
{
fprintf(stderr,"Not can create a f-descript\n");
exit(-1);
}
/*
              S_IRWXU  00700 user (file owner) has read, write, and execute permission
              S_IRWXG  00070 group has read, write, and execute permission
              S_IRWXO  00007 others have read, write, and execute permission

*/
int child_fildes[2];
int child_fdscriptors = pipe(child_fildes); //shitcode one love
#warning as i understand pipe \
not work as could work, need create two fildes from child/parent \
but i not be do this, because i know and this test code.
/*
FILE * from = fopen("test.txt","r");
FILE * to = fopen("to.txt","a+");
char ch;
while((ch = fgetc(from))!= EOF)
 {
	putc(ch,to);
 }
*/
pid_t _read = fork();
char buffer[4096];

if(!_read) // child
{
printf("child\n");
close( child_fildes[0] ); // child in
dup2(child_fildes[0],fileno(stdin)); // not this child_fildes 0 == stdin

do
{
bzero(buffer,4096);
read(from,&buffer,4095);
write(child_fildes[1],buffer,strlen(buffer));
}while(*buffer);

}else if(_read>0){
printf("parent\n");
bzero(buffer,4096);
read(child_fildes[0],&buffer,4095);
printf("Write to file %s\n",buffer);
write(to,buffer,strlen(buffer));
}else
{
fprintf(stderr,"Not can create a fork\n");
exit(-1);
}
close(from);
fsync(to);
close(to);



}

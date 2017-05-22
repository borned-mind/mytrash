#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
static pthread_t Divide;

void notAllowDivideAZero(void)
{
fprintf(stderr,"You are divide to zero, this not GOOD!\n");
pthread_cancel(Divide);
}

void _div(int i)
{
int result = 1/i;
return result;
}

void _alarm_(void)
{
printf("stop a program.\n");
exit(1);
}
void killed(void)
{
fprintf(stdout,"Stopping\n");
}

void main(void)
{
//void (*notAllow)(int) = &notAllowDivideAZero;
signal(SIGFPE,notAllowDivideAZero);
signal(SIGALRM,_alarm_);
pthread_create(&Divide,NULL,_div,0);
pthread_join(Divide,NULL);
alarm(15);
while(1);
}


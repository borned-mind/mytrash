#include<sys/io.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	char buf[2];

	FILE * ports
		=fopen("/dev/port", "rwb");
	fseek(ports, 0x378, SEEK_SET);
	fread(buf, sizeof buf, 1, ports);
	printf("Answer is %s\n", buf);

//Other 
	ioperm(0x378, 10, 1); // give x378-x388 allow write/read from ports
	//char answ = inb(0x378); // read from 0x378
	insb(0x378, buf, sizeof buf);

}

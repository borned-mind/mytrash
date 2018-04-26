#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <netdb.h>

int main(void){
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock == -1) return fprintf(stderr, "Can't open socket\n");
struct	sockaddr_in addr;

	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(3232);

	if( bind(sock, (struct sockaddr*)&addr, sizeof(addr)) == 1) return fprintf(stderr, "Can't bind to 127.0.0.1:3232\n");
	//if( listen(sock,100) == -1) return fprintf(stderr, "Can't listen 100 clients"); // 100 client for tcp
	for(auto i=3;i--;){
		char * buf = calloc(sizeof(char),1024);
		struct sockaddr_in src_addr;
		socklen_t size = sizeof(src_addr);

		if( recvfrom(sock, buf, 1024, 0, (struct sockaddr*)&src_addr, &size ) == -1) {
			fprintf(stderr, "Can't read\n");
			continue;
		}



		sendto( sock, "ECHO: ", 6, 0, (struct sockaddr*)&src_addr, size);
		sendto(sock, buf, 1024, 0, (struct sockaddr*)&src_addr, size);
		printf("Client %s:%d write %s\n", inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port), buf);
		free(buf);
	}
	close(sock);
	memset(&addr, 0, sizeof(addr));

	puts("Set struct");
	addr.sin_family=AF_INET;
	
	struct hostent * serv = gethostbyname("google.com");
	char ** s = &serv->h_addr;	
	struct 	sockaddr_in ips;
	while(*s){
		char ip[16];
		ips.sin_addr = *((struct in_addr*)s);
		puts("IP:");
		inet_ntop(AF_INET, &ips.sin_addr, ip, sizeof(ip) );
		puts(ip);
		s++;
	}

	puts("memcpy");
	memcpy( &addr.sin_addr, serv->h_addr, serv->h_length );
	
	addr.sin_port=htons(80);
	puts("Connecting...");
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if( connect(sock, (struct sockaddr*)&addr, sizeof(addr) ) == -1) return fprintf(stderr, "Can't connect to google.com 80\n");
	write(sock, "GET /\r\n\r\n", sizeof("GET /\r\n\r\n") );
	char buf[1024];
	read(sock, buf, sizeof(buf));
	puts(buf);
	close(sock);

	sock = socket(AF_INET, SOCK_STREAM,0);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	addr.sin_port=htons(3232);
	addr.sin_family=AF_INET;
	socklen_t sz = sizeof(addr);



	if( bind(sock, (struct sockaddr*)&addr, sizeof(addr) ) == -1) return fprintf(stderr,"cant' bind to localhost 3232\n");
	listen(sock, 10);
	while(1){
		struct sockaddr_in client_addr;
		sz=sizeof(client_addr);

		int client = accept( sock, (struct sockaddr*)&client_addr, &sz) ;
		if(client == -1) return fprintf(stderr, "Can't accept\n");

		printf("New client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
		write(client, "hello\n", sizeof("hello\n"));
		char buf[1024];
		read(client, buf, 1024);
		puts(buf);
		close(client);
	}
 	
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024   /*客户端发送和接收数据缓冲区的大小*/

int main(int argc,char **argv)
{
		int sockfd,port,addrlen,n;
		char buffer[MAX_BUF_SIZE];
		struct sockaddr_in addr;
		if(argc!=3)
		{
			printf("Usage:%s server_ip server_port\n",argv[0]);
			exit(1);
		}
		if((port=atoi(argv[2]))<0) 
		{   /*命令行的第三个参数为数据将要发送到的服务器端口号*/
			printf("Usage:%s server_ip server_port\n",argv[0]);
			exit(1);
		}
		sockfd=socket(AF_INET,SOCK_DGRAM,0);  /*建立客户端socket*/
		if(sockfd<0)
		{
			printf("Socket error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Creat client socket success! Socket id: %d\n", sockfd);
		addrlen=sizeof(struct sockaddr_in); 
		bzero(&addr,addrlen); 
		/*客户端填充 sockaddr结构*/
		addr.sin_family=AF_INET; 
		addr.sin_port=htons(port); 
		if(inet_aton(argv[1],&addr.sin_addr)<0) 
		{  /*命令行的第三个参数为数据将要发送到的服务器IP地址*/
			printf("Ip error:%s\n",strerror(errno)); 
			exit(1);
		} 
		while(1)
		{
			bzero(buffer,MAX_BUF_SIZE); /*接收数据之前先将缓冲区清零*/
			printf("Client endpoint input message[<1024 bytes]: ");
			fgets(buffer,MAX_BUF_SIZE,stdin);  /*从键盘读入，发送到服务器端*/
			sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)(&addr),addrlen);
			/*从网络中读取数据，并打印出接收到的数据*/
			n=recvfrom(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)(&addr),&addrlen);
			printf("Receive message from server: %s",buffer);
		}
		close(sockfd);  /*通信结束，关闭套接字*/
		return 0;
}

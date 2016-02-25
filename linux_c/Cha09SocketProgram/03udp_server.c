#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER_PORT 8000    /*定义端口号*/
#define MAX_MSG_SIZE 1024   /*服务器发送和接收数据缓冲区的大小*/

int main(void)
{
		int sockfd,addrlen,n;
		struct sockaddr_in addr;   /*定义服务器端套接字地址数据结构addr */
		char msg[MAX_MSG_SIZE];
		sockfd=socket(AF_INET,SOCK_DGRAM,0); /*服务器端开始建立socket描述符*/
		if(sockfd<0)
		{
			printf("Socket error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Creat server socket success! Socket id: %d\n", sockfd);
		addrlen=sizeof(struct sockaddr_in);
		bzero(&addr,addrlen);
		/*服务器端填充 sockaddr结构*/
		addr.sin_family=AF_INET;
		addr.sin_addr.s_addr=htonl(INADDR_ANY);
		addr.sin_port=htons(SERVER_PORT);
		if(bind(sockfd,(struct sockaddr *)(&addr),addrlen)<0)  /*调用bind函数绑定端口*/
		{
			printf("Bind error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Bind port success! local port: %d\n", SERVER_PORT);
		while(1)   /*从网络中读取数据，并打印出接收到的数据*/
		{
			bzero(msg,MAX_MSG_SIZE);  /*接收数据之前先将缓冲区清零*/
			n=recvfrom(sockfd,msg,sizeof(msg),0,(struct sockaddr*)(&addr),&addrlen); 
			printf("Receive message from client: %s",msg);
			/*从终端读入用户输入的数据，发送到网络中去*/
			printf("Server endpoint input message[<1024 bytes]: ");
			fgets(msg,MAX_MSG_SIZE,stdin);
			sendto(sockfd,msg,n,0,(struct sockaddr*)(&addr),addrlen); 
		}
		close(sockfd); /*通信结束，关闭套接字*/
		return 0;
}

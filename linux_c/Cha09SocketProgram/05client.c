#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024     /*缓冲区大小*/

int main(int argc, char *argv[])
{
		int sockfd;
		char buffer[BUFSIZE];
		struct sockaddr_in server_addr; /*定义服务器端套接字数据结构server_addr */
		struct hostent *hostname;
		int portnumber,nbytes;
		if(argc!=3)
		{
			printf("Arguments error! Usage: %s hostname portnumber\n",argv[0]);
			exit(1);
		}
		if((hostname=gethostbyname(argv[1]))==NULL)/*获得命令行第二个参数——主机名*/
		{
			printf("Get hostname error\n");
			exit(1);
		}
		/*获得命令行的第三个参数--端口号，atoi()把字符串转换成整型数*/
		if((portnumber=atoi(argv[2]))<0)
		{
			printf("Usage:%s hostname portnumber\n",argv[0]);
			exit(1);
		}
		if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)   /*创建客户端Socket*/
		{
			perror("Create client socket error!\n");
			exit(1);
		} 
		else       /*Socket创建成功*/
		{
			printf("Creat client socket success! Client socket id: %d\n", sockfd);
		}
		/*客户程序填充服务端的资料*/
		bzero(&server_addr,sizeof(server_addr));
		server_addr.sin_family=AF_INET;
		server_addr.sin_port=htons(portnumber);
		server_addr.sin_addr=*((struct in_addr *)hostname->h_addr);
		/*客户程序发起连接请求*/
		if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
		{
			perror("Connect error:%s\n");
			exit(1);
		}
		/*提示用户输入将要发送的数据，长度小于缓冲区的长度，即1024字节*/
		printf("Connect successful, input the mesage[<1024 bytes] send to server:\n");
		gets(buffer);
		if(write(sockfd,buffer,sizeof(buffer))==-1)   /*调用write发送数据*/
		{
			perror("Write error on client.\n"); 
			exit(1);
		}
		/*调用read读取服务器发送来的数据*/
		if((nbytes=read(sockfd,buffer,BUFSIZE))==-1)
		{
			perror("Read error from server.\n");
			exit(1);
		}
		buffer[nbytes]='\0';
		printf("Client %d receive message from server: %s\n", sockfd, buffer);
		close(sockfd);   /*结束通信，关闭客户端套接字*/ 
		return 0;
}

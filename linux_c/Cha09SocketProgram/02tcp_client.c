#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#define BUFSIZE 1024     /*定义数据缓冲区大小*/

int main(int argc, char *argv[])
{
		int sockfd;
		char buffer[BUFSIZE];
		struct sockaddr_in server_addr; /*定义服务器端套接字数据结构server_addr */
		struct hostent *hostname;
		int portnumber,nbytes;
		if(argc!=3)
		{
			printf("argc = %d\n",argc);
			printf("Arguments error! Usage: %s hostname portnumber\n",argv[0]);
			exit(1);
		}
		if((hostname=gethostbyname(argv[1]))==NULL)/*获得命令行第二个参数——主机名*/
		{
			printf("Get hostname error\n");
			exit(1);
		}
		/*获得命令行的第三个参数——端口号，atoi()把字符串转换成整型数*/
		if((portnumber=atoi(argv[2]))<0)
		{
			printf("Usage:%s hostname portnumber\n",argv[0]);
			exit(1);
		}
		/* 客户程序开始建立 sockfd描述符 */
		if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
		{
			printf("Create socket error:%s\n",strerror(errno));
			exit(1); 
		}
		printf("Creat client socket success! Socket id: %d\n", sockfd);
		/*客户程序填充服务端的资料*/
		bzero(&server_addr,sizeof(server_addr));
		server_addr.sin_family=AF_INET;
		server_addr.sin_port=htons(portnumber);
		server_addr.sin_addr=*((struct in_addr *)hostname->h_addr);
		/*客户程序发起连接请求*/
		if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
		{
			printf("Connect error:%s\n",strerror(errno));
			exit(1);
		}
		/*连接成功，调用read读取服务器发送来的数据*/
		while(1)
		{
			if(read(sockfd,buffer,BUFSIZE)==-1)
			{
				printf("Read error:%s\n",strerror(errno));
				exit(1);
			}
			if(strlen(buffer)!=0)
			{
				buffer[nbytes]='\0';
				printf("I have received:%s\n",buffer);   /*输出接收到的数据*/

			}
			printf("please input the mesage[<1024 bytes]:\n");
                                  /*提示用户输入将要发送的数据，长度小于缓冲区的长度，即1024字节*/
                        if(fgets(buffer, sizeof(buffer), stdin) != buffer)
                        {  /*从终端输入的数据存放在buf缓冲区*/
                                  printf("fgets error!\n");
                                  exit(1);
                        }
                        if(write(sockfd,buffer,strlen(buffer))==-1)   /*调用write发送数据*/
                        {
                                  printf("Write error:%s\n",strerror(errno));
                                  exit(1);
                        }
	
		}
		/*
		if((nbytes=read(sockfd,buffer,BUFSIZE))==-1)
		{
			printf("Read error:%s\n",strerror(errno));
			exit(1);
		}
		if(strlen(buffer)!=0)
		{
			buffer[nbytes]='\0';
			printf("I have received:%s\n",buffer);   /*输出接收到的数据*/
		//}
		close(sockfd);   /*结束通信*/
		return 0;
}			

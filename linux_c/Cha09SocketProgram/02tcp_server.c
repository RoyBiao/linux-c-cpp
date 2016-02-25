#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#define BUFSIZE 1024     /*定义数据缓冲区大小*/

int main(int argc, char *argv[])
{
		int sockfd,newsockfd;
		struct sockaddr_in server_addr;   /*定义服务器端套接字数据结构server_addr */
		struct sockaddr_in client_addr;   /*定义客户端套接字数据结构client_addr */
		int portnumber;
		char buf[BUFSIZE];     /*发送数据缓冲区*/
		int addr_len = sizeof(struct sockaddr_in);
		if(argc!=2)       /*判断命令行参数*/
		{
			printf("argc = %d\n",argc);
			printf("Arguments error! gsage: %s portnumber\n",argv[0]);
			exit(1);
		}
		/*获得命令行的第二个参数——端口号，atoi()把字符串转换成整型数*/
		if((portnumber=atoi(argv[1]))<0) 
		{
			printf("argc = %d\n",argc);
			printf("Portnumber error! Usage: %s portnumber\n",argv[0]);
			exit(1);
		}
		if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) /*创建服务器端Socket*/
		{
			printf("Create socket error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Creat server socket success! Socket id: %d\n", sockfd);
		/*服务器端填充 sockaddr结构*/
		bzero(&server_addr,sizeof(struct sockaddr_in)); /*先将套接字地址数据结构清零*/
		server_addr.sin_family=AF_INET;
		server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
		server_addr.sin_port=htons(portnumber);
		if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
										   /*调用bind函数绑定端口*/
		{
			printf("Bind error:%s\n",strerror(errno)); 
			exit(1); 
		}
		printf("Bind port success! local port: %d\n", portnumber);
		if(listen(sockfd,5)==-1)  /*监听sockfd描述符，同时处理的最大连接请求数为5 */
		{
			printf("Listen error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Listenning......\n");    /*端口监听中......*/
		while(1)      /*服务器阻塞，等待接收连接请求，直到客户程序发送连接请求*/
		{
			if((newsockfd=accept(sockfd,(struct sockaddr *)(&client_addr),&addr_len))==-1)
			/*调用accept接受一个连接请求*/
			{
				printf("Accept error:%s\n",strerror(errno)); 
				exit(1); 
			}
			printf("Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));
			/*TCP连接已建立，打印申请连接的客户机的IP地址*/
			printf("Connected successful, please input the mesage[<1024 bytes]:\n");
				/*提示用户输入将要发送的数据，长度小于缓冲区的长度，即1024字节*/
			if(fgets(buf, sizeof(buf), stdin) != buf)
			{  /*从终端输入的数据存放在buf缓冲区*/
				printf("fgets error!\n");
				exit(1);
			}
			if(write(newsockfd,buf,strlen(buf))==-1)   /*调用write发送数据*/
			{
				printf("Write error:%s\n",strerror(errno)); 
				exit(1);
			}
			if(read(newsockfd,buf,strlen(buf))!=-1)
			{
				printf("read data %s\n",buf);
			} 
			close(newsockfd);  /*通信已结束，关闭客户端的套接字，并循环下一次等待*/
		}
		close(sockfd);  /*服务器进程结束，关闭服务器端套接字*/
		return 0;
}

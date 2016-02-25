#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

#define PORT 3000          /*端口号*/
#define BUFSIZE 1024       /*缓冲区大小*/
#define MAXSELECT 100    /*最大连接数*/

int main(void)
{
		int listenfd, connfd, sockfd;    	 /*定义套接字描述符*/
		struct sockaddr_in server_addr;   /*服务器端套接字数据结构server_addr */
		struct sockaddr_in client_addr;   /*客户端套接字数据结构client_addr */
		int addr_len = sizeof(struct sockaddr_in);
		int i, maxfd, maxi=-1, nready=0;
		fd_set allset,readfds;
		int client[MAXSELECT];
		char buffer[BUFSIZE];
		ssize_t nbytes;
		
		if((listenfd = socket(AF_INET,SOCK_STREAM,0))==-1)  /*创建监听Socket*/
		{
			perror("Creat listen socket error!");
			exit(1);
		}
		else       /*Socket创建成功*/
		{
			printf("Creat listen socket success! Listen socket id: %d\n", listenfd);
		}
		bzero(&server_addr,addr_len);         /*清空表示地址的结构体变量*/
		server_addr.sin_family = AF_INET;     /*设置addr的成员信息*/
		server_addr.sin_port = htons(PORT);
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP地址设为本机IP*/
		if(bind(listenfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr))==-1)
										/*调用bind函数绑定端口*/
		{
			perror("Bind error!");
			exit(1);
		}
		else       /*端口绑定成功*/
		{
			printf("Bind port success! Local port: %d\n", PORT);
		}
		/*调用listen监听端口号，能同时处理的最大连接请求数为100*/
		if(listen(listenfd,MAXSELECT)==-1)
		{
			perror("Listen error!");
			exit(1);
		}
		
		maxfd = listenfd;
		FD_ZERO(&allset);   /*初始化描述符集*/
		FD_SET(listenfd, &allset);   /*将监听Socket加入描述符集*/
		for(i=0; i<MAXSELECT; i++) /*初始化客户数组，-1表示该项没有被登记*/
			client[i] = -1;
		
		while(1)     /*服务器开始监听*/
		{
			printf("Listenning......\n");    /*监听中......*/
			readfds = allset;
			nready = select(maxfd+1, &readfds, NULL, NULL, NULL);
			if(FD_ISSET(listenfd, &readfds))
			{
				/*再次检查是否有可读的套接字，若没有，则继续等待下一个就绪套接字*/
				if(nready <= 0) 
					continue;
				nready--;
				if((connfd = accept(listenfd,(struct sockaddr *)(&client_addr),&addr_len))==-1)
											/*调用accept接受一个连接请求*/
				{
					perror("Accept new client error!");
					continue;         /*接受失败，继续等待*/
				}
				else   /*已接受连接请求*/
				{
					printf("Accepted a new connect. Client socket id: %d\n", connfd);
				}
				for(i=0; i<MAXSELECT; i++)   /*将新的客户加入客户数组*/
				{
					if(client[i] < 0)
					{
						client[i] = connfd;
						break;
					}
				}
				if(i == MAXSELECT)
				{
					printf("Too many clients, server stopped!\n");
					exit(1);
				}
				FD_SET(connfd, &readfds);  /*将这个新连接的套接字添加至描述符集*/
				if(connfd > maxfd)    /*更新描述符集中的最大值*/
					maxfd = connfd;
				if(i > maxi)
					maxi = i;   /*记录当前最大客户数*/
				printf("There are %d client(s) connect to server.\n",maxi+1);
				for(i=0; i<=maxi; i++)
				{
					if((sockfd = client[i]) < 0)  /*无效的客户记录*/
						continue;
					if(FD_ISSET(sockfd, &readfds))   /*判断是否有套接字可读*/
					{
						printf("Serving on client %d...\n",sockfd);
/*接收数据出错，或已读到文件尾，则关闭该套接字，并将它从就绪集合中清除，继续处理下一个客户*/
						if((nbytes = read(sockfd,buffer,BUFSIZE))<=0)
						{
							close(sockfd);
							FD_CLR(sockfd, &allset);
							client[i] = -1;
							continue;
						}
						else   /*成功接收客户端的数据*/
						{
							buffer[nbytes]='\0';
							printf("OK! Receive message from client %d: %s\n", 
sockfd, buffer);
							printf("Input the mesage[<1024 bytes] send to client %d:\n",
sockfd);
							gets(buffer);
							if(write(sockfd,buffer,sizeof(buffer))==-1) /*发送数据*/
							{
								perror("Write error on server:%s\n");
								break;
							}
						}
						if(nready <= 0)
							break;
					}
				}
			}
			close(connfd);
			FD_CLR(connfd, &allset);
		}
		close(listenfd);
		FD_CLR(listenfd, &allset);
		return 0;
}

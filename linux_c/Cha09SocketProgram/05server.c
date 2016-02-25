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

#define PORT 3000          /*�˿ں�*/
#define BUFSIZE 1024       /*��������С*/
#define MAXSELECT 100    /*���������*/

int main(void)
{
		int listenfd, connfd, sockfd;    	 /*�����׽���������*/
		struct sockaddr_in server_addr;   /*���������׽������ݽṹserver_addr */
		struct sockaddr_in client_addr;   /*�ͻ����׽������ݽṹclient_addr */
		int addr_len = sizeof(struct sockaddr_in);
		int i, maxfd, maxi=-1, nready=0;
		fd_set allset,readfds;
		int client[MAXSELECT];
		char buffer[BUFSIZE];
		ssize_t nbytes;
		
		if((listenfd = socket(AF_INET,SOCK_STREAM,0))==-1)  /*��������Socket*/
		{
			perror("Creat listen socket error!");
			exit(1);
		}
		else       /*Socket�����ɹ�*/
		{
			printf("Creat listen socket success! Listen socket id: %d\n", listenfd);
		}
		bzero(&server_addr,addr_len);         /*��ձ�ʾ��ַ�Ľṹ�����*/
		server_addr.sin_family = AF_INET;     /*����addr�ĳ�Ա��Ϣ*/
		server_addr.sin_port = htons(PORT);
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY); /*IP��ַ��Ϊ����IP*/
		if(bind(listenfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr))==-1)
										/*����bind�����󶨶˿�*/
		{
			perror("Bind error!");
			exit(1);
		}
		else       /*�˿ڰ󶨳ɹ�*/
		{
			printf("Bind port success! Local port: %d\n", PORT);
		}
		/*����listen�����˿ںţ���ͬʱ������������������Ϊ100*/
		if(listen(listenfd,MAXSELECT)==-1)
		{
			perror("Listen error!");
			exit(1);
		}
		
		maxfd = listenfd;
		FD_ZERO(&allset);   /*��ʼ����������*/
		FD_SET(listenfd, &allset);   /*������Socket������������*/
		for(i=0; i<MAXSELECT; i++) /*��ʼ���ͻ����飬-1��ʾ����û�б��Ǽ�*/
			client[i] = -1;
		
		while(1)     /*��������ʼ����*/
		{
			printf("Listenning......\n");    /*������......*/
			readfds = allset;
			nready = select(maxfd+1, &readfds, NULL, NULL, NULL);
			if(FD_ISSET(listenfd, &readfds))
			{
				/*�ٴμ���Ƿ��пɶ����׽��֣���û�У�������ȴ���һ�������׽���*/
				if(nready <= 0) 
					continue;
				nready--;
				if((connfd = accept(listenfd,(struct sockaddr *)(&client_addr),&addr_len))==-1)
											/*����accept����һ����������*/
				{
					perror("Accept new client error!");
					continue;         /*����ʧ�ܣ������ȴ�*/
				}
				else   /*�ѽ�����������*/
				{
					printf("Accepted a new connect. Client socket id: %d\n", connfd);
				}
				for(i=0; i<MAXSELECT; i++)   /*���µĿͻ�����ͻ�����*/
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
				FD_SET(connfd, &readfds);  /*����������ӵ��׽����������������*/
				if(connfd > maxfd)    /*�������������е����ֵ*/
					maxfd = connfd;
				if(i > maxi)
					maxi = i;   /*��¼��ǰ���ͻ���*/
				printf("There are %d client(s) connect to server.\n",maxi+1);
				for(i=0; i<=maxi; i++)
				{
					if((sockfd = client[i]) < 0)  /*��Ч�Ŀͻ���¼*/
						continue;
					if(FD_ISSET(sockfd, &readfds))   /*�ж��Ƿ����׽��ֿɶ�*/
					{
						printf("Serving on client %d...\n",sockfd);
/*�������ݳ������Ѷ����ļ�β����رո��׽��֣��������Ӿ������������������������һ���ͻ�*/
						if((nbytes = read(sockfd,buffer,BUFSIZE))<=0)
						{
							close(sockfd);
							FD_CLR(sockfd, &allset);
							client[i] = -1;
							continue;
						}
						else   /*�ɹ����տͻ��˵�����*/
						{
							buffer[nbytes]='\0';
							printf("OK! Receive message from client %d: %s\n", 
sockfd, buffer);
							printf("Input the mesage[<1024 bytes] send to client %d:\n",
sockfd);
							gets(buffer);
							if(write(sockfd,buffer,sizeof(buffer))==-1) /*��������*/
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

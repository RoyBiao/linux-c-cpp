#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#define BUFSIZE 1024     /*�������ݻ�������С*/

int main(int argc, char *argv[])
{
		int sockfd;
		char buffer[BUFSIZE];
		struct sockaddr_in server_addr; /*������������׽������ݽṹserver_addr */
		struct hostent *hostname;
		int portnumber,nbytes;
		if(argc!=3)
		{
			printf("argc = %d\n",argc);
			printf("Arguments error! Usage: %s hostname portnumber\n",argv[0]);
			exit(1);
		}
		if((hostname=gethostbyname(argv[1]))==NULL)/*��������еڶ�����������������*/
		{
			printf("Get hostname error\n");
			exit(1);
		}
		/*��������еĵ��������������˿ںţ�atoi()���ַ���ת����������*/
		if((portnumber=atoi(argv[2]))<0)
		{
			printf("Usage:%s hostname portnumber\n",argv[0]);
			exit(1);
		}
		/* �ͻ�����ʼ���� sockfd������ */
		if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
		{
			printf("Create socket error:%s\n",strerror(errno));
			exit(1); 
		}
		printf("Creat client socket success! Socket id: %d\n", sockfd);
		/*�ͻ�����������˵�����*/
		bzero(&server_addr,sizeof(server_addr));
		server_addr.sin_family=AF_INET;
		server_addr.sin_port=htons(portnumber);
		server_addr.sin_addr=*((struct in_addr *)hostname->h_addr);
		/*�ͻ���������������*/
		if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
		{
			printf("Connect error:%s\n",strerror(errno));
			exit(1);
		}
		/*���ӳɹ�������read��ȡ������������������*/
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
				printf("I have received:%s\n",buffer);   /*������յ�������*/

			}
			printf("please input the mesage[<1024 bytes]:\n");
                                  /*��ʾ�û����뽫Ҫ���͵����ݣ�����С�ڻ������ĳ��ȣ���1024�ֽ�*/
                        if(fgets(buffer, sizeof(buffer), stdin) != buffer)
                        {  /*���ն���������ݴ����buf������*/
                                  printf("fgets error!\n");
                                  exit(1);
                        }
                        if(write(sockfd,buffer,strlen(buffer))==-1)   /*����write��������*/
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
			printf("I have received:%s\n",buffer);   /*������յ�������*/
		//}
		close(sockfd);   /*����ͨ��*/
		return 0;
}			

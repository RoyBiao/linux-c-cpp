#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024     /*��������С*/

int main(int argc, char *argv[])
{
		int sockfd;
		char buffer[BUFSIZE];
		struct sockaddr_in server_addr; /*������������׽������ݽṹserver_addr */
		struct hostent *hostname;
		int portnumber,nbytes;
		if(argc!=3)
		{
			printf("Arguments error! Usage: %s hostname portnumber\n",argv[0]);
			exit(1);
		}
		if((hostname=gethostbyname(argv[1]))==NULL)/*��������еڶ�����������������*/
		{
			printf("Get hostname error\n");
			exit(1);
		}
		/*��������еĵ���������--�˿ںţ�atoi()���ַ���ת����������*/
		if((portnumber=atoi(argv[2]))<0)
		{
			printf("Usage:%s hostname portnumber\n",argv[0]);
			exit(1);
		}
		if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)   /*�����ͻ���Socket*/
		{
			perror("Create client socket error!\n");
			exit(1);
		} 
		else       /*Socket�����ɹ�*/
		{
			printf("Creat client socket success! Client socket id: %d\n", sockfd);
		}
		/*�ͻ�����������˵�����*/
		bzero(&server_addr,sizeof(server_addr));
		server_addr.sin_family=AF_INET;
		server_addr.sin_port=htons(portnumber);
		server_addr.sin_addr=*((struct in_addr *)hostname->h_addr);
		/*�ͻ���������������*/
		if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
		{
			perror("Connect error:%s\n");
			exit(1);
		}
		/*��ʾ�û����뽫Ҫ���͵����ݣ�����С�ڻ������ĳ��ȣ���1024�ֽ�*/
		printf("Connect successful, input the mesage[<1024 bytes] send to server:\n");
		gets(buffer);
		if(write(sockfd,buffer,sizeof(buffer))==-1)   /*����write��������*/
		{
			perror("Write error on client.\n"); 
			exit(1);
		}
		/*����read��ȡ������������������*/
		if((nbytes=read(sockfd,buffer,BUFSIZE))==-1)
		{
			perror("Read error from server.\n");
			exit(1);
		}
		buffer[nbytes]='\0';
		printf("Client %d receive message from server: %s\n", sockfd, buffer);
		close(sockfd);   /*����ͨ�ţ��رտͻ����׽���*/ 
		return 0;
}

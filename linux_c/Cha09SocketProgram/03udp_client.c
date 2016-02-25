#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024   /*�ͻ��˷��ͺͽ������ݻ������Ĵ�С*/

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
		{   /*�����еĵ���������Ϊ���ݽ�Ҫ���͵��ķ������˿ں�*/
			printf("Usage:%s server_ip server_port\n",argv[0]);
			exit(1);
		}
		sockfd=socket(AF_INET,SOCK_DGRAM,0);  /*�����ͻ���socket*/
		if(sockfd<0)
		{
			printf("Socket error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Creat client socket success! Socket id: %d\n", sockfd);
		addrlen=sizeof(struct sockaddr_in); 
		bzero(&addr,addrlen); 
		/*�ͻ������ sockaddr�ṹ*/
		addr.sin_family=AF_INET; 
		addr.sin_port=htons(port); 
		if(inet_aton(argv[1],&addr.sin_addr)<0) 
		{  /*�����еĵ���������Ϊ���ݽ�Ҫ���͵��ķ�����IP��ַ*/
			printf("Ip error:%s\n",strerror(errno)); 
			exit(1);
		} 
		while(1)
		{
			bzero(buffer,MAX_BUF_SIZE); /*��������֮ǰ�Ƚ�����������*/
			printf("Client endpoint input message[<1024 bytes]: ");
			fgets(buffer,MAX_BUF_SIZE,stdin);  /*�Ӽ��̶��룬���͵���������*/
			sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)(&addr),addrlen);
			/*�������ж�ȡ���ݣ�����ӡ�����յ�������*/
			n=recvfrom(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)(&addr),&addrlen);
			printf("Receive message from server: %s",buffer);
		}
		close(sockfd);  /*ͨ�Ž������ر��׽���*/
		return 0;
}

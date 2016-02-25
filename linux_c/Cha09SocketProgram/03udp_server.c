#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER_PORT 8000    /*����˿ں�*/
#define MAX_MSG_SIZE 1024   /*���������ͺͽ������ݻ������Ĵ�С*/

int main(void)
{
		int sockfd,addrlen,n;
		struct sockaddr_in addr;   /*������������׽��ֵ�ַ���ݽṹaddr */
		char msg[MAX_MSG_SIZE];
		sockfd=socket(AF_INET,SOCK_DGRAM,0); /*�������˿�ʼ����socket������*/
		if(sockfd<0)
		{
			printf("Socket error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Creat server socket success! Socket id: %d\n", sockfd);
		addrlen=sizeof(struct sockaddr_in);
		bzero(&addr,addrlen);
		/*����������� sockaddr�ṹ*/
		addr.sin_family=AF_INET;
		addr.sin_addr.s_addr=htonl(INADDR_ANY);
		addr.sin_port=htons(SERVER_PORT);
		if(bind(sockfd,(struct sockaddr *)(&addr),addrlen)<0)  /*����bind�����󶨶˿�*/
		{
			printf("Bind error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Bind port success! local port: %d\n", SERVER_PORT);
		while(1)   /*�������ж�ȡ���ݣ�����ӡ�����յ�������*/
		{
			bzero(msg,MAX_MSG_SIZE);  /*��������֮ǰ�Ƚ�����������*/
			n=recvfrom(sockfd,msg,sizeof(msg),0,(struct sockaddr*)(&addr),&addrlen); 
			printf("Receive message from client: %s",msg);
			/*���ն˶����û���������ݣ����͵�������ȥ*/
			printf("Server endpoint input message[<1024 bytes]: ");
			fgets(msg,MAX_MSG_SIZE,stdin);
			sendto(sockfd,msg,n,0,(struct sockaddr*)(&addr),addrlen); 
		}
		close(sockfd); /*ͨ�Ž������ر��׽���*/
		return 0;
}

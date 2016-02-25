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
#define BUFSIZE 1024     /*�������ݻ�������С*/

int main(int argc, char *argv[])
{
		int sockfd,newsockfd;
		struct sockaddr_in server_addr;   /*������������׽������ݽṹserver_addr */
		struct sockaddr_in client_addr;   /*����ͻ����׽������ݽṹclient_addr */
		int portnumber;
		char buf[BUFSIZE];     /*�������ݻ�����*/
		int addr_len = sizeof(struct sockaddr_in);
		if(argc!=2)       /*�ж������в���*/
		{
			printf("argc = %d\n",argc);
			printf("Arguments error! gsage: %s portnumber\n",argv[0]);
			exit(1);
		}
		/*��������еĵڶ������������˿ںţ�atoi()���ַ���ת����������*/
		if((portnumber=atoi(argv[1]))<0) 
		{
			printf("argc = %d\n",argc);
			printf("Portnumber error! Usage: %s portnumber\n",argv[0]);
			exit(1);
		}
		if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) /*������������Socket*/
		{
			printf("Create socket error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Creat server socket success! Socket id: %d\n", sockfd);
		/*����������� sockaddr�ṹ*/
		bzero(&server_addr,sizeof(struct sockaddr_in)); /*�Ƚ��׽��ֵ�ַ���ݽṹ����*/
		server_addr.sin_family=AF_INET;
		server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
		server_addr.sin_port=htons(portnumber);
		if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
										   /*����bind�����󶨶˿�*/
		{
			printf("Bind error:%s\n",strerror(errno)); 
			exit(1); 
		}
		printf("Bind port success! local port: %d\n", portnumber);
		if(listen(sockfd,5)==-1)  /*����sockfd��������ͬʱ������������������Ϊ5 */
		{
			printf("Listen error:%s\n",strerror(errno));
			exit(1);
		}
		printf("Listenning......\n");    /*�˿ڼ�����......*/
		while(1)      /*�������������ȴ�������������ֱ���ͻ���������������*/
		{
			if((newsockfd=accept(sockfd,(struct sockaddr *)(&client_addr),&addr_len))==-1)
			/*����accept����һ����������*/
			{
				printf("Accept error:%s\n",strerror(errno)); 
				exit(1); 
			}
			printf("Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));
			/*TCP�����ѽ�������ӡ�������ӵĿͻ�����IP��ַ*/
			printf("Connected successful, please input the mesage[<1024 bytes]:\n");
				/*��ʾ�û����뽫Ҫ���͵����ݣ�����С�ڻ������ĳ��ȣ���1024�ֽ�*/
			if(fgets(buf, sizeof(buf), stdin) != buf)
			{  /*���ն���������ݴ����buf������*/
				printf("fgets error!\n");
				exit(1);
			}
			if(write(newsockfd,buf,strlen(buf))==-1)   /*����write��������*/
			{
				printf("Write error:%s\n",strerror(errno)); 
				exit(1);
			}
			if(read(newsockfd,buf,strlen(buf))!=-1)
			{
				printf("read data %s\n",buf);
			} 
			close(newsockfd);  /*ͨ���ѽ������رտͻ��˵��׽��֣���ѭ����һ�εȴ�*/
		}
		close(sockfd);  /*���������̽������رշ��������׽���*/
		return 0;
}

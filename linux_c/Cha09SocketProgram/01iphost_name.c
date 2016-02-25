#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
int main(void)
{
	struct hostent * host;
	char hostname[30];
	char IP[30];
	struct in_addr in;
	struct sockaddr_in addr_in;
	while(1)
	{
		printf("Input domain name:");
		gets(hostname);
		if((host=gethostbyname(hostname))!=NULL)
		{
			memcpy(&addr_in.sin_addr.s_addr,host->h_addr,4);
			in.s_addr=addr_in.sin_addr.s_addr;
			printf("IP	 :%s\n",inet_ntoa(in));
			printf("IP length:%d\n",host->h_length);
			printf("IP type  :%d\n",host->h_addrtype);
		}
		else
		{
			printf("Error:%d--->%s\n",h_errno,hstrerror(h_errno));
		}

		printf("Input IP address:");
		gets(IP);
		if((host=gethostbyaddr(IP,sizeof(IP),AF_INET))!=NULL)
		{
			memcpy(&addr_in.sin_addr.s_addr,host->h_addr,4);
			in.s_addr=addr_in.sin_addr.s_addr;
			printf("Domain name:%s\n",host->h_name);
			printf("IP length  :%d\n",host->h_length);
			printf("IP type    :%d\n",host->h_addrtype);
		}
		else
		{
			printf("Error:%d--->%s\n",h_errno,hstrerror(h_errno));
		}
	}
}

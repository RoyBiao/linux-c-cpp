#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 50
#define FILE "test.txt"
#define LINK_FILE "link_test.txt"

int main(void)
{
	int count ;
	int fd;
	char buffer[SIZE] = "I like linux C program!";
	struct stat buf;
	if(stat(FILE,&buf)<0)
	{
		printf("stat test.txt error!\n");
		exit(1);
	}
	printf("Before create a hardlink.Link = %d\n",buf.st_nlink);
	if(link(FILE,LINK_FILE)==-1)
	{
		printf("link test.txt error!\n");
		exit(1);
	}
	if(stat(FILE,&buf)<0)
	{
		printf("stat test.txt error!\n");
		exit(1);
	}
	printf("After create a hardlink.Link = %d\n",buf.st_nlink);
	fd=open(LINK_FILE,O_WRONLY);
	if(fd==-1)
	{
		printf("error,open file faied!\n");
		exit(1);
	}
	count=write(fd,buffer,strlen(buffer));	
	if(count==-1)
	{
		printf("error,write file failed!\n");
		exit(1);
	}
	printf("OK,write [%d] strings to file!\n",count);
	system("cat test.txt");
	printf("\n");
	unlink(LINK_FILE);
	stat(FILE,&buf);
	printf("After delete a hardlink.Link = %d\n",buf.st_nlink);
	return 0;
}

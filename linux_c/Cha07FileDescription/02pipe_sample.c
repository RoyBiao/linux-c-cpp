#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd[2];
	char str[256];
	if((pipe(fd))==-1)
	{
		printf("create the pipe failed!\n");
		exit(1);
	}
	printf("fd[0]=%d\n",fd[0]);
	printf("fd[1]=%d\n",fd[1]);
	write(fd[1],"Create the pipe success!\n",30);
	read(fd[0],str,sizeof(str));
	printf("str=%s\n",str);
	close(fd[0]);
	close(fd[1]);
}

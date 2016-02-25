#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/unistd.h>
#include <time.h>

int main(void)
{
	pid_t pChild,pWait;
	time_t timer;
	struct tm *tblock;
	pChild=fork();
	if(pChild == -1)
	{
		printf("failed to create a new process\n");
		exit(1);
	}
	else if(pChild == 0)
	{
		printf("Child process:PID=%d\n",getpid());
		sleep(10);
		exit(0);
	}
	else
	{
		printf("Parent process:PID=%d\n",getpid());
		do{
			//pWait = waitpid(pChild,NULL,WNOHANG);//非阻塞
			pWait = wait(NULL);//阻塞
			if(pWait==0)
			{
				timer = time(NULL);
				tblock = localtime(&timer);
				printf("%s",asctime(tblock));
			}
		}while(pWait==0);
		if(pWait==pChild)
		{	
			printf("successful\n");
		}
		else
		{
			printf("error\n");
		}
	}
}

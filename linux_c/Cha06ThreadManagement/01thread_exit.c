#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

char buffer[]="Hello World";

void thread_function(void * arg)
{
	printf("new thread is running,arg = %s\n",(char *)arg);
	strcpy(buffer,"Bye!");
	pthread_exit("I like C program.");
}

int main(void)
{
	pthread_t thread_id;
	int ret;
	void * thread_result;
	ret = pthread_create(&thread_id,NULL,(void *)thread_function,(void *)buffer);
	if(ret!=0)
	{
		printf("create thread error.\n");
		exit(0);
	}

	ret = pthread_join(thread_id,&thread_result);

	if(ret!=0)
	{
		printf("thread join error.\n");
		exit(1);
	}

	printf("buffer = %s\n",buffer);
	printf("thread id = %ld,result = %s\n",thread_id,(char *)thread_result);
	
	return 0;
}

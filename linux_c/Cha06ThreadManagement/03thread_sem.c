#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define BUFFER_SIZE 5
#define A 65
#define Z 90

char share_buffer[BUFFER_SIZE];
int curr=-1;
int empty=0;
int full=BUFFER_SIZE;
pthread_mutex_t share_mutex;
sem_t non_empty,non_full;

void * consumer_func(void * whichone)
{
int position;

		char data;

		char *who;

		who = (char *)whichone;

		printf("%s: Starting...\n",who);

		while(1)

		{

			sem_wait(&non_empty);             /*是否有非空资源*/

			pthread_mutex_lock(&share_mutex);   /*进入临界区*/

			data = share_buffer[curr];

			position = curr--;

			printf ("%s: Reading [%c] from buffer at position %d\n", who, data, position);

			sem_post(&non_full);              /*生成一个非满资源*/

			pthread_mutex_unlock(&share_mutex);  /*离开临界区*/

			sleep(1);                         /*费时操作*/

		}

		return NULL;
}

void * producer_func(void * whichone)
{
	int position;
	char data;
	char * who;
	who=(char *)whichone;
	printf("%s:Starting...\n",who);
	while(1)
	{
		srand((unsigned int)time(NULL));
		data = (char)(rand()%(Z-A+1)+A);
		sem_wait(&non_full);
		pthread_mutex_lock(&share_mutex);
		position = ++curr;
		share_buffer[curr]=data;
		printf("%s:Writing[%c] to buffer at position %d\n",who,data,position);
		sem_post(&non_empty);
		pthread_mutex_unlock(&share_mutex);
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	pthread_t c1,c2,p1,p2;
	pthread_mutex_init(&share_mutex,NULL);
	sem_init(&non_empty,0,empty);
	sem_init(&non_full,0,full);
	pthread_create(&c1,NULL,&consumer_func,"consumer1");
	pthread_create(&c2,NULL,&consumer_func,"consumer2");
	pthread_create(&p1,NULL,&producer_func,"producer1");
	pthread_create(&p2,NULL,&producer_func,"producer2");
	pthread_join(c1,NULL);
	pthread_join(c2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	sem_destroy(&non_empty);
	sem_destroy(&non_full);
	pthread_mutex_destroy(&share_mutex);
	return 0;
}








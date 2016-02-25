#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define PRODUCT_MAX 5

typedef struct 
{
	char buffer[PRODUCT_MAX];
	int number;
}PRODUCT;

PRODUCT product ={"",0};
char ch = 'A';
pthread_mutex_t mutex;
pthread_cond_t cond;

void * producer_func(void * arg)
{
	pthread_t p_id;
	p_id = pthread_self();
	printf("producer %ld:Starting\n",p_id);
	while(ch!='Z')
	{
		pthread_mutex_lock(&mutex);
		if(product.number!=PRODUCT_MAX)
		{
			product.buffer[product.number++]=ch++;
			printf("Producer %ld:Putting [%c] to buffer\n",p_id,ch-1);
			if(product.number==PRODUCT_MAX)
			{
				printf("Producer %ld:Putting ful!!!\n",p_id);
				pthread_cond_signal(&cond);
			}
			pthread_mutex_unlock(&mutex);
		}
		sleep(1);
	}
	printf("producer %ld:Endting\n",p_id);
	return NULL;
}

void * consumer_func(void * arg)
{
	int i;
	pthread_t c_id;
	c_id = pthread_self();
	printf("consumer %ld:Starting\n",c_id);
	while(ch!='Z')
	{
		pthread_mutex_lock(&mutex);
		while(product.number!=PRODUCT_MAX)
		{
			pthread_cond_wait(&cond,&mutex);
		}
		printf("Consumer %ld:Getting from buffer\n",c_id);
		for(i=0;product.buffer[i]&&product.number;++i,product.number--)
			putchar(product.buffer[i]);
		printf("\n");
		pthread_mutex_unlock(&mutex);
	}
	printf("consumer %ld:Endting\n",c_id);
}

int main(void)
{
	pthread_t producer,consumer;
	void * retval;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_create(&producer,NULL,(void *)producer_func,NULL);
	pthread_create(&consumer,NULL,(void *)consumer_func,NULL);
	pthread_join(producer,&retval);
	pthread_join(consumer,&retval);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}

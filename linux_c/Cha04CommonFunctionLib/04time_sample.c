#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t timer;
	struct tm * tblock;
	timer = time(NULL);
	tblock = localtime(&timer);
	
	printf("Local time is (asctime):%s",asctime(tblock));

	printf("Local time is (ctime):%s",ctime(&timer));
	 
}

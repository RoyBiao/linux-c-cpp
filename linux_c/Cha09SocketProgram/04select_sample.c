#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

int main(void)
{
	struct timeval timer;
	fd_set readfds;
	timer.tv_sec=2;
	timer.tv_usec=500000;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO,&readfds);
	select(STDIN_FILENO+1,&readfds,NULL,NULL,&timer);
	if(FD_ISSET(STDIN_FILENO,&readfds))
		printf("one key was pressed.\n");
	else
		printf("Time out.\n");
	return 0;
}

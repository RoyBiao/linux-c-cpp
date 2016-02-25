#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define X 10
#define Y 50

int main(void)
{
	srand((unsigned int)time(NULL));
	int i;	
	for(i=0;i<5;i++)
		printf("%d \t",(rand()%(Y-X+1)+X));
	printf("\n");
}

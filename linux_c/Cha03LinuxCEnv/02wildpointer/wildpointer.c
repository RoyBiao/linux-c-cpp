#include <stdio.h>
int main(void)
{
 	int input;
	int *p ;
	printf("Please input an interger:");
	scanf("%d",&input);
	*p = input;
	printf("An interger of your input is:%d\n",*p);
	return 0;
}

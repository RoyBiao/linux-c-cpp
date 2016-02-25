#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buffer[30];
	int a=1;
	float b=1.222;
	char *c="helllo";

	sprintf(buffer,"%d%f%s",a,b,c);
	puts(buffer);

	return 0;
}

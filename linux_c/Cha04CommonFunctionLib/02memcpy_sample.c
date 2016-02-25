#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	struct student
	{
		unsigned int num;
		unsigned char * name;
	}*p1,*p2;
	p1 = (struct student *)malloc(sizeof(struct student));
	p2 = (struct student *)malloc(sizeof(struct student));
	if(p1==NULL||p2==NULL)
	{
		printf("error!malloc failed.\n");
		exit(0);
	}	
	memset(p1,0,sizeof(struct student));
	memset(p2,0,sizeof(struct student));
	p1->num=11;
	p1->name="biao11";

	printf("p1 num=%d,name=%s\n",p1->num,p1->name);

	memcpy(p2,p1,sizeof(struct student));

	printf("p2 num=%d,name=%s\n",p2->num,p2->name);

	free(p2);
	free(p1);
	p1=NULL;
	p2=NULL;
	return 0;
}

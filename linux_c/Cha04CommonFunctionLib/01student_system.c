#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char UNIT8;
typedef unsigned short UNIT16;
typedef unsigned int UNIT32;

struct student
{
	UNIT32 number;
	UNIT8 name[20];
	UNIT16 age;
	struct student *next;
};
UNIT8 NUM = 0;
struct student * head =NULL;

struct student * add_student()
{
	static struct student *p1,*p2;
	UNIT8 flag=0;
	p2=(struct student*)malloc(sizeof(struct student));
	if(p2==NULL)
	{
		printf("error,not enough memory to allocate buffer!\n");
		exit(1);
	}
	memset(p2,0,sizeof(struct student));
	printf("Please input student's number:");
	scanf("%d",&p2->number);
	printf("Please input student's name:");
        scanf("%s",&p2->name);
	printf("Please input student's age:");
        scanf("%d",&p2->age);
	printf("Do you want to add this student info?Y or N\n");
	scanf("%s",&flag);
	if(flag=='Y')
	{
		NUM++;
	}
	else
	{
		return head;
	}
	if(NUM==1)
	{
		p1=p2;
		head=p1;
	}
	else
	{
		p1->next=p2;
		p1=p2;
	}
	p1->next = NULL;
	return head;
}

struct student * delete_student()
{
	struct student *p,*del;
	UNIT16 num;
	printf("Please input the student's number you want to delete:");
	scanf("%d",&num);
	if(head==NULL)
	{	
		printf("No student info!\n");
		return NULL;
	}
	p=head;
	del=head;
	if(del->number==num)
	{
		head = del->next;
		del->next=NULL;
		free(del);
		return head;
	}
	else
	{
		while(del!=NULL)
		{
			del = p->next;
			if(del->number==num)
			{
				printf("The student you want to delete is:%s\n",del->name);
				p->next = del->next;
				free(del);
				return head;
			}
			else
			{	
				p=del;
			}
		}
		printf("No this number student!\n");
	}
	return head;	
}

int print_list(struct student * head)
{
	struct student *p;
	p=head;
	if(p==NULL)
	{	printf("There is no student's information!\n");
		return -1;
	}
	else
	{
		do{
			printf("number:%d\t",p->number);
			printf("name:%s\t",p->name);
			printf("age:%d\n",p->age);
			p=p->next;
		}while(p!=NULL);
	}
	return 0;
}

int main(void)
{
	UNIT8 select =0;
	while(1)
	{
		printf("Select the operation:\n1--->Add a student\n2--->Delete a student\n0--->Exit\n");
		scanf("%d",&select);
		switch(select)
		{
			case 0:
				exit(0);
				break;
			case 1:	
				head = add_student();
				break;
			case 2:
				head = delete_student();
				break;
			default:
				break;
		}
		print_list(head);

	}
	return 0;
}


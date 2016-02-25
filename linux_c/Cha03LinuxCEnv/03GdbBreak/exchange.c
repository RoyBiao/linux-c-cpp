#include <stdio.h>
void exchange_by_arith(int a,int b);
void exchange_by_xor(int a,int b);
void exchange_by_pointer(int *a,int *b);
int main(void)
{
	int a,b;
	int method;
	while(1)
	{
		printf("please input two integers,or use 0 0 to exit");
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
		{
			exit(0);
		}
		printf("please select the exchange method:\n");	
		printf("1.Exchanged by arith\n");
		printf("2.Exchanged by xor\n");
		printf("3.Exchanged by pointer\n");
		printf("method:");
		scanf("%d",&method);
		switch(method)
		{
			case 1:
				exchange_by_arith(a,b);
				break;
			case 2:
                                exchange_by_xor(a,b);
                                break;
			case 3:
                                exchange_by_pointer(&a,&b);
                                break;
			default:
				break;
		}

	}
	return 0;
}
void exchange_by_arith(int a,int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	printf("Exchanged by arith:a=%d,b=%d\n",a,b);
}

void exchange_by_xor(int a,int b)
{
	a=a^b;
	b=a^b;
	a=a^b;
	printf("Exchanged by xor:a=%d,b=%d\n",a,b);	
}

void exchange_by_pointer(int *a,int *b)
{
	int *p;
	p=a;
	a=b;
	b=p;
	printf("Exchanged by pointer:a=%d,b=%d\n",*a,*b);  
}

#include <stdio.h>
#include <unistd.h>
int ret =0;
void testExecl()
{
	if(fork()==0)
         {       
                 if(ret = execl("/bin/ls","ls","-al",NULL)==-1)
                         perror("Error on execl");
         }
}

void testExeclp()
{
	
	if(fork()==0)
	{
		if(ret = execlp("ls","ls","-al",NULL)==-1)
                        perror("Error on execlp");
	}
}

void testExecle()
{
    char * const envp[] = {"AA=11", "BB=22", NULL};
    printf("Entering main ...\n");
    int ret;
    ret =execle("./hello", "hello", NULL, envp);
    if(ret == -1)
        perror("execl error");
    printf("Exiting main ...\n");
}

char * argv_execv[]={"ls","-al",NULL};
void testExecv()
{
	if(fork()==0)
         {       
                 if(ret = execv("/bin/ls",argv_execv)==-1)
                         perror("Error on execv");
         }
}

void testExecvp()
 {
         if(fork()==0)
          {
                  if(ret = execvp("ls",argv_execv)==-1)
                          perror("Error on execvp");
          }
}

void testExecve()
{
    char * const argv[] = {"ls","-al",NULL};
    char * const envp[] = {"AA=11", "BB=22", NULL};
    printf("Entering main ...\n");
    int ret;
    ret =execve("./hello", argv, envp);
    if(ret == -1)
        perror("execl error");
    printf("Exiting main ...\n");
}
int main(void)
{
	//testExecl();
	//testExeclp();
	//testExecle();
	//testExecv();
	//testExecvp();
	testExecve();
	return 0;
}

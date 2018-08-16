#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
	pid_t fo = fork();
	if(fo == -1)
	{
		perror("fork failed");
		return -1;
	}
	switch (fo)
	{
		case -1: 
			perror("fork failed"); break;

		case 0 : //child
			printf("child Process\n");
			printf("pid = %d\tppid = %d\n",getpid(),getppid());break;
		default : //Parent
			printf("Parent Process\n");
			printf("pid = %d\tppid = %d\n",getpid(),getppid());
			wait(NULL);//waits for child to terminate
			
	}
	printf("kkkkkk\n");
	return 0;
}

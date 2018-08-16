#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t fo = fork();
	int var = 10;
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
			//exit(0);
			var = 200;
			printf("child : var = %d\n",var);
			//printf("child Process\n");
			//execl("../fileIO/a.out","a.out","hello.txt","toupper.txt",NULL);
			//printf("pid = %d\tppid = %d\n",getpid(),getppid());
			//sleep(2);
			break;

		default : //Parent
			//system("ps");
			//sleep(10);
			//system("ps");
			//printf("Parent Process\n");
			var = 500;
			printf("parent : var = %d\n",var);
			//printf("pid = %d\tppid = %d\n",getpid(),getppid());
			wait(NULL);//waits for child to terminate
			printf("parent : var = %d\n",var);
			
	}
	//printf("kkkkkk\n");
	return 0;
}

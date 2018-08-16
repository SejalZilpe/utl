#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <signal.h>
#include<sys/wait.h>

int main()
{

	int ret = -1;
	int pid = fork();
	switch (pid)
	{
		case -1:
			perror("fork failed");
			return -1;

		case 0 : 
			printf("Child is running in infinite loop\n");
			while (1);break;
		
		default : 
			sleep(5);
			printf("Parent process gonna kill the child\n");
			kill (pid ,SIGKILL );
			sleep(2);
			printf("Parent killed it's child\n");
			wait(NULL);
		

	}

	return 0;
}

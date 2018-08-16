#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void doSomeWork(char *name)
{
	const int NUM_TIMES = 5;
	for(int i=0; i<NUM_TIMES;i++)
	{
		sleep(rand() %4);
		printf("\n Done pass %d for %s  \n ",i,name);
	}
}

int main(int argc,char *argv[])
{
	printf("\n i am : %d \n ",(int) getpid());
	pid_t pid=fork();
	printf("fork returned : %d \n ",(int) pid);

	if(pid < 0)
	{
		perror("FORK FAILED ");
	}
	if(pid==0)
	{
		printf("\n i  am the child with pid %d .\n ",(int) getpid());
		doSomeWork("Child");
		exit(42);
	}
	 
	printf("\n i am the parent, waiting for the child to end . \n ");
	sleep(10);

	int status =0;
	pid_t childpid= wait(&status);
	printf("\n parent knows child %d finished with status %d .\n ",(int)childpid, status);
	int childReturnValue = WEXITSTATUS(status);
	printf("\n return value was %d ",childReturnValue);
	sleep(60);
	
	return 0;
}





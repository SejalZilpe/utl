#include<stdio.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

#define NUM_CHILDREN 4
int g=0;
 
int main(int argc,char *argv[])
{
	int i=0;
	for(i=0; i<NUM_CHILDREN ;i++)
	{
		pid_t pid=fork();
		if(pid<0)
		{
			perror("fork failed ");
			exit(1);
		}	
		else if(pid ==0)
		{
			// child now exec
			char* args[]={"./bogosort"};//,"2","1","3","4","5","6","7",
					//"8","9","10","11",NULL};
			execv(args[0],args);
			printf("\n never going to see this !! \n ");
		}
	
	}
	printf("\n parent is doing something amazing \n ");
	printf("\n parent is waiting for child process \n ");
	for(i=0;i<NUM_CHILDREN;i++)
	{
		wait(NULL);
	}
return 0;
}

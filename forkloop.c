#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	for(int i=1;i<=4 ;i++)
	{
		fork();
		printf("\n %d : my PID = %d \n ",i,(int)getpid());
	}
	
	sleep(1);
	printf("--> my PID = %d \n",(int)getpid());
	return 0;
}

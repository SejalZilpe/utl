#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	int ret = -1;
	char cbuf[50] = {0};
	ret = pipe(fd);
	
	ret = fork();
	switch(ret)
	{
		case -1:
			return -1;
		case 0: 
			//write(fd[1],"Child : Hello Papa!",19 );
			read(fd[0] , cbuf , 50 );
			printf("Parent Wrote = %s\n",cbuf);
			break; 
		default: //wait(NULL);
			printf("Parent is writing Hello to the children\n");
			write(fd[1] , "Hello children\n",14);
			//read(fd[0] , pbuf , 19 );
			//printf("Child Wrote = %s\n",pbuf);
	


	}
	return 0;
}

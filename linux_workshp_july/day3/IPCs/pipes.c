#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	int ret = -1;
	char pbuf[50] = {0} , cbuf[50] = {0};
	ret = pipe(fd);
	
	ret = fork();
	switch(ret)
	{
		case -1:
			return -1;
		case 0: 
			close(fd[0]);
			write(fd[1],"Hello Papa!",19 );
			//sleep(2);
			//read(fd[0] , cbuf , 50 );
			//printf("Parent Wrote = %s\n",cbuf);
			break; 
		default: //sleep(1);
			//write(fd[1] , "Hello\n",6);
			close(fd[1]);
			read(fd[0] , pbuf , 19 );
			printf("Child Wrote = %s\n",pbuf);
			//sleep(2);
			//write(fd[1] , "Hello son\n",9);
			
	}
	return 0;
}

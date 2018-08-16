#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc , char* argv[])
{
	if (argc < 2)
	{
		perror("bad cmnd");
		return -1;
	}
	int ret = mkfifo(argv[1],0664);	
	if (ret == -1)
	{
		perror("fifo failed");
		return -1;
	}	
	printf("fifo %s created successfully\n",argv[1]);
	

	return 0;
}

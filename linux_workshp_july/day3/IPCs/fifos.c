#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int ret = mkfifo("fifo1",0664);	
	if (ret == -1)
	{
		perror("fifo failed");
		return -1;
	}	
	//write(ret , "Hello fifo1", 11);

	return 0;
}

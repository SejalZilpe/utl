#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc , char* argv[])
{

	int ret = -1;
	int fd = -1;
	char rbuf[100] = {0};
	if (argc < 3)
	{
		printf("SYNTAX : %s <fifoname> <readbytecount>\n",argv[0] );
		return -1;
	}
	fd = open(argv[1] , O_RDWR );
	if (fd == -1)
	{
		perror("open failed");
		return -1;
	}	
	ret = read(fd , rbuf , atoi(argv[2]) );
	if (ret == -1)
	{
		perror("write failed");
		return -1;
	}	
	printf("rbuf = %s\n",rbuf);
	unlink(argv[1]);
	
	return 0;
}

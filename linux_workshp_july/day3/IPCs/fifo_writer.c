#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc , char* argv[])
{

	int ret = -1;
	int fd = -1;
	//char wbuf[] = "This is mr writer proc";
	
	if (argc < 3)
	{
		perror("bad cmnd");
		return -1;
	}
	fd = open(argv[1] , O_RDWR );
	if (fd == -1)
	{
		perror("open failed");
		return -1;
	}	
	ret = write(fd , argv[2] , strlen(argv[2]) );
	if (ret == -1)
	{
		perror("write failed");
		return -1;
	}	
	
	return 0;
}

#include <sys/types.h>
#include <sys/stat.h>
include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<ctype.h>
int main()
{
	unsigned int fd = -1 , w = -1 , r = -1 , l = -1; 
	char buf[] = " Hello File I/Os " , rbuf[100] = {0};
	char ch1 , ch2;
	fd = open("open_demo.txt",O_RDWR | O_CREAT | O_APPEND,0664);
	if(fd == -1)
	{

		perror("open() failed");
		return -1;
	}
	w =  write (fd , buf , sizeof(buf));
		if(-1 == w){
			perror("write failed");
			close(fd);
			return -1;
		}
	printf("w = %d\n",w);

	l = lseek(fd , 5, SEEK_SET );
	printf("l = %d\n",l);

	r = read(fd ,rbuf , sizeof(rbuf));
		if(-1 == r){
			perror("read failed");
			close(fd);
			return -1;
		}
	printf("rbuf = %s\n",rbuf);
	printf("r = %d\n",r);
	

	close(fd);

	return 0;
}

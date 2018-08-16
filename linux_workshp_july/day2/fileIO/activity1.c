#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc , char* argv[])
{
	unsigned int fd = -1 ; int ret = -1 , rret = -1;
	char buff[100] = {0};
	//char *str = argv[2];

	if(argc != 4)
		{
			printf("Bad Command\n");
			return -1;
		}
	//strcpy(buf , str);
	switch (argv[3][0])
	{
		case 'w' :
				fd = open(argv[1] , O_CREAT | O_RDWR ,0664 );
					if(-1 == fd)
					{
						perror("open failed");
						return -1;
					}
					ret = write(fd , argv[2] , strlen(argv[2])+1);
					if(-1 == ret)
					{
						perror("write failed");
						return -1;
					}
				break;
		case 'r' : 	
				fd = open(argv[1] , O_CREAT | O_RDWR ,0664 );
					if(-1 == fd)
					{
						perror("open failed");
						return -1;
					}
					read(fd , buff , atoi(argv[2]));
					if(-1 == rret)
					{
						perror("read failed");
						return -1;
					}
					printf("buff = %s\n",buff);
				break;
				

	}
	/*fd = open(argv[1], O_CREAT | O_RDWR , 0664);

		if(-1 == fd)
		{
			perror("open failed");
			return -1;
		}

		if (*argv[3] == 'w')
			write(fd ,str, strlen(argv[2]));*/
	close(fd);
	return 0;
}

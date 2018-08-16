#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
int main(int argc , char* argv[])
{
	unsigned int readfd = -1 ,writefd = -1; int ret = -1 , rret = -1;
	char ch1 , ch2;
	char buff[100] = {0};
	//char *str = argv[2];

	if(argc != 3)
		{
			printf("SYNTAX:%s <filename> <data> <r/w>\n",argv[0]);
			return -1;
		}
	

				readfd = open(argv[1] , O_CREAT | O_RDONLY ,0664 );
					if(-1 == readfd)
					{
						perror("open failed");
						return -1;
					}
					writefd = open( argv[2] , O_WRONLY | O_CREAT | O_APPEND,0664);
					if(-1 == writefd)
					{
						perror("open failed");
						return -1;
					}
		while((ret = read(readfd , &ch1 , 1 )))
			{
				ch2 = toupper(ch1);
				write(writefd , &ch2 , 1);
			}
	
	close(readfd);
	close(writefd);
	return 0;
}

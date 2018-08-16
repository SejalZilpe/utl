#include<stdio.h>
#include<unistd.h>

int main()
{
	execl("/bin/ls","ls","-l",NULL);
	printf("Hello World\n");


	return 0;
}

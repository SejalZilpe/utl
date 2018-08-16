#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* sum_runner(void* arg)
{
	long long *limit_ptr=(long long)arg;
	long long limit=*limit_ptr;
	free(arg);

	long long sum=0;
	for(long long i=0; i<= limit; i++)
	{	
		sum+=i;
	}
	long long *answer = malloc(sizeof(*answer));
	*answer=sum;
	pthread_exit(answer);
}

int main(int argc,char **argv)
{
	if(argc<2)

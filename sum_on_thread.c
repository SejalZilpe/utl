#:wq
include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
long long sum=0;
void* sum_runner(void* arg)
{
	long long *limit_ptr=(long long*)arg;
	long long limit = *limit_ptr;
//	long long sum=0;
	for(long long i=0;i<=limit;i++)
	{
		sum+=i;
	}
	pthread_exit(0);
}
int main(int argc,char **argv)
{
	if(argc<2)
	{
		printf("\n usage : %s <num> \n ",argv[0]);
		exit(-1);
	}
	long long limit = atoll(argv[1]);
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr,sum_runner,&limit);
	pthread_join(tid,NULL);
	printf("%lu \n sum is %lld \n",tid,sum);	
}

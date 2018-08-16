#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct sum_runner_struct
{
	long long limit;
	long long answer;
};

void* sum_runner(void* arg)
{
	struct sum_runner_struct *arg_struct = (struct sum_runner_struct*)arg;
	long long i,sum=0;		
	for(i=0 ;i <= arg_struct->limit ;i++);
	{
		sum+=i;
	}

	arg_struct->answer=sum;
	pthread_exit(0);
}

int main(int argc,char **argv)
{
	int i;
	if(argc < 2)
	{
		printf("\n usage : %s <num 1> <num 2>...<num-n>\n",argv[0]);
		exit(-1);
	}
	int num_args=argc-1;

	struct sum_runner_struct args[num_args];
	
	pthread_t tids[num_args];
	for(i=0; i < num_args ;i++)
	{
		args[i].limit=atoll(argv[i+1]);
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tids[i], &attr,sum_runner, &args[i]);
	}
	for( i=0; i<num_args; i++)
	{
		pthread_join(tids[i],NULL);
		printf("\n sum fo thread %d  is %lld \n ",i,args[i].answer);
	}
}

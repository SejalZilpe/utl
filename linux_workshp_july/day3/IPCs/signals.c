#include<stdio.h>
#include<signal.h>


void sigHandler(int i){
	printf("SIGQUIT triggered; i = %d\n",i);
	return;
}

int main()
{
	signal(SIGQUIT, sigHandler);
	//signal(SIGINT, SIG_DFL);
	signal(SIGINT, SIG_IGN);

	while(1);

	return 0;
}

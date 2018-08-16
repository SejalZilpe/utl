#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include"msgQCreate.h"
//#define PROJ_PATH "./saif"
//#define PROJ_NUM 0x7

int main(int argc , char* argv[])
{
	
	key_t key = -1;
	//key = ftok("./",10);
	key = ftok(PROJ_PATH,PROJ_NUM);
	int mid = -1;
	//mid = msgget(IPC_PRIVATE , IPC_CREAT);
	//mid = msgget(1234 , IPC_CREAT | 0664);
	mid = msgget(1234 , IPC_CREAT | IPC_EXCL |0664);
	if(-1 == mid)
	{

		perror("msgget");
		return -1;
	}
	printf("msgq created successfully mid = %x  %d\n",mid,mid);


	return 0;
}

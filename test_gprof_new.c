#include<stdio.h>
void new_func1(void)
{
	printf("\n inside new function \n ");
	int i=0;
	for(;i<0xffffffee;i++);
	return;
}

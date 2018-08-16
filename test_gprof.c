#include<stdio.h>
void new_func1(void);
void func1(void)
{
	printf("\n inside func 1 ");
	int i=0;
	for(;i<0xffffffff;i++);
	new_func1();
//	return;
}
static void func2(void)
{
	printf("\n inside func 2 ");
	int i=0;
	for(;i<0xffffffaa;i++);
//	return;
}
int main(void)
{
	printf("\n inside main\n ");
	int i=0;
	for(;i<0xffffff;i++);
	func1();
	func2();
	return 0;
}

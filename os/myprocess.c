#include<stdio.h>
#include<stdlib.h>

// globals or externs 
int glo_1=100;

//static global
static int glo_s=200;

int main()
{	
	// auto or local variables
	int loc_1=10; 
	auto int loc_2=20;

	//static variable (local static)
	static int loc_s=30;	

	int *p= (int*)malloc(4);

	printf(" <%p> loc_1 = %d \n ",&loc_1, loc_1);
	printf(" <%p> loc_2 = %d \n ",&loc_2, loc_2);
	printf(" <%p> loc_s = %d \n ",&loc_s, loc_s);
	printf(" <%p> glo_1 = %d \n ",&glo_1, glo_1);
	printf(" <%p> glo_s = %d \n ",&glo_s, glo_s);
	printf(" <%p> p = %p \n ",&p, p);

	while(1);

	return 0;
}

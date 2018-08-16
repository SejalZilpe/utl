#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int mat1[3][3],mat2[3][3],mat3[3][3],i,j,k;
void *thread_mat_mul(void *);

int main()
{
	//int mat1[3][3],mat2[3][3],mat3[3][3],i,j,k;	
	pthread_t tid;
	printf("\n enter 1st array : ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("\n enter 2nd array : ");
	for(i=0;i<3;i++)
        {
        	for(j=0;j<3;j++)
        	{
                	scanf("%d",&mat2[i][j]);
        	}
        }
	for(i=0;i<3;i++)
        {
        	for(j=0;j<3;j++)
        	{
                	mat3[i][j]=0;
        	}
        }
	printf("\n multiplying the matrix : ");
	pthread_create(&tid,NULL,thread_mat_mul,NULL);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
	 			mat3[i][j]=mat3[i][j]+(mat2[i][k]*mat1[k][j]);	
			}
		}		
	}
	printf("\n the first matrix \n ");
	for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%d\t",mat1[i][j]);
                }
                printf("\n");
        }
	printf("\n the second matrix \n ");
	for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%d\t",mat2[i][j]);
                }
                printf("\n");
        }
	printf("\n the output is : \n ");
	for(i=0;i<3;i++)
        {
        	for(j=0;j<3;j++)
        	{
                	printf("%d\t",mat3[i][j]);
        	}
		printf("\n");
        }

return 0;
}


void *thread_mat_mul(void *para)
{
	int i,j,k;
        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        for(k=0;k<3;k++)
                        {
                                mat3[i][j]=mat3[i][j]+(mat2[i][k]*mat1[k][j]);
                        }
                }
        }
	printf("\n thread finish ");
	pthread_exit(0);
}


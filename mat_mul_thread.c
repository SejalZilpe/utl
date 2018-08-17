#include<stdio.h>

#include<sys/types.h>

#include<pthread.h>



#define size 1000



int mat1[size][size];

int mat2[size][size];

int mat3[size][size];

int n=0;

void* Multiply_Matrix(void* arg)

{

	int i,j,k;

  for(j=0;j<size;j++)

  {

   for(k=0;k<size;k++)

    mat3[n][j]+=mat1[n][k] * mat2[k][j];

  }

	n++;   //This is for each row(i.e.; threads)

}



int main()

{ 

 int i,j;

 printf("Generating random values for Matrix !");

 for(i=0;i<size;i++)

 {

  for(j=0;j<size;j++)

  {

   mat1[i][j] = rand() % 10;

   mat2[i][j] = rand() % 5;

  }

 }

 printf("\n Matrix 1: \n");

 for(i=0;i<size;i++)

 {

  printf("\n");

  for(j=0;j<size;j++)

   printf("%d ",mat1[i][j]);

 }



 printf("\n Matrix 2: \n");

 for(i=0;i<size;i++)

 {

  printf("\n");

  for(j=0;j<size;j++)

   printf("%d ",mat2[i][j]);

 }

 

 printf("\n Matrix Multiplication using Threads");

  

 // Creating thread ids  

 pthread_t ThreadIds[size];

 

 for(i=0;i<size;i++)

 {

   pthread_create(&ThreadIds[i], NULL, Multiply_Matrix

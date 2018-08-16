#include<stdio.h>

int validateDate(int dd,int mm,int yy)
{
//check year
    if(yy>=1900 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=28) && (mm==2))
                printf("Date is valid.\n");
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                printf("Date is valid.\n");
            else
                printf("Day is invalid.\n");
		return -1;
        }
        else
        {
            printf("Month is not valid.\n");
		return -1;
        }
    }
    else
    {
        printf("Year is not valid.\n");
	return -1; //on failure
    }
	return 0; //on success
 
}
//function definition
int getStartDate(){
	int day = 0;
	int month = 0;
	int year = 0;
	printf("\nEnter the day in dd format: ");
	scanf("%d",&day);
	printf("\nEnter the month in mm format: ");
	scanf("%d",&month);
	printf("\nEnter the year in yyyy format: ");
	scanf("%d",&year);
	validateDate(day,month,year);
	return 0;


}
	

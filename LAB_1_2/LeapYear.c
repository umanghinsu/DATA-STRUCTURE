#include <stdio.h>

void main()
{
    int year;

    printf("Enter Year - ");
    scanf("%d",&year);

    if((year%100!=0 && year%4==0) || year%400==0)
    {
        printf("Entered year is leap year");
    }
    else{
        printf("Entered year is not a leap year");
    }
}
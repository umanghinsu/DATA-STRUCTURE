#include <stdio.h>

void main(){

    int d,year,week,day;

    printf("enter days = ");
    scanf("%d",&d);

    year = d/365;
    week = (d%365)/7;
    day = (d%365)%7; 

    printf("%d year, %d week, %d day",year,week,day);
}
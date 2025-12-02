#include <stdio.h>

void main()
{
    int sec,hour,minute,second;

    printf("enter second = ");
    scanf("%d",&sec);

    hour = sec/3600;
    minute = (sec%3600)/60;
    second = (sec%3600)%60; 

    printf("HH:MM:SS = %d:%d:%d",hour,minute,second);
}
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[5];
    int *ptr = a;

    printf("input : \n");
    for(int i=0; i<5; i++)
    {
        scanf("%d",ptr+i);
    }


    printf("output : \n");
    for(int i=0; i<5; i++)
    {
        printf("%d ",*ptr+i);
    }
}
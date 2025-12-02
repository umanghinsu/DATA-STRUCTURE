#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n1,n2;
    int *ptr1 = &n1;
    int *ptr2 = &n2;

    printf("n1:");
    scanf("%d",ptr1);

    printf("n2:");
    scanf("%d",ptr2);

    printf("ans = %d",(*ptr1+*ptr2));
}
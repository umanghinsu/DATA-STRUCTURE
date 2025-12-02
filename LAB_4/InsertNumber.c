#include <stdio.h>

void main()
{
    int size,position,num;

    printf("Enter array size = ");
    scanf("%d",&size);

    int a[size];

    printf("input :\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter position - ");
    scanf("%d",&position);

    printf("Enter number - ");
    scanf("%d",&num);

    for (int i=size; i>position; i--)
    {
        a[i] = a[i-1];  //sift left number for genrate space for enter new num 
    }
    a[position] = num;
    size++;

    printf("output :\n");
    for(int i=0; i<size; i++)
    {
        printf("%d\n",a[i]);
    }
}
#include <stdio.h>

void main()
{
    int size ;
    int i;

    printf("Enter size = ");
    scanf("%d",&size);

    int a[size];

    printf("input :\n");
    for(i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("output :\n");

    for(i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
}
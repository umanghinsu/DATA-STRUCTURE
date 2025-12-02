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

    for (int i=position; i<size; i++)
    {
        a[i] = a[i+1]; // sift right start from position  
    }
    size--;

    printf("output :\n");
    for(int i=0; i<size; i++)
    {
        printf("%d\n",a[i]);
    }
}
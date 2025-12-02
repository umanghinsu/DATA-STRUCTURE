#include <stdio.h>

void main()
{
    int size,num,position;

    printf("Enter array size = ");
    scanf("%d",&size);

    int a[size];

    printf("input :\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter number - ");
    scanf("%d",&num);

    for(int i=0; i<size; i++)
    {
        if(num<a[i])
        {
            position = i;
            break;
        }
    }

    for (int i=size; i>position; i--)
    {
        a[i] = a[i-1];
    }

    a[position] = num;
    size++;

    printf("output :\n");
    for(int i=0; i<size; i++)
    {
        printf("%d\n",a[i]);
    }
}
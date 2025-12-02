#include <stdio.h>

void main()
{
    int size;
    int min, index1,index2;

    printf("Enter size = ");
    scanf("%d",&size);

    int a[size];

    printf("input :\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0; i<size-1; i++)
    {
        if(a[i] < a[i+1])
        {
            index1 = i+1;
        }
    }

    printf("index of maximum number = %d\n",index1);

    min = a[0];
    for(int i=0; i<size; i++)
    {
        if(min > a[i])
        {
            min = a[i];
            index2 = i;
        }
    }

    printf("index of minimum number = %d",index2);
}
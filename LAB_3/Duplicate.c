#include <stdio.h>

void main()
{
    int size, count=0;

    printf("Enter size = ");
    scanf("%d",&size);

    int a[size];

    printf("input :\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(a[i] == a[j])
            {
                count++;
            }
        }
    }

    if(count>0)
    {
        printf("Array is duplicate");
    }
    else{
        printf("Array is not duplicate");   
    }
}
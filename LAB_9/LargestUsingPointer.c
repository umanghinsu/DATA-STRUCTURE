#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("n :");
    scanf("%d",&n);
    int * a=(int *)malloc(n*sizeof(int));
    
    int max;

    printf("input : \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }

    max = *a;
    for(int i=1; i<n; i++)
    {
        if(max<*(a+i))
        {
            max = *(a+i);
        }
    }
    printf("maximum = %d",max);
    
}
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("n :");
    scanf("%d",&n);

    int * a=(int *)malloc(n*sizeof(int));
    
    printf("input : \n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(*(a+j)<*(a+j+1))
            {
                int temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }

    printf("output : \n");
    for(int i=0; i<n; i++)
    {
        printf("%d  ",*(a+i));
    }
    
}
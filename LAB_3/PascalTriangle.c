#include <stdio.h>

void main()
{
    int i,j,n;
    printf("enter row size -");
    scanf("%d",&n);
    int a[n][n];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(j==1||j==i)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }    
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }
        for(j=1; j<=i; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
} 
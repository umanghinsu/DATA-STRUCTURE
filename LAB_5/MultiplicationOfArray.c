#include <stdio.h>

void main(){
    int rowsize,colsize,sum=0;

    printf("enter rowsize : ");
    scanf("%d",&rowsize);

     printf("enter colsize : ");
    scanf("%d",&colsize);

    int a[rowsize][colsize];
    int b[colsize][rowsize];
    int ans[rowsize][colsize];

    printf("\nintput of a :\n");
    for(int i=0; i<rowsize; i++)
    {
        for(int j=0; j<colsize; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nintput of b :\n");
    for(int i=0; i<colsize; i++)
    {
        for(int j=0; j<rowsize; j++)
        {
            scanf("%d",&b[i][j]); 
        }
    }

    for(int i=0; i<rowsize; i++)
    {
        for(int j=0; j<rowsize; j++)
        {
            for(int k=0; k<colsize; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            ans[i][j] = sum;
            sum = 0;
        }
    }

    printf("\nans :\n");
    for(int i=0; i<rowsize; i++)
    {
        for(int j=0; j<rowsize; j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
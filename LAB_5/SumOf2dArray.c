#include <stdio.h>

void main(){
    int rowsize,colsize;

    printf("enter rowsize : ");
    scanf("%d",&rowsize);

     printf("enter colsize : ");
    scanf("%d",&colsize);

    int a[rowsize][colsize];
    int b[rowsize][colsize];
    int ans[rowsize][colsize];

    printf("intput of a :\n");
    for(int i=0; i<rowsize; i++)
    {
        for(int j=0; j<colsize; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("intput of b :\n");
    for(int i=0; i<rowsize; i++)
    {
        for(int j=0; j<colsize; j++)
        {
            scanf("%d",&b[i][j]);
            ans[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("ans :\n");
    for(int i=0; i<rowsize; i++)
    {
        for(int j=0; j<colsize; j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}
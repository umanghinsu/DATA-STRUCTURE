#include <stdio.h>

void main()
{
    int size1, size2;
    int i,j;

    printf("Enter size 1 = ");
    scanf("%d",&size1);
    int a1[size1];

    printf("Enter size 2 = ");
    scanf("%d",&size2);
    int a2[size2];

    printf("input 1 :\n");
    for(i=0; i<size1; i++)
    {
        scanf("%d",&a1[i]);
    }

    printf("input 2 :\n");
    for(i=0; i<size2; i++)
    {
        scanf("%d",&a2[i]);
    }

    for(i=size1,j=0; i<size1+size2,j<size2; i++,j++)
    {
        a1[size1] = a2[j];
        size1++;
    }
    printf("output :\n");

    for(i=0; i<size1; i++)
    {
        printf("%d ",a1[i]);
    }
}
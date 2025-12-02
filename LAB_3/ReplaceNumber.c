#include <stdio.h>

void main()
{
    int size, count=0 ,n1, n2, temp, index1, index2;

    printf("Enter size = ");
    scanf("%d",&size);

    int a[size];

    printf("input :\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter number 1 = ");
    scanf("%d",&n1);

    printf("Enter number 2 = ");
    scanf("%d",&n2);

    for(int i=0; i<size-1; i++)
    {
        if(n1 == a[i])
        {
            if(n2 == a[i+1])
            {    
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;

                index1 = i;
                index2 = i+1;
            }
        }
    }

    printf("output :\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }

    printf("first number index = %d\n",index1);
    
    printf("second number index = %d\n",index2);   
    
}
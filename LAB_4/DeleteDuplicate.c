#include <stdio.h>

void main()
{
    int size;

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
                for (int k=j; k<size; k++)
                {
                    a[k] = a[k+1];
                }
                size--;
                j--;
            }
        }
    }

    printf("output :\n");
    for(int i=0; i<size; i++)
    {
        printf("%d\n",a[i]);
    }
}
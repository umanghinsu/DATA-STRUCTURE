#include <stdio.h>
#include <math.h>

void main()
{
    int i,ans,num,length;

    printf("Armstrong number :-\n");

    for(i=1; i<=1000; i++)
    {
        length = floor(log10(abs(i))) + 1;

        ans = (pow((i%10),length) + pow((i%100-i%10) / 10,length) + pow((i%1000-i%100) / 100,length));

        if(ans == i)
        {
            printf("%d\n",i); 
        }
    }
}
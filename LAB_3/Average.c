#include <stdio.h>

void main()
{
    int n,i,ans=0;

    printf("Enter number 1 =");
    scanf("%d",&n);
    
    for(i=1; i<=n; i++)
    {
        ans +=i;
    }

    ans = ans*1.0/n;

    printf("sum = %d",ans);
}
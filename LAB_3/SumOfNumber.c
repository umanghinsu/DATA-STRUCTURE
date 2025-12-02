#include <stdio.h>

void main()
{
    int m,n,i,ans=0;

    printf("Enter number 1 =");
    scanf("%d",&m);
    
    printf("Enter number 2 =");
    scanf("%d",&n);

    for(i=m; i<=n; i++)
    {
        ans +=i;
    }

    printf("sum = %d",ans);
}
#include <stdio.h>

//using loop

void main()
{
    int n,i,ans=1;

    printf("n = ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        ans *= i;
    }
    printf("ans = %d",ans);
}

// using recurtion

#include <stdio.h>

int rec(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    return n*rec(n-1);
}
void main() {
    int num;
    
    printf("num = ");
    scanf("%d",&num);
    printf("Factorial = %d",rec(num));
}
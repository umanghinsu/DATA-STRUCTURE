#include <stdio.h>

void main() {
    
    int i,n,ans=0,temp1;
    
    printf("n= ");
    scanf("%d",&n);
    
    while(n!=0)
    {
        temp1 = n%10;
        ans = (ans*10) + (temp1);
        n=n/10;
    }
    
    printf("ans = %d",ans);
}
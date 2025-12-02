#include <stdio.h>

// 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n).

void main() {
    
    int i,j,n,ans=0;
    
    printf("n= ");
    scanf("%d",&n);
 
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++)
        {
            ans += j;
        }
    }
    
    printf("ans = %d",ans);
}
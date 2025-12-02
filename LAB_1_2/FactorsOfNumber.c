#include <stdio.h>

//using loop

void main() {
    
    int i,n,ans;
    
    printf("n= ");
    scanf("%d",&n);
    
    printf("factors :\n");
    for(i=1; i<=n; i++){
        if(n%i==0)
        {
            printf("%d\n",i);
        }
    }
}

//using recursion

#include <stdio.h>

int rec(int n,int x)
{
    if(x<=n)
    {
        if(n%x==0)
        {
            printf("%d\n",x);
        }
    }
    rec(n,x+1);
}
void main() {
    
    int n;
    
    printf("n= ");
    scanf("%d",&n);
    
    printf("factors :\n");
    rec(n,1);
}
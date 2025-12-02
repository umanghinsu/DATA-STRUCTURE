#include <stdio.h>

//using loop

void main() {
    
    int i,n,ans=1,p;
    
    printf("n= ");
    scanf("%d",&n);
    printf("p= ");
    scanf("%d",&p);
    
    for(i=1; i<=p; i++){
        ans*=n;
    }
    
    printf("ans = %d",ans);
}

//using recursion

#include <stdio.h>

int rec(int n,int p)
{
    if(p==0 || p==1)
    {
        return n;
    }
    return n*rec(n,p-1);
}
void main(){

    int n,p;

    printf("n = ");
    scanf("%d",&n);

    printf("p = ");
    scanf("%d",&p);

    printf("ans = %d",rec(n,p));
}
#include <stdio.h>

void main() {
    
    int i,j,n1,n2,ans,count=0;
    
    printf("n1= ");
    scanf("%d",&n1);

    printf("n2= ");
    scanf("%d",&n2);
    
    printf("prime number :\n");
    
    for(i=n1; i<=n2; i++){
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                count++;
            }
        }
        if(count==0)
        {
            printf("%d\n",i);
        }
        count=0;
    }
}
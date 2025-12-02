#include <stdio.h>

int slide(int [],int, int, int, int);

int slide(int a[],int start, int k, int size, int maxlength){
    
    int s=0;
    int n=start;
    int end;
    int length=0;
    int count=0;
    
    if(start>size){
        return maxlength;
    }

    while(n < size){
        end = start;
        while (end <= n)
        {
            s += a[end++];
            count++;
        }
        if(s <= k){
            length = count;
        }
        n++;
        s=0;
        count=0;
    }

    if(maxlength<length){
        maxlength = length;
    }
    
    slide(a,start+1,k,size,maxlength);
}

void main(){
    int size;
    int k;

    printf("Enter array size : ");
    scanf("%d",&size);

    int a[size];

    printf("\nEnter Array Element :- \n");
    
    for(int i=0; i<size; i++){
        printf("~");
        scanf("%d",&a[i]);
    }

    printf("\nEnter Integer : ");
    scanf("%d",&k);

    printf("max length = %d",slide(a,0,k,size,0));
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter size : ");
    scanf("%d",&size);

    int a[size];

    printf("Enter element : \n");
    for(int i=0; i<size; i++){
        printf("->");
        scanf("%d",&a[i]);
    }

    int search_num,h=size-1,l=0,mid=h/2;
    printf("Enter number for search : ");
    scanf("%d",&search_num);

    for(int i=0; i<(size/2)+1; i++){
        printf("*%d*",mid);
        if(a[mid]>search_num){
            h = mid-1;
        }
        else if(a[mid]<search_num){
            l = mid+1;
        }
        else if(a[mid]==search_num){
            printf("NUMBER AVAILABLE");
            exit(0);
        }
        mid = (l+h)/2;
    }

    printf("number not found");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int check(int [],int,int,int);

int check(int a[],int num,int l,int h){

    if(l>h){
    return 0;

    }
    int mid=(l+h)/2;
    if(a[mid]>num){
        h = mid-1;
        return check(a,num,l,h);
    }
    else if(a[mid]<num){
        l = mid+1;
        return check(a,num,l,h);
    }
    else if(a[mid]==num){
        return 1;
    }
}

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

    int search_num;
    printf("Enter number for search : ");
    scanf("%d",&search_num);

    if(check(a,search_num,0,size-1)){
        printf("NUMBER AVAILABLE");
    }
    else{
        printf("number not found");
    }    

    return 0;
}
#include <stdio.h>

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

    int search_num,count=0;
    printf("Enter number for search : ");
    scanf("%d",&search_num);
    for(int i=0; i<size; i++){
        if(a[i] == search_num){
            printf("number available");
            count++;
        }
    }
    if(count == 0){
        printf("number not found");
    }

    return 0;
}
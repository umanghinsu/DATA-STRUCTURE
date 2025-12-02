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

    int curr,min;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(a[j]<a[j+1]){
                min = j+1;
            }
        }
        a
    }

    for(int i=0; i<size; i++){
        printf("%d ",a[i]);
    }

    return 0;
}  
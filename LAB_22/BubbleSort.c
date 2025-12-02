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

    int temp;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(int i=0; i<size; i++){
        printf("%d ",a[i]);
    }

    return 0;
}  
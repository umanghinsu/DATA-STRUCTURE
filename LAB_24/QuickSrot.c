#include <stdio.h>

int partition(int a[], int start, int end){
    int index = start-1;
    int pivot = a[end];
    int temp;

    for(int j=start; j<end; j++){
        if(a[j] <= pivot){
            index++;
            temp = a[index];
            a[index] = a[j];
            a[j] = temp;
        }
    }

    index++;
    temp = a[index];
    a[index] = a[end];
    a[end] = temp;

    return index;
}

void quickSort(int a[], int start, int end){
    if(start < end){
        int pivot_index = partition(a,start,end);
        quickSort(a, start, pivot_index-1); //left
        quickSort(a, pivot_index+1, end); //right
    }
}

int main(){
    
    int a[] = {5,9,2,8,3,1};

    quickSort(a,0,5);

    for(int i=0; i<6; i++){
        printf("%d ",a[i]);
    }

    return 0;
}
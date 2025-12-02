#include <stdio.h>

void mergeSort(int [],int, int);
void merge(int [], int, int, int);

void mergeSort(int a[],int start,int end){
    if(start < end){
        int mid = start + ((end-start)/2);
        mergeSort(a,start,mid); //left
        mergeSort(a,mid+1,end); //right
        merge(a,start,mid,end);
    }
}

void merge(int a[],int start,int mid,int end){
    int i = start;
    int j = mid+1;
    int temp[6];
    int index=0;

    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            temp[index++] = a[i++];
        }
        else{
            temp[index++] = a[j++];
        }
    }

    //left
    while (i<=mid)
    {
        temp[index++] = a[i++];
    }

    //right
    while(j<=end){
        temp[index++] = a[j++];
    }

    for(int k=0; k<index; k++){
        a[start+k] = temp[k];
    }
    
}

void main(){

    int a[] = {5,9,2,8,3,1};

    mergeSort(a,0,5);

    for(int i=0; i<6; i++){
        printf("%d ",a[i]);
    }
}
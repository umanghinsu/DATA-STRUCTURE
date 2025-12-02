#include <stdio.h>
#define size 10

int set[size];

void setinitial(){
    for(int i=0; i<size; i++){
        set[i] = -1;
    }
}

int find(int value){
    return (value%size);
}

int prob(int index,int i){
    
    while(((index+i)%size) != index){
        if(set[index+i]==-1){
            return (index+i);
        }
        else{
            i++;
        }
    }
    printf("HasSet is full");
}

void add(int value){
    int index = find(value);
    if(set[index] != -1){
        int newindex = prob(index,1);
        set[newindex] = value;
    }
    else{
        set[index] = value;
    }
}

void main(){
    setinitial();
    int arr[7] = {1,2,36,4,5,6,25};
    for(int i=0; i<7; i++){
        add(arr[i]);
    }

    for(int i=0; i<size; i++){
        printf("%d ",set[i]);
    }
}
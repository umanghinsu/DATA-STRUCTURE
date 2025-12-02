#include <stdio.h>
#include <stdlib.h>

void enQueue(int [], int *, int *, int);
void deQueue(int [], int *, int *);
void display(int [], int, int, int);

void enQueue(int queue[], int *F, int *R, int size){
    
    if(*R == size-1) *R = 0;
    else (*R)++;
    if(*F == *R){
        printf("Queue is over flow");
        return;
    }
    
    printf("Enter Number for Enqueue : ");
    scanf("%d",&queue[*R]);
    
    if(*F == -1) *F = 0;
}

void deQueue(int queue[], int *F, int *R){
    if(*F == -1){
        printf("Queue is under flow");
        return;
    }

    if(*F == *R){
        *F = -1;
        *R = -1;
    }
    else{
        (*F)++;
    }
    return;
}

void display(int queue[], int F, int R,int size){
    if(F == -1 && F == R){
        printf("Queue is empty\n");
        return;
    }
    int i=F;
    while(1){
        printf("%d ",queue[i]);
        if(i==R) break;
        i = (i+1)%size;
    }
}

void main(){
    int size;
    printf("Enter Size of Queue : ");
    scanf("%d",&size);
    
    int F = -1;
    int R = -1;
    int queue[size];

    int n,num;
    while(1){
        printf("\n1   Enqueue\n");
        printf("2   Dequeue\n");
        printf("3   Display\n");
        printf("0   exit\n");
        printf("Enter number : ");
        scanf("%d",&n);
        
        switch(n){
            case 1:
            enQueue(queue,&F,&R,size);
            break;
            
            case 2:
            deQueue(queue,&F,&R);
            break;

            case 3:
            display(queue,F,R,size);
            break;

            case 0:
            exit(0);
        }
    }

}
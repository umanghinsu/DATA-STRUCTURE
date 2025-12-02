#include <stdio.h>
#include <stdlib.h>

// void enQueue(struct element *[], int *, int *, int);
// void deQueue(struct element *[], int *, int *);
// void display(struct element *[], int, int);

struct element{
    int data;
    int priority;
};

void enQueue(struct element queue[], int *F, int *R, int size){
    if(*R >= size-1){
        printf("Queue is over flow");
        return;
    }
    
    int data,priority;
    printf("    Enqueue\n    Enter Number : ");
    scanf("%d",&data);
    printf("    Enter Priority : ");
    scanf("%d",&priority);

    if(*F == -1 && *R == -1){
        (*F)++;
        (*R)++;
        queue[*R].data = data;
        queue[*R].priority = priority;
        return;
    }
    int i;
    for(i=*F; i<=*R; i++){
        if(queue[i].priority < priority){
            for(int j=*R; j >= i; j--){
                queue[j+1] = queue[j]; 
            }
            break;
        }
    }

    queue[i].data = data;
    queue[i].priority = priority;
    (*R)++;
    
}

void deQueue(struct element queue[], int *F, int *R){
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

void display(struct element queue[], int F, int R, int size){
    if(F == -1 && F == R){
        printf("Queue is empty\n");
        return;
    }
    printf("data-priority\n");

    int i=F;
    while(1){
        printf("%d-%d |",queue[i].data,queue[i].priority);
        if(i==R) break;
        i = (i+1)%size;
    }
}

int main(){

    int size;
    printf("Enter Size of priority Queue : ");
    scanf("%d",&size);
    
    int F = -1;
    int R = -1;
    struct element *queue = (struct element *)malloc(size*(sizeof(struct element)));

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

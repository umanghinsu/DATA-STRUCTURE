#include <stdio.h>

#define size 10

int stack[size],input[size],output[size];
int top = -1,count = 0;

void push(int n){
    if(top >= size-1){
        printf("stack ovreflow");
        return;
    }

    stack[++top] = n;
}

int pop(){
    if(top == -1){
        printf("stack underflow");
    }
    else{
        return stack[top--];
    }   
}

void stackSortabilityCheck(){
    
    int i=0, j=0;

    while(i != count){
        
        while(top != -1 && stack[top] <= input[i]){
            output[j++] = pop();                        
        }
        push(input[i]);
        i++;
    }

    while(top != -1){
        output[j++] = pop();
    }
    
    for(int i=0; i<count; i++){
        printf("%d ",output[i]);
    }

    int k = 0;
    while(k != count-1){
        if(output[k]>output[k+1]){
            printf("\nNO");
            return;    
        }
        k++;
    }
    printf("\nYES");
}

void main(){

    int n;
    printf("Enter number (-1 for stop) : \n");
    for(int i=0; i<10; i++){
        printf("->");
        scanf("%d",&n);
        if(n == -1){
            break;
        }
        input[i] = n;
        count++;
    }

    if (count == 0) {
        printf("No input provided.\n");
    }   

    stackSortabilityCheck();
}
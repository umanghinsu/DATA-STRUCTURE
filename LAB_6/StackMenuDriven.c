#include <stdio.h>
#include <stdlib.h>

int stack[10],top=-1;

void push(){
    int x;
    if(top > 10){
        printf("stack is full");
        return;
    }
    printf("Enter number = ");
    scanf("%d",&x);

    stack[++top] = x;
}

int pop(){
    if(top == -1){
        printf("stack underflow");
    }
    else{
        return stack[top--];
    }   
}

int peep(int i){
    if(top-i+1 <= 0){
        printf("stack underflow");
    }
    else{
        printf("%d\n",stack[top - i +1]);
    }
}

int change(int i, int x){
    if(top-i+1 <= 0){
        printf("stack underflow");
    }
    else{
        stack[top - i +1] = x;
    }
}

void display(){
    if(top == -1){
        printf("stack underflow");
    }
    else{
        int temp = top;
        for(int i=temp; i>=0; i--)
        printf("%d\n",stack[i]);
    }
}
void main(){
    int n;
    while(1)
    {
        int i,x;
    printf("\nenter 1 push\n");
    printf("enter 2 pop\n");
    printf("enter 3 peep\n");
    printf("enter 4 change\n");
    printf("enter 5 display\n");
    printf("enter 0 for end\n");

    printf("\nenter above number to you want to do");
    printf("\nnumber = ");
    scanf("%d",&n);
        switch (n)
        {
            case 1: 
            push();
            break;
            
            case 2:
            pop();
            break;
            
            case 3:
            printf("enter i for you want to show number : ");
            scanf("%d",&i);
            peep(i);
            break;
            
            case 4:
            printf("enter i for you want to change : ");
            scanf("%d",&i);
            printf("enter value for you want to change : ");
            scanf("%d",&x);
            change(i,x);
            break;
            
            case 5:
            display();
            break;

            case 0:
            exit(0);
        }
    }
}
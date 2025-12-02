#include <stdio.h>

char stack[50],string[50];
int top = -1;

void getString();
void push(char);
char pop();
void display();

void getString(){   
    printf("enter string : ");
    scanf("%49s",string);

    int i=0;
    while(string[i] != 'c'){
        push(string[i++]);
    }
    i++;
    while(string[i] != '\0'){
        if(string[i++] == stack[top]){
            pop();
        }
        else{
            break;
        }
    }
    if(top == -1){
        printf("stack is palindrom");
        return;
    }
    else{
        printf("stack is not palindrom");
        return;
    }
}

void push(char c){
    if(top > 50){
        printf("stack ovreflow");
        return;
    }

    stack[++top] = c;
}

char pop(){
    if(top == -1){
        printf("stack underflow");
    }
    else{
        return stack[top--];
    }   
}

int main(){
    getString();
    return 0;
}
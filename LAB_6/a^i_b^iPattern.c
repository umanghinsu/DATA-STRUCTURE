#include <stdio.h>

char stack[50],string[50];
int top = -1;

void getString();
void push(char);
char pop();
void display();

void push(char c){
    if(top >= 49){
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

void getString(){
    printf("enter string : ");
    scanf("%49s",string);

    int i=0;
    while(string[i] != '\0'){
        if(string[i] == string[0]){
            push(string[i]);
        }
        i++;
    }

    i=0;
    while(string[i] != '\0'){
        if(string[i++] != string[0]){
            pop();
        }
    }

    if(top == -1){
        printf("\na^i b^i pattern is present");
        return;
    }
    else{
        printf("\na^i b^i pattern is absent");
        return;
    }
}

int main(){
    getString();
    return 0;
}
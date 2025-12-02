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

    if(stack[0] == ']' || stack[0] == ')' || stack[0] == '}'){
        return;
    }

    int i=0;
    while(string[i] != '\0'){

        if(string[i] == '{'){
            push('}');
        }
        else if(string[i] == '['){
            push(']');
        }
        else if(string[i] == '('){
            push(')');
        }
        else if(string[i] == '}' && stack[top] == '}'){
            pop();
        }
        else if(string[i] == ']' && stack[top] == ']'){
            pop();
        }
        else if(string[i] == ')' && stack[top] == ')'){
            pop();
        }

        i++;
    }
    if(top == -1){
        printf("1");
        return;
    }
    else{
        printf("0");
        return;
    }
    
}

void push(char c){
    if(top > 50){
        printf("stack is full");
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
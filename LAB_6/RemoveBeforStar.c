#include <stdio.h>
#include <string.h>

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
    while(i != strlen(string)){

        if(string[i] == '*'){
           pop();
        }
        else
        {
            push(string[i]);
        }

        i++;
    }

    stack[top+1] = '\0';
    printf("%s",stack);
}

int main(){
    getString();
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void push(int);
int pop();
int opration(int, int, char);

int stack[100];
int top = -1;

void postfixEval(char postfix[]){

    int value = 0;
    for(int i=0; i<strlen(postfix); i++){
        
        if(isdigit(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            int op2=pop();
            int op1=pop();
            value = opration(op1,op2,postfix[i]);
            push(value);
        }
    }
}

int opration(int oprand1, int oprand2, char oprator){
    switch (oprator)
    {
        case '+':
            return oprand1+oprand2;
            break;

        case '-':
            return oprand1-oprand2;
            break;

        case '*':
            return oprand1*oprand2;
            break;

        case '/':
            return oprand1/oprand2;
            break;
            
        case '^':
            return pow(oprand1,oprand2);
            break;

        default:
            break;
    }
}

void push(int n){
    if(top > 100){
        printf("\nstack ovreflow");
        return;
    }

    stack[++top] = n;
}

int pop(){
    if(top <= -1){
        printf("\nstack underflow");
    }
    else{
        int n = stack[top];
        stack[top] = '\0';
        top--;
        return n;
    } 
}

void main(){  

    char postfix[100];
    printf("enter postfix : ");
    scanf("%99s",postfix);
    postfixEval(postfix);
    printf("Ans = %d",pop());
}
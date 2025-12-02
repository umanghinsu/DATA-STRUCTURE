#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void push(int);
int pop();
int opration(int, int, char);

int stack[100];
int top = -1;

void prefixEval(char prefix[]){

    int value = 0;
    for(int i=strlen(prefix); i>=0; i--){
        
        if(isdigit(prefix[i])){
            push(prefix[i]-'0');
        }
        else{
            int op1=pop();
            int op2=pop();
            value = opration(op1,op2,prefix[i]);
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

    char prefix[100];
    printf("enter prefix : ");
    scanf("%99s",prefix);
    prefixEval(prefix);
    printf("Ans = %d",pop());
}
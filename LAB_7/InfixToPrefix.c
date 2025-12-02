#include <stdio.h>
#include <string.h>

void push(char);
char pop();
void display(char []);

char stack[100];
int top = -1;

int sta_pre(char c){
    switch (c)
    {
        case '+':
            return 1;
            break;

        case '-':
            return 1;
            break;

        case '*':
            return 3;
            break;

        case '/':
            return 3;
            break;
            
        case '^':
            return 6;
            break;

        case '(':
            return 0;
            break;

        default:
            return 8;
            break;
    }
}

int in_pre(char c){
    switch (c)
    {
        case '+':
            return 2;
            break;

        case '-':
            return 2;
            break;

        case '*':
            return 4;
            break;

        case '/':
            return 4;
            break;
            
        case '^':
            return 5;
            break;

        case '(':
            return 9;
            break;

        case ')':
            return 0;
            break;

        default:
            return 7;
            break;
    }
}

int r(char c){
    switch (c)
    {
        case '+':
            return -1;
            break;

        case '-':
            return -1;
            break;

        case '*':
            return -1;
            break;

        case '/':
            return -1;
            break;
            
        case '^':
            return -1;
            break;

        case '(':
            return 0;
            break;
        
        case ')':
            return 0;
            break;

        default:
            return 1;
            break;
    }
}

void infixToprefix(char infix[]){

    char prefix[100];
    int i = 0,n=0;
    int j = 0;
    int rank = 0;
    char temp;

    push('(');
    
    while(i != strlen(infix)){
        char next = infix[i];
        if(top <= -1){
            printf("INVALID");
            return;
        }
        else{
            while(sta_pre(stack[top]) > in_pre(next)){
                temp = pop();
                prefix[j++] = temp;
                rank += r(temp);
                if(rank < 1){
                    printf("INVALID");
                    return;
                }
            }
            
            if(sta_pre(stack[top]) != in_pre(next)){
                push(next);
            }
            else{
                pop();
            }
        }
        i++;
    }
    
    prefix[j] = '\0';
    if(top != -1 || rank != 1){
        printf("INVALID hello");      
    }
    else{
        printf("%s",strrev(prefix));                
    }   
}

void push(char c){
    if(top > 100){
        printf("stack ovreflow");
        return;
    }

    stack[++top] = c;
}

char pop(){
    if(top <= -1){
        printf("stack underflow");
    }
    else{
        return stack[top--];
    } 
}

void main(){

    char infix[100];
    printf("enter INFIX : ");
    scanf("%99s",infix);

    for(int i=0; i<strlen(infix); i++){
        switch(infix[i]){
            case '(':
            infix[i] = ')';
            break;
            
            case ')':
            infix[i] = '(';
            break;

            default:
            break;
        }
    }

    strrev(infix);
    strcat(infix,")");
    
    infixToprefix(infix);
}



            // display(stack);
            // printf("\ninfix %c\n",next);
            // printf("s_pre %d\n",sta_pre(stack[top]));
            // printf("in_pre %d\n",in_pre(next));
            // display(prefix);
            // printf("\n----------------\n");
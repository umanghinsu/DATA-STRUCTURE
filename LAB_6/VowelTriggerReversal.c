#include <stdio.h>
#include <string.h>

char stack[100],string[100];
int top = -1;

void push(char c){
    if(top >= 49){
        printf("stack ovreflow");
        return;
    }

    stack[++top] = c;
}

void vowelTriggerReversal(){
    printf("Enter string : ");
    scanf("%99s",string);

    int i=0;
    while(i != strlen(string)){
        if(string[i] == 'a' ||string[i] == 'e' ||string[i] == 'i' ||string[i] == 'o' ||string[i] == 'u'){
            strrev(stack);
        }
        push(string[i]);
        i++;
    }

    stack[++top] = '\0';
    printf("%s",stack);
}

void main(){
    vowelTriggerReversal();
}
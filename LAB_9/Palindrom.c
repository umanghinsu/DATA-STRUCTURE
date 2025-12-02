#include <stdio.h>

void main(){
    char s[20];
    int length = 0;
    int is_palindrome = 1;

    printf("Enter string: ");
    scanf("%19s", s);

    while(s[length] != '\0'){
        length++;
    }

    for(int i=0; i<length/2; i++){
        if(s[i]!=s[length-1-i]){
            is_palindrome = 0;
            break;
        }
    }
    
    if(is_palindrome){
        printf("string is palindrom");
    }
    else{
        printf("string is not palindrom");
    }
}
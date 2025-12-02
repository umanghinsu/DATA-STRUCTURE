#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char s[50];

    printf("Enter string : ");
    for(int i=0; i<50; i++){

        scanf("%[^\n]",s);
    }

    for(int i=0; s[i]!='\0'; i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = s[i] + 32;
            continue;
        }
        if(s[i]>='a' && s[i]<='z'){
            s[i] = s[i] - 32;
            continue;
        }
    }

        printf("%s",s);

}
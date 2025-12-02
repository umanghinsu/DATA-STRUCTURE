#include <stdio.h>
#include <string.h>

void main()
{
    char name[5][10];

    for(int i=0; i<5; i++)
    {
        scanf("%9s",name[i]);
    }

    for(int i=0; i<4; i++){
        for(int j=i; j<5; j++){
            if(strcmp(name[i],name[j]) > 0){
                char temp[10];
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }
    for(int i=0; i<5; i++)
    {
        printf("%s\n",name[i]);
    }
}
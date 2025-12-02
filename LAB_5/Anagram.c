#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int anagram(char word[], char new_word[]);
void sortstring(char str[]);

int anagram(char word[], char new_word[])
{
    char word1[100], word2[100];

    strcpy(word1,word);
    strcpy(word2,new_word);
    strlwr(word1);
    strlwr(word2);
    sortstring(word1);
    sortstring(word2);

    return strcmp(word1,word2) == 0;
}

void sortstring(char str[])
{
    for(int i=0; i<str[i]!='\0'; i++)
    {
        for(int j=0; j<str[i]!='\0'; j++)
        {
            if(str[j]>str[j+1])
            {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}
void main (){

    int n;
    int index;
    char new_word[100];

    printf("enter number of you want to enter : ");
    scanf("%d",&n);

    char word[n][100];

    for(int i=0; i<n; i++)
    {
        scanf("%s",&word[i]);
    }

    srand(time(0));
    index = rand()%n;
    
    printf("\nword of array :  %s",word[index]);

    printf("\nenter new word : ");
    scanf("%s",&new_word);
    
    
    if(anagram(word[index],new_word))
    {
        printf("string is anagram");
    }
    else
    {
        printf("string is not anagram");
    }
}
#include <stdio.h>
#include <string.h>
#define size 10

struct map{
    char key[10];
    int value;
};

struct map Hmap[size];

int find(int value){
    return (value%size);
}

int asciivalue(char key[]){
    int asciivaalue = 0;
    for(int i=0; i<strlen(key); i++){
        asciivaalue += key[i];
    }
    return asciivaalue;
}

int prob(int index,int i){
    
    while(((index+i)%size) != index){
        if(Hmap[index+i].key[0] == '\0'){
            return (index+i);
        }
        else{
            i++;
        }
    }
    printf("HasHmap is full");
}

void add(char key[],int value){
    int index = find(asciivalue(key));
    char tempkey[10];
    strcpy(tempkey,key);

    if(Hmap[index].key[0] != '\0'){
        if(strcmp(key,Hmap[index].key) == 0){
            Hmap[index].value = value;
        }
        else{
            int newindex = prob(index,1);
            strcpy(Hmap[index].key,key);
            Hmap[index].value = value;
        }
    }
    else{
        strcpy(Hmap[index].key,key);
        Hmap[index].value = value;
    }
}

void main(){
    char Hmapkey[7][10] = {"abc","bcd","cde","def","efg","fgh","hij"};
    int value[7] = {1,2,3,4,5,6,7};
    
    for(int i=0; i<7; i++){
        add(Hmapkey[i],value[i]);
    }

    for(int i=0; i<size; i++){
        printf("%s-%d | ",Hmap[i].key,Hmap[i].value);
    }
}
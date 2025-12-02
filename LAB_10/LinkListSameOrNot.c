#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};


struct node *insertAtlast(struct node **head){
    int x=0;

    while(x != -1){
        printf("enter(-1 for exit) x =");
        scanf("%d",&x);
    
        if(x == -1){
            break;
        }
    
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->info = x;
        
        if(*head == NULL){
            newnode->link = *head;
            *head = newnode;
        }
        else{
            struct node *save = *head;
            
            while(save->link != NULL){
                save = save->link;
            }

            save->link = newnode;
            newnode->link = NULL;
        }
    
    }
    return *head;  
}  

void sameOrNot(struct node *first1,struct node *first2){
    if(first1 == NULL || first2 == NULL){
        printf("one link list is null");
        return;
    }
    while(first1 != NULL && first2 != NULL){
        struct node *save1 = first1;
        struct node *save2 = first2;
        if(first1->info == first2->info){
            save1 = first1;
            save2 = first2;
            first1 = first1->link;
            first2 = first2->link;
            free(save1);
            free(save2);
        }
    }
    if(first1 !=NULL || first2 != NULL){
        printf("link list is not same");
    }
    else{
        printf("link list is same");
    }
}

void main(){

    struct node *first1 = NULL;
    struct node *first2 = NULL;

    first1 = insertAtlast(&first1);
    first2 = insertAtlast(&first2);

    sameOrNot(first1,first2);
}
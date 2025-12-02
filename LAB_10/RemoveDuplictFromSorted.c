#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

// Function to insert a new node at the end of the linked list
struct node *insertAtEnd(struct node **head){
    struct node *first = *head;

    int x;
    while(1){
        printf("Enter number(-1 for exit) for insert = ");
        scanf("%d",&x);
        
        if(x == -1){
            break;
        }

        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->info = x;
        
        if(first == NULL){
            newnode->link = first;
            first = newnode;
        }
        else{
            struct node *save = first;
            
            while(save->link != NULL){
                save = save->link;
            }

            save->link = newnode;
            newnode->link = NULL;
        }
    }
    
    return first;
}

//Remove duplicate
struct node *removeDuplicate(struct node **head){

    struct node *first = *head;
    struct node *save = first;

    while(save != NULL && save->link != NULL){
        if(save->info == save->link->info){
            struct node *temp = save->link;
            save->link = temp->link;
            free(temp);
        }
        else{
            save =save->link;
        }
    }
    return first;
}

//display
void displayNode(struct node *first){
    if(first == NULL){
        printf("link list is empty");
        return;
    }
    struct node* save = first;
    while(save!= NULL){
        printf("%d ",save->info);
        save = save->link;
    }
}
void main(){
    struct node *first = NULL;

    printf("insert sorted link list\n\n");

    first = insertAtEnd(&first);
    first = removeDuplicate(&first);

    displayNode(first);
}
#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

// Function to insert a new node at the end of the linked list
struct node *enqueue(struct node **head){
    struct node *first = *head;
    int x;
    while(1){
        printf("Enter number (-1 for exit) for insert = ");
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

// Function to delete the first node of the linked list
struct node *dequeue(struct node **head){

    struct node *first = *head;
    if(first == NULL){
        return first;
    }

    struct node *save = first;
    first = first->link;
    free(save);

    return first;
}

// Function to display all nodes in the linked list
void displayNode(struct node **head){

    struct node *first = *head;
    
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

    first = enqueue(&first);
    first = dequeue(&first);

    displayNode(&first);
}
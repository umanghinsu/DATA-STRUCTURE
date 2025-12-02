#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

// Function to insert a new node at the end of the linked list
struct node *insertAtLast(struct node **head){
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

//copy
struct node *copy(struct node **head1,struct node **head2){
    struct node *first = *head1;
    struct node *begin = *head2;
    struct node *save = *head1;

    while(save != NULL){
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = save->info;
        
        if(first == NULL){
            return first;
        }

        if(begin == NULL){
            newnode->link = begin;
            begin = newnode;
        }
        else{
            struct node *pred = begin;

            while(pred->link != NULL){
                pred = pred->link;
            }

            pred->link = newnode;
            newnode->link = NULL;
        }
        save = save->link;
    }
    return begin;
}

// Function to display all nodes in the linked list
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
    struct node *begin = NULL;

    first = insertAtLast(&first);
    begin = copy(&first,&begin);
    displayNode(begin);
}
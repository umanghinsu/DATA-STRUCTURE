#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};

// Function to insert a new node at the last of the linked list
struct node *insertAtLast(struct node **head){
    struct node *first = *head;
    int x;

    while(1){
        printf("Enter number (-1 for exit) for insert last : ");
        scanf("%d",&x);
    
        if(x == -1){
            break;
        }
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = x;
    
        if(first == NULL){
            newnode->lptr = newnode;
            newnode->rptr = newnode;
            first = newnode;
        }
        else{
            
            struct node *last = first;
            while(last->rptr != first){
                last = last->rptr;
            }
            newnode->lptr = last;
            last->rptr = newnode;
            newnode->rptr = first;
            first->lptr = newnode;
        }
    }

    return first;
}

// Function to display all nodes in the linked list
void displayNode(struct node **head){

    struct node *first = *head;

    if(first == NULL){
        printf("link list is empty");
        return;
    }
    struct node *last = first;
    do{
        printf("%d ",last->info);
        last = last->rptr;          // print normal then write 'rptr' for reverse 'lptr'
    }while(last != first);
}

void main(){

    struct node *first = NULL;

    first = insertAtLast(&first);
    displayNode(&first);
}
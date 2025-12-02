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
            newnode->lptr = NULL;
            newnode->rptr = NULL;
            first = newnode;
        }
        else{
            newnode->rptr = NULL;
            struct node *last = first;
            while(last->rptr != NULL){
                last = last->rptr;
            }
            newnode->lptr = last;
            last->rptr = newnode;
        }
    }

    return first;
}

//Delete alternate node
struct node *deleteAlternate(struct node **head){
    struct node *first = *head;
    struct node *save = first;
    struct node *pred = first;

    if(first == NULL){
        return first;
    }

    //only one node
    if(save->lptr ==NULL && save->rptr == NULL){
        printf("Link List have only one node\n");
        return first;
    }

    while(1){
        pred = save;
        save = save->rptr;
        if(save->rptr == NULL){
            break;
        }
        pred->rptr = save->rptr;
        (save->rptr)->lptr = pred;
        free(save);
        struct node *save = pred;
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
    
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d ",save->info);
        save = save->rptr;
    }
}

void main(){

    struct node *first = NULL;

    first = insertAtLast(&first);
    first = deleteAlternate(&first);
    displayNode(&first);
}
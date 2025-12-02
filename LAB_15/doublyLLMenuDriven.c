#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};

// Function to insert a new node at the beginning of the linked list
struct node *insertAtFirst(struct node **head){
    struct node *first = *head;
    int x;

    printf("Enter number (-1 for exit) for insert first : ");
    scanf("%d",&x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;

    if(first == NULL){
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        first = newnode;
    }
    else{
        newnode->lptr = NULL;
        newnode->rptr = first;
        first->lptr = newnode;
        first = newnode;
    }
    
    return first;
}

// Function to insert a new node at the last of the linked list
struct node *insertAtLast(struct node **head){
    struct node *first = *head;
    int x;

    printf("Enter number (-1 for exit) for insert last : ");
    scanf("%d",&x);

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

    return first;
}

//Delete node from specific position
struct node *delete(struct node **head){
    struct node *first = *head;
    struct node *save = first;
    struct node *pred = NULL;
    int x;

    if(first == NULL){
        printf("link list is empty\n");
        return first;
    }
    printf("Enter number for delete : ");
    scanf("%d",&x);

    while(save->rptr != NULL && save->info != x){
        pred = save;
        save = save->rptr;
    }

    // LL have only one node
    if(save == first && save->lptr == NULL && save->rptr == NULL){
        free(save);
        first = NULL;
        return first;
    }

    //for first node
    if(pred == NULL){
        first = first->rptr;
        first->lptr = NULL;
        free(save);
        return first;
    }

    //other node
    pred->rptr = save->rptr;
    (save->rptr)->lptr = pred;
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
    
    struct node *save = first;
    while (save != NULL){
        printf("%d ",save->info);
        save = save->rptr;
    }
}

void main(){

    struct node *first = NULL;
    int n;

    while(1)
    {
    printf("\nenter 1 Insert a node at the front of the doubly linked list.\n");
    printf("enter 2 Delete node from specific position.\n");
    printf("enter 3 Insert a node at the end of the doubly linked list.\n");
    printf("enter 4 Display all node.\n");
    printf("enter 0 for end else to continu\n");

    printf("\nenter above number to you want to do");
    printf("\nnumber = ");
    scanf("%d",&n);
        switch (n)
        {
            case 1: 
            first = insertAtFirst(&first);
            break;
            
            case 2:
            first = delete(&first);
            break;
            
            case 3:
            first = insertAtLast(&first);
            break;
            
            case 4:
            displayNode(&first);
            break;
            
            case 0:
            exit(0);
        }
    }
}
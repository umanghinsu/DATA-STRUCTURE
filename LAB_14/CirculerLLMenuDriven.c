#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *link;
};

struct node *first = NULL;

// Function to insert a new node at the beginning of the linked list
void insertAtFirst(){
    int x;
    printf("Enter number for insert = ");
    scanf("%d",&x);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = x;

    if(first == NULL){
        newnode->link = newnode;
        first = newnode;
    }
    else{
        struct node *last = first;
        while(last->link != first){
            last = last->link;
        }
        last->link = newnode;
        newnode ->link = first;
        first = newnode;
    }
}

// Function to display all nodes in the linked list
void displayNode(){
    if(first == NULL){
        printf("link list is empty");
        return;
    }
    struct node *last = first;
    do{
        printf("%d ",last->info);
        last = last->link;
    }while(last != first);
}

//delete from specific position
void delete(){
    int x;

    if(first == NULL){
        printf("link list is empty\n");
        return;
    }
    printf("Enter number for delete : ");
    scanf("%d",&x);

    struct node *save = first;
    struct node *pred = NULL;

    do{
        if(save->info == x){
            break;
        }
        pred = save;
        save = save->link;
    }while(save != first);

    if(save->info != x){
        printf("node not found");
        return;
    }
    
    //only one node exsist
    if(save == first && save->link == first){
        free(save);
        first = NULL;
        return;
    }

    //first node
    if(save == first){
        struct node *last = first;
        while(last->link != first){
            last = last->link;
        }
        first = first->link;
        last->link = first;
    }
    //other node
    else{
        pred->link = save->link;
    }
    free(save);
}

// Function to insert a new node at the last of the linked list
void insertAtEnd(){
    int x;
    printf("Enter number for insert = ");
    scanf("%d",&x);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = x;

    if(first == NULL){
        newnode->link = newnode;
        first = newnode;
    }
    else{
        struct node *last = first;
        while(last->link != first){
            last = last->link;
        }
        last->link = newnode;
        newnode ->link = first;
        last = newnode;
    }
}

void main(){
    int n;
    while(1)
    {
    printf("\nenter 1 Insert a node at the front of the circuler linked list.\n");
    printf("enter 2 Delete node from specific position.\n");
    printf("enter 3 Insert a node at the end of the circuler linked list.\n");
    printf("enter 4 Display all node.\n");
    printf("enter 0 for end else to continu\n");

    printf("\nenter above number to you want to do");
    printf("\nnumber = ");
    scanf("%d",&n);
        switch (n)
        {
            case 1: 
            insertAtFirst();
            break;
            
            case 2:
            delete();
            break;
            
            case 3:
            insertAtEnd();
            break;
            
            case 4:
            displayNode();
            break;
            
            case 0:
            exit(0);
        }
    }
}
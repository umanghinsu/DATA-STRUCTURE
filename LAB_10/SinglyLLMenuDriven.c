#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first =NULL;

// Function to insert a new node at the beginning of the linked list
void insertAtFirst(){
    int x;
    printf("Enter number for insert = ");
    scanf("%d",&x);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->link =first;
    newnode->info = x;
    first = newnode;
}

// Function to display all nodes in the linked list
void displayNode(){
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


// Function to delete the first node of the linked list
void deleteAtFirst(){

    if(first == NULL){
        printf("link list is empty");
        return;
    }

    struct node *save = first;
    first = first->link;
    free(save);
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(){
    int x;
    printf("Enter number for insert = ");
    scanf("%d",&x);
    
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

// Function to delete the last node of the linked list
void deleteAtLast(){

    if(first == NULL){
        printf("link list is empty");
        return;
    }

    struct node *save = first;
    struct node *pred = first;

    while(save->link != NULL){
        pred = save;
        save = save->link;
    }

    pred->link = NULL;
    free(save);

}

// function Delete a node from specified position.
void deletAtAnyWhere(){

    int x;
    printf("Enter number for delete = ");
    scanf("%d",&x);

    if(first == NULL){
        printf("link list is empty");
        return;
    }

    struct node *save = first;
    struct node *pred = NULL;
    
    while(save != NULL && save->info !=x){
        pred = save;
        save = save->link;
    }
    if(save == NULL){
        printf("node not found");
        return;
    }

    if(pred == NULL){
        first = save->link;
    }
    else{
        pred->link = save->link;
    }

    free(save);
}

void CountNumOfNode(){
    int count=0;

    if(first == NULL){
        printf("link list is empty");
        return;
    }
    struct node* save = first;
    while(save!= NULL){
        count++;
        save = save->link;
    }
    
    printf("%d nodes in link list",count);
}

void main(){
    
    int n;
    while(1)
    {
    printf("\nenter 1 Insert a node at the front of the linked list.\n");
    printf("enter 2 Display all nodes.\n");
    printf("enter 3 Delete a first node of the linked list.\n");
    printf("enter 4 Insert a node at the end of the linked list.\n");
    printf("enter 5 Delete a last node of the linked list.\n");
    printf("enter 6 Delete a node from specified position.\n");
    printf("enter 7 count number of nodes.\n");
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
            displayNode();
            break;

            case 3:
            deleteAtFirst();
            break;

            case 4:
            insertAtEnd();
            break;

            case 5:
            deleteAtLast();
            break;

            case 6:
            deletAtAnyWhere();
            break;

            case 7:
            CountNumOfNode();
            break;
            
            case 0:
                exit(0);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

void displayNode(struct node *);


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
            newnode->link = newnode;
            first = newnode;
        }
        else{
            struct node *last = first;
            while(last->link != first){
                last = last->link;
            }
            last->link = newnode;
            newnode->link = first;
            last = newnode;
        }
    }
    return first;
}

struct node *splitLL(struct node **head){
    struct node *first = *head;
    if(first == NULL){
        printf("link list is empty");
        return first;
    }
    if(first->link == NULL){
        printf("link list have only node");
        return first;
    }

    struct node *save1 = first;
    struct node *save2 = first;

    while(save2->link != first && save2->link->link != first){
        save1 = save1->link;
        save2 = save2->link->link;
    }

    struct node *firstHalf = first;
    struct node *secondHalf = save1->link;

    save1->link = firstHalf;
    if(save2->link->link == first){
        save2 = save2->link;
    }
    save2->link = secondHalf;

    displayNode(firstHalf);
    printf("\n");
    displayNode(secondHalf);
}


// Function to display all nodes in the linked list
void displayNode(struct node *first){
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

void main(){
    struct node *first = NULL;
    
    first = insertAtLast(&first);
    
    splitLL(&first);
}
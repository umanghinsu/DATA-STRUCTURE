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

//sorting
struct node *sort(struct node **head){

    struct node *first = *head;

    for(struct node *i=first; i!=NULL; i=i->link){

        for(struct node *j=first; j->link!=NULL; j=j->link){

            if(j->info > (j->link)->info){
                int temp = j->info;
                j->info = (j->link)->info;
                (j->link)->info = temp;
            }
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
    while(save != NULL){
        printf("%d ",save->info);
        save = save->link;
    }
}

void main(){
    struct node *first = NULL;

    first = insertAtEnd(&first);
    first = sort(&first);

    displayNode(first);
}
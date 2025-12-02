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

//swap Kth node
// struct node *swapKthNode(struct node **head){
//     struct node *first = *head;
//     struct node *save1 = first;
//     struct node *perd1 = NULL;
//     struct node *save2 = first;
//     struct node *perd2 = NULL;
    
//     int k,count=0;
//     printf("enter k for swap : ");
//     scanf("%d",&k);
    
//     //count total    node
//     struct node *temp = first;
//     while(temp != NULL){
//         count++;
//         temp = temp->link;
//     }
    
//     if(k > count || k < 1){
//         printf("invalid k's value");
//         return first;
//     }
    
//     //k == count - k + 1
//     if(2 * k -1 == count){
//         return first;
//     }

//     for(int i=1; i<count-k+1; i++){
//         perd2 = save2;
//         save2 = save2->link;    
//     }
    
//     for(int i=1; i<k; i++){
//         perd1 = save1;
//         save1 = save1->link;
//     }


//     //only 2 node exist
//     if(count == 2){
//         save2->link = save1;
//         save1->link = NULL;
//         first = save2;
//         return first;
//     }

//     // swap first & last node
//     if(k==1){
//         save2->link = save1->link;
//         first = save2;
//         perd2->link = save1;
//         save1->link = NULL;
//         return first;
//     }

//     //save1 & save2 is alternate
//     //if(save1->link == save2){
//     if(k+1 == count - k + 1){
//         save1->link = save2->link;
//         perd1->link = save2;
//         save2->link = save1;
//         return first;
//     }

//     perd1->link = save2;
//     perd2->link = save2->link;
//     save2->link = save1->link;
//     save1->link = perd2->link;
//     perd2->link = save1;
//     return first;
// }

struct node *swapKthNode(struct node **head){
    struct node *first = *head;
    if(first == NULL) return NULL;

    int k, count = 0;
    printf("Enter k for swap: ");
    scanf("%d", &k);

    struct node *temp = first;
    while(temp != NULL){
        count++;
        temp = temp->link;
    }

    if(k > count || k < 1){
        printf("Invalid k value\n");
        return first;
    }

    if(2 * k - 1 == count){
        // Same node from start and end
        return first;
    }

    // Find k-th node from start
    struct node *prev1 = NULL, *curr1 = first;
    for(int i = 1; i < k; i++){
        prev1 = curr1;
        curr1 = curr1->link;
    }

    // Find k-th node from end
    struct node *prev2 = NULL, *curr2 = first;
    for(int i = 1; i < count - k + 1; i++){
        prev2 = curr2;
        curr2 = curr2->link;
    }

    // If either is head
    if(prev1 != NULL)
        prev1->link = curr2;
    else
        first = curr2;

    if(prev2 != NULL)
        prev2->link = curr1;
    else
        first = curr1;

    // Swap next pointers
    struct node *tempLink = curr1->link;
    curr1->link = curr2->link;
    curr2->link = tempLink;

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
    
    first = insertAtLast(&first);
    first = swapKthNode(&first);
    displayNode(&first);
}
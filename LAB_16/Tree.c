#include <stdio.h>
#include <stdlib.h>

struct node *preOrder(struct node *);
struct node *createNode(int);
struct node *createTree(struct node *);


struct node{
    int info;
    struct node *lptr, *rptr;
};


struct node *createNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    return newnode;
}


struct node *createTree(struct node * root){
    int x;
    int hasleft,hasright;

    //left
    printf("    node %d has left(1-yes | 0-no) : ",root->info);
    scanf("%d",&hasleft);
    if(hasleft){
        printf("Enter node value : ");        
        scanf("%d",&x);
        root->lptr = createNode(x); 
        createTree(root->lptr);
    }
    else{
        root->lptr = NULL;
    }
    
    //right
    printf("    node %d has right(1-yes | 0-no) : ",root->info);
    scanf("%d",&hasright);
    if(hasright){
        printf("Enter node value : ");        
        scanf("%d",&x);
        root->rptr = createNode(x);
        createTree(root->rptr);
    }
    else{
        root->rptr = NULL;
    }

    return root;
}

struct node *preOrder(struct node *root){
    if(root == NULL){
        return root;
    }
    printf("%d ",root->info);
    preOrder(root->lptr);
    preOrder(root->rptr);
}

void main(){
    int n;
    printf("Enter root node : ");
    scanf("%d",&n);
    
    struct node *root = createNode(n);

    root = createTree(root);

    printf("\nPreorder : ");
    preOrder(root);
}

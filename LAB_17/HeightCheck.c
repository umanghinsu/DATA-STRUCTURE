#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//create
struct node *createNode(int);
//insert
struct node *createTree(struct node *);
struct node *insert(struct node *, int);

struct node{
    int info;   
    struct node *lptr;
    struct node *rptr;
};

//create node
struct node *createNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    return newnode;
}

//depth
int finddepth(struct node *root){

    if(root == NULL) return -1;

    int left = finddepth(root->lptr);
    int right = finddepth(root->rptr);
    return (left>right ? left : right)+1;
}

int balance(struct node *root){
    if(root == NULL) return 0;
    return finddepth(root->lptr) - finddepth(root->rptr);
}

//insert
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
        int totalbalance = balance(root);
        if(totalbalance > 1 || totalbalance < -1) return false;
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
        int totalbalance = balance(root);
        if(totalbalance > 1 || totalbalance < -1) return false;
        createTree(root->rptr);
    }
    else{
        root->rptr = NULL;
    }

    return root;
}

int main(){
    int n;
    printf("Enter root node : ");
    scanf("%d",&n);
    
    struct node *root = createNode(n);

    if(!createTree(root)) printf("FASLE");
    else printf("TURE");
    return 0;
}
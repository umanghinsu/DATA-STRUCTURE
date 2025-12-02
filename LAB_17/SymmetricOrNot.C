#include <stdio.h>
#include <stdlib.h>

//create
struct node *createNode(int);
//display
void inOrder(struct node *);
//insert
struct node *createTree(struct node *);
//search
int search(struct node *, struct node *);



struct node{
    int info;   
    struct node *lptr;
    struct node *rptr;
};

//display
void inOrder(struct node *save){
    if(save == NULL){
        return;
    }
    inOrder(save->lptr);
    printf("%d ",save->info);
    inOrder(save->rptr);
}

//create node
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


int search(struct node *save1, struct node *save2){

    if(save1 == NULL && save2 == NULL) return 1;
    if(save1 == NULL || save2 == NULL) return 0;

    if(save1->info != save2->info) return 0;

    int left = search(save1->lptr, save2->rptr);
    if(left == 0) return 0;
    int right = search(save1->rptr, save2->lptr);
    if(right == 0) return 0;
    
}

void main(){
    int n;
    //insert
    printf("Enter root node of tree : ");
    scanf("%d",&n);
    
    //create root node
    struct node *root = createNode(n);

    //creae BST
    root = createTree(root);

    //display
    printf("-------Inorder of tree : ");
    inOrder(root);
    
    //check
    if(search(root->lptr,root->rptr) == 1) printf("\nBoth the tree are symmetric");
    else printf("\nBoth the tree are not symmetric");
}
#include <stdio.h>
#include <stdlib.h>

//create
struct node *createNode(int);
//insert
struct node *createBST(struct node *);
struct node *insert(struct node *, int);

struct node *minValueNode(struct node *);
struct node *maxValueNode(struct node *);

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

//insert
struct node *createBST(struct node *root){
    int hasnew, nodeinfo;
    printf("    you want to insert node (1-yes | 0-no) : ");
    scanf("%d",&hasnew);
    while(hasnew){
        printf("        Enter node value : ");
        scanf("%d",&nodeinfo);
        root = insert(root,nodeinfo);
        
        printf("    you want to insert node (1-yes | 0-no) : ");
        scanf("%d",&hasnew);
    }
    return root;
}

struct node *insert(struct node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(root->info > data){
        root->lptr = insert(root->lptr,data);
    }
    else if(root->info < data){
        root->rptr = insert(root->rptr,data);
    }
    return root;
}

struct node *minValueNode(struct node *root){
    struct node* current = root;
    while (current && current->lptr != NULL)
        current = current->lptr;
    return current;
}

struct node *maxValueNode(struct node *root){
    struct node* current = root;
    while (current && current->rptr != NULL)
        current = current->rptr;
    return current;
}

void main(){
    int n;
    printf("Enter root node : ");
    scanf("%d",&n);
    
    struct node *root = createNode(n);

    root = createBST(root);

    printf("smallest value = %d\n",minValueNode(root)->info);
    printf("largest value = %d",maxValueNode(root)->info);
}
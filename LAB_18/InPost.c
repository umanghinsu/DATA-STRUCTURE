#include <stdio.h>
#include <stdlib.h>

struct node *constructTree(int [], int [],int *, int , int , int );
void preOrder(struct node *);

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};

void preOrder(struct node *save){
    if(save == NULL){
        return;
    }
    printf("%d ",save->info);
    preOrder(save->lptr);
    preOrder(save->rptr);
}

//create node
struct node *createNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    return newnode;
}

int findindex(int inorder[], int data, int l, int h){
    for(int i=l; i<=h; i++){
        if(inorder[i] == data) return i;
    }
    return -1;
}

struct node *constructTree(int inorder[], int postorder[],int *postindex, int size, int l, int h){
    if(*postindex <= 0 || l > h){
        return NULL;
    }
    struct node *root = createNode(postorder[h]);
    (*postindex)--;
    
    if(l == h || *postindex <= 0){
        return root;
    }

    int index = findindex(inorder,postorder[*postindex],l,h);

    if(index != -1){
        root->lptr = constructTree(inorder, postorder, postindex, size, l, index-1);
        root->rptr = constructTree(inorder, postorder, postindex, size, index+1, h);
    }

    preOrder(root);
}

void main(){

    int size;
    printf("Enter size : ");
    scanf("%d",&size);
    
    
    int postorder[size];
    int inorder[size];
    int postindex=size-1;

    printf("Enter InOrder : \n");
    for(int i=0; i<size; i++){
        printf("->");
        scanf("%d",&inorder[i]);
    }
    
    printf("Enter PostOrder : \n");
    for(int i=0; i<size; i++){
        printf("->");
        scanf("%d",&postorder[i]);
    }

    constructTree(inorder,postorder,&postindex,size,0,size-1);
}
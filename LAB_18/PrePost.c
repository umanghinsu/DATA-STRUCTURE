#include <stdio.h>
#include <stdlib.h>

struct node *constructTree(int [], int [],int *, int , int , int );
void inOrder(struct node *);

struct node{
    int info;
    struct node *lptr;
    struct node *rptr;
};

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

int findindex(int postorder[], int data, int l, int h){
    for(int i=l; i<=h; i++){
        if(postorder[i] == data) return i;
    }
    return -1;
}

struct node *constructTree(int preorder[], int postorder[],int *preindex, int size, int l, int h){
    if(*preindex >= size || l > h){
        return NULL;
    }
    struct node *root = createNode(preorder[*preindex]);
    (*preindex)++;
    
    if(l == h || *preindex >= size){
        return root;
    }

    int index = findindex(postorder,preorder[*preindex],l,h);

    if(index != -1){
        root->lptr = constructTree(preorder, postorder, preindex, size, l, index);
        root->rptr = constructTree(preorder, postorder, preindex, size, index+1, h);
    }

    inOrder(root);
}

void main(){

    int size;
    printf("Enter size : ");
    scanf("%d",&size);
    
    
    int postorder[size];
    int preorder[size];
    int preindex=0;

    printf("Enter preorder : \n");
    for(int i=0; i<size; i++){
        printf("->");
        scanf("%d",&preorder[i]);
    }
    
    printf("Enter PostOrder : \n");
    for(int i=0; i<size; i++){
        printf("->");
        scanf("%d",&postorder[i]);
    }

    constructTree(preorder,postorder,&preindex,size,0,size-1);
}
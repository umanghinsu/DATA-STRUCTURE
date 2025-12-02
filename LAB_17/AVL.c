#include <stdio.h>
#include <stdlib.h>

//create
struct node *createNode(int);
//display
void inOrder(struct node *);
void preOrder(struct node *);
//insert
struct node *createBST(struct node *);
struct node *insert(struct node *, int);
//delete
struct node *deleteNode(struct node *);
struct node *deleteFinal(struct node *, int);
struct node *minValueNode(struct node *);
//depth
int finddepth(struct node *);
//check height balanced or not
int balance(struct node *);
//rotation
struct node *rightRotation(struct node *);
struct node *leftRotation(struct node *);


struct node{
    int info;   
    struct node *lptr;
    struct node *rptr;
};

//display
void inOrder(struct node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->lptr);
    printf("%d ",root->info);
    inOrder(root->rptr);
}

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
    
    int totalbalance = balance(root);

    //right rotation - left heavy
    if(totalbalance > 1 && data < root->lptr->info){
        return rightRotation(root);
    }
    //left rotation - right heavy
    if(totalbalance < -1 && data > root->rptr->info){
        return leftRotation(root);
    }
    //left right rotation
    if(totalbalance > 1 && data > root->lptr->info){
        root->lptr = leftRotation(root->lptr);
        return rightRotation(root);
    }
    //right left rotation
    if(totalbalance < -1 && data < root->rptr->info){
        root->rptr = rightRotation(root->rptr);
        return leftRotation(root);
    }

    return root;
}

//rotation
struct node *rightRotation(struct node *root){
    if(root == NULL || root->lptr == NULL)    return root;
    struct node *temp = root->lptr;
    root->lptr = temp->rptr;
    temp->rptr = root;
    return temp;
}

struct node *leftRotation(struct node *root){
    if(root == NULL || root->rptr == NULL)    return root;
    struct node *temp = root->rptr;
    root->rptr = temp->lptr;
    temp->lptr = root;
    return temp;
}

//delete
struct node *deleteNode(struct node *root){
    int hasnew, nodeinfo;
    printf("\n    you want to delete node (1-yes | 0-no) : ");
    scanf("%d",&hasnew);
    while(hasnew){
        printf("        Enter node value : ");
        scanf("%d",&nodeinfo);
        root = deleteFinal(root,nodeinfo);

        printf("\n    you want to delete node (1-yes | 0-no) : ");
        scanf("%d",&hasnew);
    }

    return root;
}

struct node *minValueNode(struct node *node){
    struct node* current = node;
    while (current && current->lptr != NULL)
        current = current->lptr;
    return current;
}

struct node *deleteFinal(struct node *root,int data){
    if (root == NULL)
        return root;

    // Traverse to the node to be deleted
    if (root->info > data){
        root->lptr = deleteFinal(root->lptr, data);
    }
    else if (root->info < data){
        root->rptr = deleteFinal(root->rptr, data);
    }
    else {
        // Node found

        // Case 1: Node with only one child or no child
        if (root->lptr == NULL) {
            struct node* temp = root->rptr;
            free(root);
            return temp;
        }
        else if (root->rptr == NULL) {
            struct node* temp = root->lptr;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct node *temp = minValueNode(root->rptr);
        root->info = temp->info;
        root->rptr = deleteFinal(root->rptr, temp->info);
    }

    int totalbalance = balance(root);

    //right - left heaavy
    if(totalbalance > 1 && data < root->lptr->info){
        return rightRotation(root);
    }
    //left - right heavy
    if(totalbalance < -1 && data > root->rptr->info){
        return leftRotation(root);
    }
    //left right
    if(totalbalance > 1 && data > root->lptr->info){
        root->lptr = leftRotation(root->lptr);
        return rightRotation(root);
    }
    //right left
    if(totalbalance < -1 && data < root->rptr->info){
        root->rptr = rightRotation(root->rptr);
        return leftRotation(root);
    }

    return root;
}

int main(){
    int n;
    //insert
    printf("Enter root node of tree : ");
    scanf("%d",&n);
    
    //create root node
    struct node *root = createNode(n);

    while(1){
        printf("\n  1->insetr\n");
        printf("  2->delete\n");
        printf("  3->inorder\n");
        printf("  0->exit\n");
        printf("Enter 0-6 : ");
        scanf("%d",&n);

        switch(n){
            
            //insert
            case 1: root = createBST(root); break;
            //delete
            case 2: root = deleteNode(root); break;
            //display
            case 3: printf("\nInorder : "); inOrder(root); break;
            //exit
            case 0: exit(0);
        }
    }
    return 0;
}
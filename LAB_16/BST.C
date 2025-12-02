#include <stdio.h>
#include <stdlib.h>

//create
struct node *createNode(int);
//display
void inOrder(struct node *);
void preOrder(struct node *);
void postOrder(struct node *);
//insert
struct node *createBST(struct node *);
struct node *insert(struct node *, int);
//delete
struct node *deleteNode(struct node *);
struct node *deleteFinal(struct node *, int);
struct node *minValueNode(struct node *);
//search
void searchNode(struct node *);
struct node *search(struct node *, int);



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

//display
void inOrder(struct node *save){
    if(save == NULL){
        return;
    }
    inOrder(save->lptr);
    printf("%d ",save->info);
    inOrder(save->rptr);
}

void preOrder(struct node *save){
    if(save == NULL){
        return;
    }
    printf("%d ",save->info);
    preOrder(save->lptr);
    preOrder(save->rptr);
}

void postOrder(struct node *save){
    if(save == NULL){
        return;
    }
    postOrder(save->lptr);
    postOrder(save->rptr);
    printf("%d ",save->info);
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

//delete
struct node *deleteNode(struct node *save){
    int hasnew, nodeinfo;
    printf("\n    you want to delete node (1-yes | 0-no) : ");
    scanf("%d",&hasnew);
    while(hasnew){
        printf("        Enter node value : ");
        scanf("%d",&nodeinfo);
        save = deleteFinal(save,nodeinfo);

        printf("\n    you want to delete node (1-yes | 0-no) : ");
        scanf("%d",&hasnew);
    }

    return save;
}

struct node *minValueNode(struct node *node){
    struct node* current = node;
    while (current && current->lptr != NULL)
        current = current->lptr;
    return current;
}

struct node *deleteFinal(struct node *save,int data){
    if (save == NULL)
        return save;

    // Traverse to the node to be deleted
    if (save->info > data){
        save->lptr = deleteFinal(save->lptr, data);
    }
    else if (save->info < data){
        save->rptr = deleteFinal(save->rptr, data);
    }
    else {
        // Node found

        // Case 1: Node with only one child or no child
        if (save->lptr == NULL) {
            struct node* temp = save->rptr;
            free(save);
            return temp;
        }
        else if (save->rptr == NULL) {
            struct node* temp = save->lptr;
            free(save);
            return temp;
        }

        // Case 2: Node with two children
        struct node *temp = minValueNode(save->rptr);
        save->info = temp->info;
        save->rptr = deleteFinal(save->rptr, temp->info);
    }


    return save;
}

//search
void searchNode(struct node *root){
     int hasnew, nodeinfo;
    printf("\n    you want to search node (1-yes | 0-no) : ");
    scanf("%d",&hasnew);
    while(hasnew){
        printf("        Enter node value : ");
        scanf("%d",&nodeinfo);
        struct node *result = search(root,nodeinfo);

        if(result == NULL){
            printf("-->node not avilable in tree<--");
        }
        else{
            printf("-->node is avilable : %d",result->info);
        }

        printf("\n    you want to search node (1-yes | 0-no) : ");
        scanf("%d",&hasnew);
    }
}

struct node *search(struct node *save,int data){
    if(save == NULL){
        return NULL;
    }
    if(save->info == data){
        return save;
    }
    if(save->info >= data){
        return search(save->lptr,data);
    }
    else{
        return search(save->rptr,data);
    }
}

int main(){

    int n;
    //insert root node
    printf("Enter root node : ");
    scanf("%d",&n);
    
    //create root node
    struct node *root = createNode(n);

    while(1){
        printf("\n  1->insetr\n");
        printf("  2->delete\n");
        printf("  3->search\n");
        printf("  4->preorder\n");
        printf("  5->postorder\n");
        printf("  6->inorder\n");
        printf("  0->exit\n");
        printf("Enter 0-6 : ");
        scanf("%d",&n);

        switch(n){
            
            //insert
            case 1: root = createBST(root); break;
            //delete
            case 2: root = deleteNode(root); break;
            //search
            case 3: searchNode(root); break;
            //preorder
            case 4: printf("\nPreorder : "); preOrder(root); break;
            //postorder
            case 5: printf("\nPostorder : "); postOrder(root); break; 
            //inorder
            case 6: printf("\nInorder : "); inOrder(root); break;
            //exit
            case 0: exit(0);
        }
    }
    return 0;
}
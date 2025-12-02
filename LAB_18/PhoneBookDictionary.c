#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create
struct node *createNode(char [], char []);
//display
void ascending(struct node *);
void descending(struct node *);
//insert
struct node *createBST(struct node *);
struct node *insert(struct node *, char [], char []);
//delete
struct node *deleteNode(struct node *);
struct node *minValueNode(struct node *);
struct node *deleteFinal(struct node *, char []);
//search
void searchNode(struct node *);
struct node *search(struct node *, char []);



struct node{
    char name[50];
    char number[11];   
    struct node *lptr;
    struct node *rptr;
};

//create node
struct node *createNode(char name[], char number[]){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    strcpy(newnode->number, number);
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    return newnode;
}

//display
void ascending(struct node *save){
    if(save == NULL){
        return;
    }
    ascending(save->lptr);
    printf("        %s        %s\n",save->name,save->number);
    ascending(save->rptr);
}

void descending(struct node *save){
    if(save == NULL){
        return;
    }
    ascending(save->rptr);
    printf("        %s        %s\n",save->name,save->number);
    ascending(save->lptr);
}

//insert
struct node *createBST(struct node *root){
    int hasnew=1;
    char name[50],number[11];
    
    printf("        Enter name : ");
    scanf("%49s",name);
    printf("        Enter Mobile No. : ");
    scanf("%10s",number);
    root = insert(root,name,number);
    return root;
}

struct node *insert(struct node *root, char name[], char number[]){
    if(root == NULL){
        return createNode(name,number);
    }
    if(strcmp(root->name, name) > 0){
        root->lptr = insert(root->lptr,name,number);
    }
    else if(strcmp(root->name, name) < 0){
        root->rptr = insert(root->rptr,name,number);
    }
    return root;
}

//delete
struct node *deleteNode(struct node *save){
    char name[50];
    
    printf("        Enter name : ");
    scanf("%49s",name);
    save = deleteFinal(save,name);
    return save;
}

struct node *minValueNode(struct node *node){
    struct node* current = node;
    while (current && current->lptr != NULL)
        current = current->lptr;
    return current;
}

struct node *deleteFinal(struct node *save, char name[]){
    if (save == NULL)
        return save;

    // Traverse to the node to be deleted
    if(strcmp(save->name, name) > 0){
        save->lptr = deleteFinal(save->lptr, name);
    }
    else if(strcmp(save->name, name) < 0){
        save->rptr = deleteFinal(save->rptr, name);
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
        strcpy(save->name,temp->name);
        save->rptr = deleteFinal(save->rptr, temp->name);
    }
    return save;
}

//search
void searchNode(struct node *root){
    char name[50];
    printf("        Enter name : ");
    scanf("%49s",name);
    struct node *result = search(root,name);

    if(result == NULL){
        printf("-->Contect not avilable in dictionary<--");
    }
    else{
        printf("    %s    %s\n",result->name,result->number);
    }
}

struct node *search(struct node *save, char name[]){
    if(save == NULL)    return NULL;
    if(strcmp(save->name,name) == 0)    return save;
    if(strcmp(save->name,name) > 0)     return search(save->lptr,name);
    return search(save->rptr,name);
}

int main(){

    int n;
    struct node *root = NULL;

    while(1){
        printf("\n  1->insetr\n");
        printf("  2->delete\n");
        printf("  3->search\n");
        printf("  4->ascending\n");
        printf("  5->descending\n");
        printf("  0->exit\n");
        printf("Enter 0-6 : ");
        scanf("%d",&n);

        switch(n){
            
            //insert
            case 1: root = createBST(root); break;
            //delete
            case 2: root = deleteNode(root); break;
            // //search
            case 3: searchNode(root); break;
            //assending
            case 4: printf("\nascending : \n"); ascending(root); break;
            //dssending
            case 5: printf("\ndescending : \n"); descending(root); break; 
            //exit
            case 0: exit(0);
        }
    }
    return 0;
}
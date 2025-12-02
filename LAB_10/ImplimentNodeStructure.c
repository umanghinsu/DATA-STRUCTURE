#include <stdio.h>
#include <stdlib.h>


void inseartAtFirst(int x);

struct node{
    int info;
    struct node *link;
};

struct node * first = NULL;

void main(){
    int a;
    scanf("%d",&a);
    inseartAtFirst(a);
}

void inseartAtFirst(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof (struct node));
        newnode->link = first;
        newnode->info = x;
        first = newnode;
    printf("node value = %d",first->info);
}
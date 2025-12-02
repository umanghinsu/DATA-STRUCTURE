#include <stdio.h>
#include <stdlib.h>

struct student{
    int roll_no;
    char name[20];
    char branch[10];
    int branch_no;
};

void main(){
    int size;
    printf("enter number of total student = ");
    scanf("%d",&size);
    struct student *s[size];

    for(int i=0; i<size; i++){
        s[i] = (struct student *)malloc(sizeof(struct student));

        printf("enter rollno - ");
        scanf("%d",&s[i]->roll_no);

        printf("enter name - ");
        scanf(" %[^\n]s",s[i]->name);

        printf("enter branch - ");
        scanf(" %[^\n]s",s[i]->branch);

        printf("enter branch_no - ");
        scanf("%d",&s[i]->branch_no);
    }

    for(int i=0; i<size; i++){
        printf("\nroll_no - %d\nname - %s\nbranch - %s\nbranch_no- %d",s[i]->roll_no,s[i]->name,s[i]->branch,s[i]->branch_no);
    }

    for(int i=0; i<size; i++){
        free(s[i]);
    }
}
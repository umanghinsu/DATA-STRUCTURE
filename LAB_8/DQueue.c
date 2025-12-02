#include <stdio.h>
#include <stdlib.h>

void enQueue(int[], int *, int *, int);
void deQueue(int[], int *, int *);
void display(int[], int, int);
void insertAtFirst(int[], int *, int *);
void deleteAtLast(int[], int *, int *);

void enQueue(int queue[], int *F, int *R, int size)
{
    if (*F == -1 && *R == -1)
    {
        *F = 0;
    }
    if (*R >= size - 1)
    {
        printf("Queue is over flow");
        return;
    }

    printf("Enter Number for Enqueue : ");
    scanf("%d", &queue[++(*R)]);
}

void deQueue(int queue[], int *F, int *R)
{
    if (*F == -1)
    {
        printf("Queue is under flow");
        return;
    }

    if (*F == *R)
    {
        *F = -1;
        *R = -1;
    }
    else
    {
        (*F)++;
    }
    return;
}

void insertAtFirst(int queue[], int *F, int *R)
{
    if (*F == 0)
    {
        printf("queue is underflow");
        return;
    }
    printf("Enter Number for Enqueue : ");
    scanf("%d", &queue[--(*F)]);
}

void deleteAtLast(int queue[], int *F, int *R)
{
    if (*R == -1)
    {
        printf("Queue is under flow");
        return;
    }

    if (*F == *R)
    {
        *F = -1;
        *R = -1;
    }
    else
    {
        (*R)--;
    }
    return;
}

void display(int queue[], int F, int R)
{
    if (F == -1 && F == R)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = F; i <= R; i++)
    {
        printf("%d ", queue[i]);
    }
}

void main()
{
    int size;
    printf("Enter Size of Queue : ");
    scanf("%d", &size);

    int F = -1;
    int R = -1;
    int queue[size];

    int n, num;
    while (1)
    {
        printf("\n1   insert at last\n");
        printf("2   delete at first\n");
        printf("3   insert at first\n");
        printf("4   delete at last\n");
        printf("5   Display\n");
        printf("0   exit\n");
        printf("Enter number : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            enQueue(queue, &F, &R, size);
            break;

        case 2:
            deQueue(queue, &F, &R);
            break;

        case 3:
            insertAtFirst(queue, &F, &R);
            break;

        case 4:
            deleteAtLast(queue, &F, &R);
            break;

        case 5:
            display(queue, F, R);
            break;

        case 0:
            exit(0);
        }
    }
}
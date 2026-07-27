#include "stdio.h"
#include "stdlib.h"

struct queue
{
    int info;
    struct queue *link;
};

struct queue *left = NULL;
struct queue *right = NULL;

void enqueue(int x);
int dequeue();
void display();

int main()
{

    int choice;
    int x;

    while (1)
    {
        printf("\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;

        case 1:
            printf("\nEnter Value: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            printf("\nDequeued Value = %d\n", dequeue());
            break;

        case 3:
            display();
            break;

        default:
            printf("\nInvalid Choice...!\n");
        }
    }

    return 0;
}

void enqueue(int x)
{
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    new->info = x;
    new->link = NULL;

    if (left == NULL && right == NULL)
    {
        left = right = new;
    }
    else
    {
        right->link = new;
        right = new;
    }
}

int dequeue()
{
    if (left == NULL && right == NULL)
    {
        printf("\nEmpty Queue...!\n");
        return -1;
    }
    else if (left == right)
    {
        int temp = left->info;
        free(left);
        left = right = NULL;
        return temp;
    }
    else
    {
        int temp = left->info;
        struct queue *save = left;
        left = left->link;
        free(save);
        return temp;
    }
}

void display()
{
    if (left == NULL && right == NULL)
    {
        printf("\nEmpty Queue...!\n");
    }
    else
    {
        struct queue *save = left;

        printf("\n[");
        while (save != NULL)
        {
            printf("%d, ", save->info);
            save = save->link;
        }
        printf("\b\b]\n");
    }
}
#include "stdio.h"
#include "stdlib.h"

struct PriorityQueue
{
    int info;
    int priority;
    struct PriorityQueue *link;
};

struct PriorityQueue *front = NULL;
struct PriorityQueue *rear = NULL;

void enqueue(int x, int p);
int dequeue();
void display();

int main()
{
    int choice;
    int x;
    int p;
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
            printf("\nEnter Priority: ");
            scanf("%d", &p);
            enqueue(x, p);
            break;

        case 2:
            printf("\nDequeued Value: %d\n", dequeue());
            break;

        case 3:
            display();
            break;

        default:
            printf("\nInvalid Choice...!\n");
            break;
        }
    }
}

void enqueue(int x, int p)
{
    struct PriorityQueue *new = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    new->info = x;
    new->priority = p;

    if (rear == NULL)
    {
        front = new;
        rear = new;
        new->link = NULL;
    }
    else
    {
        struct PriorityQueue *save = front;
        struct PriorityQueue *pred = front;
        while (save != NULL && save->priority >= new->priority)
        {
            pred = save;
            save = save->link;
        }
        if (save == NULL)
        {
            pred->link = new;
            new->link = NULL;
        }
        else
        {
            pred->link = new;
            new->link = save;
        }
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue Overflow...!\n");
        return -1;
    }

    int t = front->info;
    struct PriorityQueue *save = front;

    if (front->link == NULL)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->link;
    }

    free(save);
    return t;
}

void display()
{
    if (front == NULL)
    {
        printf("\nEmpty Queue...!\n");
        return;
    }

    struct PriorityQueue *save = front;
    printf("\n[");
    while (save != NULL)
    {
        printf("{%d,%d}, ", save->info, save->priority);
        save = save->link;
    }
    printf("\b\b]\n");
}
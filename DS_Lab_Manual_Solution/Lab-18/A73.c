#include "stdio.h"
#include "stdlib.h"

int left = -1;
int right = -1;
int *queue;
int size;

void enqueueFront(int x);
void enqueueEnd(int x);
int dequeueFront();
int dequeueEnd();
void display();

int main()
{
    printf("Enter Size: ");
    scanf("%d", &size);

    queue = (int *)malloc(sizeof(int) * size);

    int choice;
    int x;

    while (1)
    {
        printf("\n0.Exit\n1.Enqueue_Front\n2.Enqueue_End\n3.Dequeue_Front\n4.Dequeue_End\n5.Display\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            free(queue);
            return 0;

        case 1:
            printf("\nEnter Value: ");
            scanf("%d", &x);
            enqueueFront(x);
            break;

        case 2:
            printf("\nEnter Value: ");
            scanf("%d", &x);
            enqueueEnd(x);
            break;

        case 3:
            printf("\nDequeued value from front: %d\n", dequeueFront());
            break;

        case 4:
            printf("\nDequeued value from front: %d\n", dequeueEnd());
            break;

        case 5:
            display();
            break;

        default:
            printf("\nInvalid Choice...!\n");
        }
    }
}

void enqueueFront(int x)
{
    if (left == -1 && right == -1)
    {
        left = 0;
        right = 0;
        queue[0] = x;
    }
    else if (right >= size - 1)
    {
        printf("\nQueue Overflow From Front...!\n");
    }
    else
    {
        queue[++right] = x;
    }
}

void enqueueEnd(int x)
{
    if (left <= -1)
    {
        printf("\nQueue Overflow From End...!\n");
    }
    else
    {
        queue[--left] = x;
    }
}
int dequeueFront()
{
    if (left == -1 && right == -1)
    {
        printf("\nQueue underflow...!\n");
        return -1;
    }
    else if (left == right)
    {
        int t = left;
        left = -1;
        right = -1;
        return queue[t];
    }
    else
    {
        return queue[right--];
    }
}

int dequeueEnd()
{
    if (left == -1 && right == -1)
    {
        printf("\nQueue underflow...!\n");
        return -1;
    }
    else if (left == right)
    {
        int t = left;
        left = -1;
        right = -1;
        return queue[t];
    }
    else
    {
        return queue[left++];
    }
}

void display()
{
    if (left == -1 && right == -1)
    {
        printf("\nEmpty Queue...!\n");
    }
    else
    {
        printf("\n[");
        for (int i = left; i <= right; i++)
        {
            printf("%d, ", queue[i]);
        }
        printf("\b\b]\n");
    }
}
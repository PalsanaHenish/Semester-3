#include "stdio.h"
#include "stdlib.h"

int left = -1;
int right = -1;
int *queue;
int size;

void ENQUEUE(int x);

int DEQUEUE();

void DISPLAY();

int main()
{
    printf("Enter Size: ");
    scanf("%d", &size);

    queue = (int *)malloc(sizeof(int) * size);

    int choice;
    int x;

    while (1)
    {
        printf("\n0.Exit\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nEnter Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 0:
            free(queue);
            return 0;
        
        case 1:
            printf("\nEnter value: ");
            scanf("%d",&x);
            ENQUEUE(x);
            break;

        case 2:
            printf("\nDequeued value: %d\n",DEQUEUE());
            break;

        case 3:
            DISPLAY();
            break;

        default:
            printf("\nInvalid Input...!\n");
            break;
        }
    }
    

    return 0;
}

void ENQUEUE(int x)
{
    if (right >= size - 1)
    {
        printf("\nQueue Overflow...!\n");
        return;
    }
    else
    {
        queue[++right] = x;
        if (left == -1)
        {
            left = 0;
        }
    }
}

int DEQUEUE()
{
    if (left <= -1)
    {
        printf("\nQueue underflow...!\n");
        return -1;
    }

    else
    {
        if (left == right)
        {
            int temp = left;
            left = right = -1;
            return queue[temp];
        }

        return queue[left++];
    }
}

void DISPLAY()
{
    if (left <= -1)
    {
        printf("\nEmpty Queue...!\n");
        return;
    }
    else
    {
        printf("\n[");
        for(int i=left; i <= right; i++){
            printf("%d, ",queue[i]);
        }
        printf("\b\b]\n");
    }
}
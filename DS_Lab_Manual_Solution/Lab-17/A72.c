#include "stdio.h"
#include "stdlib.h"

int left = -1;
int right = -1;
int *queue;
int size;

void insert(int x);
int delete();
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
        printf("\n0.Exit\n1.Insert\n2.Delete\n3.Display\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            free(queue);
            return 0;

        case 1:
            printf("\nEnter value: ");
            scanf("%d", &x);
            insert(x);
            break;

        case 2:
            printf("\nDequeued value: %d\n", delete());
            break;

        case 3:
            display();
            break;

        default:
            printf("\nInvalid Input...!\n");
            break;
        }
    }
    return 0;
}

void insert(int x)
{
    if ((right + 1) % size == left)
    {
        printf("\nQueue Overflow...!\n");
        return;
    }

    right = (right + 1) % size;

    queue[right] = x;

    if (left == -1)
    {
        left = 0;
    }
}

int delete()
{
    if (left == right && left == -1 && right == -1)
    {
        printf("\nQueue Underflow...!\n");
        return -1;
    }

    if (left == right)
    {
        int temp = queue[left];
        left = -1;
        right = -1;
        return temp;
    }
    else if (left == size - 1)
    {
        left = 0;
        return queue[left];
    }
    else
    {
        return queue[left++];
    }
}

void display()
{
    if (left == right && left == -1 && right == -1)
    {
        printf("\nEmpty Queue...!\n");
        return;
    }

    printf("\n[");
    for (int i = left; i != right; i++)
    {
        printf("%d, ", queue[i]);
        if (i == size - 1)
        {
            i = -1;
        }
    }
    printf("%d]\n",queue[right]);
}
// 57.	Write a menu driven program to implement following operations on the Stack using an Array
// •	PUSH, POP, DISPLAY
// •	PEEP, CHANGE

#include "stdio.h"
#include "stdlib.h"

int top = -1;
int *stack;
int size;

void PUSH(int x);

int POP();

void DISPLAY();

int PEEP(int i);

void CHANGE(int x, int i);

int main()
{
    printf("Enter size: ");
    scanf("%d", &size);

    stack = (int *)malloc(sizeof(int) * size);

    int choice;
    int x;
    int i;

    while (1)
    {
        printf("\n0. Exit\n1. PUSH\n2. POP\n3. DISPLAY\n4. PEEP\n5. CHANGE\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;

        case 1:
            printf("\nEnter x: ");
            scanf("%d", &x);
            PUSH(x);
            break;

        case 2:
            printf("\nPoped value : %d\n", POP());
            break;

        case 3:
            DISPLAY();
            break;

        case 4:
            printf("\nEnter index: ");
            scanf("%d", &i);
            printf("\nValue at index %d : %d\n", i, PEEP(i));
            break;

        case 5:
            printf("\nEnter Value and Index: ");
            scanf("%d %d", &x, &i);
            CHANGE(x, i);
            break;

        default:
            printf("\nInvalid...!\n");
        }
    }

    return 0;
}

void PUSH(int x)
{
    if (top >= size - 1)
        printf("\nStack Overflow!\n");

    else
        stack[++top] = x;
}

int POP()
{
    if (top <= -1)
    {
        printf("\nStack Underflow!\n");
        return -1;
    }
    else
        return stack[top--];
}

void DISPLAY()
{
    if (top < 0)
        printf("\nEmpty Stack!\n");

    else
    {
        printf("\nStack: [");
        for (int i = 0; i <= top; i++)
        {
            printf("%d, ", stack[i]);
        }
        printf("\b\b]\n");
    }
}

int PEEP(int i)
{
    if (i < 0 || i > top)
    {
        printf("\nInvalid...!\n");
        return -1;
    }

    return stack[top - i];
}

void CHANGE(int x, int i)
{
    if (i < 0 || i > top)
    {
        printf("\nInvalid...!\n");
        return;
    }

    stack[i] = x;
}
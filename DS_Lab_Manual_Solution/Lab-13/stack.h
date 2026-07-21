#include "stdio.h"
#include "stdlib.h"

void PUSH(int x, int &stack, int top)
{
    if (top >= size - 1)
        printf("\nStack Overflow!\n");

    else
        stack[++top] = x;
}

int POP(int &stack, int top)
{
    if (top <= -1)
    {
        printf("\nStack Underflow!\n");
        return -1;
    }
    else
        return stack[top--];
}

void DISPLAY(int &stack, int top)
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

int PEEP(int i, int &stack, int top)
{
    if (i < 0 || i > top)
    {
        printf("\nInvalid...!\n");
        return -1;
    }

    return stack[top - i];
}

void CHANGE(int x, int i, int &stack, int top)
{
    if (i < 0 || i > top)
    {
        printf("\nInvalid...!\n");
        return;
    }

    stack[i] = x;
}
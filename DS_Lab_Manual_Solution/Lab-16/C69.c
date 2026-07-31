#include "stdio.h"

int top = -1;
int stack[2];

void sortableUsingStack(int A[], int n);

void PUSH(int x);

int POP();

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int A[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Element: ");
        scanf("%d",&A[i]);
    }

    sortableUsingStack(A, n);

    return 0;
}

void sortableUsingStack(int A[], int n)
{
    int B[n];

    for (int i = 0, j = 0; i < n - 1;)
    {
        if (A[i] < A[i + 1])
        {
            PUSH(A[i++]);
            B[j++] = POP();
        }
        else
        {
            PUSH(A[i++]);
            PUSH(A[i++]);
            B[j++] = POP();
            B[j++] = POP();
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", B[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (B[i] > B[i + 1])
        {
            printf("\nCan't be Sorted Using Stack...!");
            return;
        }
    }

    printf("\nSortable Using Stack...('-')");
}

void PUSH(int x)
{
    if (top >= 2 - 1)
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
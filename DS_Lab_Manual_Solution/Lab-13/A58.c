#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int info;
    struct stack *link;
};

struct stack *first = NULL;

void PUSH(int);

int POP();

int main()
{
    int choice;
    int x;

    while (1)
    {
        printf("\n0.Exit\n1.PUSH\n2.POP\nEnter Choice : ");
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
            printf("\nPoped Value : %d\n", POP());
            break;

        default:
            printf("\nInvalid...\n");
            break;
        }
    }
}

void PUSH(int x)
{
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    new->info = x;
    new->link = NULL;

    if (first == NULL)
        first = new;

    else
    {
        struct stack *save = first;

        while (save->link != NULL)
            save = save->link;

        save->link = new;
    }
}

int POP()
{
    if (first == NULL)
    {
        printf("\nStack Underflow!!!");
        return -1;
    }

    struct stack *pred = NULL;
    struct stack *save = first;
    int temp;

    while (save->link != NULL)
    {
        pred = save;
        save = save->link;
    }
    if (save == first)
    {
        first = NULL;
    }
    else
    {
        pred->link = NULL;
    }

    temp = save->info;
    free(save);
    return temp;
}
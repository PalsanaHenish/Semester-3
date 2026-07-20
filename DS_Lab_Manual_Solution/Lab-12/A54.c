#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *dbl_ins_fir(int x, struct node *first);

struct node *dbl_delete(int x, struct node *first);

struct node *dbl_ins_end(int x, struct node *first);

void dbl_display(struct node *first);

int main()
{
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    struct node *first = NULL;

    for (int i = 0; i < n; i++)
    {
        first = dbl_ins_fir(i, first);
    }

    dbl_display(first);

    for (int i = 0; i < n; i++)
    {
        first = dbl_ins_end(i, first);
    }

    dbl_display(first);

    while (1)
    {
        printf("Enter Info to be deleted or -1: ");
        scanf("%d", &n);
        if (n == -1)
            return 0;

        first = dbl_delete(n, first);

        dbl_display(first);
    }

    return 0;
}

struct node *dbl_ins_fir(int x, struct node *first)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->lptr = NULL;

    if (first == NULL)
    {
        first = new;
        new->rptr = NULL;
    }
    else
    {
        new->rptr = first;
        first->lptr = new;
        first = new;
    }

    return first;
}

struct node *dbl_delete(int x, struct node *first)
{
    if (first == NULL)
        return NULL;

    else if (first->rptr == NULL && first->info == x)
    {
        free(first);
        return NULL;
    }

    else
    {
        struct node *save = first;

        while (save->info != x && save != NULL)
            save = save->rptr;

        if (save == NULL)
            printf("\n404!\n");
        else
        {
            if (save == first)
            {
                first = first->rptr;
                free(first->lptr);
                first->lptr = NULL;
            }

            else if (save->rptr == NULL)
            {
                save->lptr->rptr = NULL;
                free(save);
            }

            else
            {
                save->lptr->rptr = save->rptr;
                save->rptr->lptr = save->lptr;
                free(save);
            }
        }
    }

    return first;
}

struct node *dbl_ins_end(int x, struct node *first)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->rptr = NULL;

    if (first == NULL)
    {
        first = new;
        new->lptr = NULL;
    }
    else
    {
        struct node *save = first;

        while (save->rptr != NULL)
            save = save->rptr;

        save->rptr = new;
        new->lptr = save;
    }

    return first;
}

void dbl_display(struct node *first)
{
    if (first == NULL)
        printf("\nEmpty List!\n");

    else
    {
        struct node *save = first;

        printf("\nDoubly Linked List: [");
        while (save != NULL)
        {
            printf("%d,", save->info);
            save = save->rptr;
        }
        printf("\b]\n");
    }
}
#include "stdio.h"
#include "stdlib.h"

struct node
{
    int coe;
    int exp;
    struct node *link;
};

struct node *first_1 = NULL, *first_2 = NULL, *last_1 = NULL, *last_2 = NULL;
struct node *first_sum = NULL;
struct node *last_sum = NULL;

void add_poly(int min);

int main()
{
    int m, n;
    printf("Enter no. of terms of 1st polynomial: ");
    scanf("%d", &m);
    printf("Enter no. of terms of 2st polynomial: ");
    scanf("%d", &n);

    printf("For 1st Polynomial: \n");
    for (int i = 0; i < m; i++)
    {
        int coe, exp;
        printf("Enter Coefficient and Exponent: ");
        scanf("%d %d", &coe, &exp);
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->coe = coe;
        new->exp = exp;
        if (first_1 == NULL)
        {
            first_1 = new;
            last_1 = new;
            last_1->link = first_1;
        }
        else
        {
            last_1->link = new;
            last_1 = new;
            last_1->link = first_1;
        }
    }

    printf("For 2st Polynomial: \n");
    for (int i = 0; i < n; i++)
    {
        int coe, exp;
        printf("Enter Coefficient and Exponent: ");
        scanf("%d %d", &coe, &exp);
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->coe = coe;
        new->exp = exp;
        if (first_2 == NULL)
        {
            first_2 = new;
            last_2 = new;
            last_2->link = first_2;
        }
        else
        {
            last_2->link = new;
            last_2 = new;
            last_2->link = first_2;
        }
    }

    add_poly((m<n)?m:n);

    struct node *save = first_sum;

    printf("Result : ");
    do
    {
        printf("%dx^%d + ", save->coe, save->exp);
        save = save->link;
    } while (save != last_sum);
    printf("%dx^%d", last_sum->coe, last_sum->exp);


    return 0;
}

void add_poly(int min)
{
    if (first_1 == NULL && first_2 == NULL)
        return;
    else if (first_1 == NULL && first_2 != NULL)
    {
        first_sum = first_2;
        return;
    }
    else if (first_1 != NULL && first_2 == NULL)
    {
        first_sum = first_1;
        return;
    }

    struct node *s1 = first_1, *s2 = first_2;

    for (int i=0; i<min; i++)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));

        if (s1->exp == s2->exp)
        {
            new->coe = s1->coe + s2->coe;
            new->exp = s1->exp;
            s1 = s1->link;
            s2 = s2->link;
        }
        else if (s1->exp > s2->exp)
        {
            new->coe = s1->coe;
            new->exp = s1->exp;
            s1 = s1->link;
        }
        else if (s2->exp > s1->exp)
        {
            new->coe = s2->coe;
            new->exp = s2->exp;
            s2 = s2->link;
        }

        if (first_sum == NULL)
        {
            first_sum = new;
            last_sum = new;
            last_sum->link = first_sum;
        }
        else
        {
            last_sum->link = new;
            last_sum = new;
            last_sum->link = first_sum;
        }

    }


    if (s1 != first_1)
    {
        do
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->coe = s1->coe;
            new->exp = s1->exp;
            s1 = s1->link;
            last_sum->link = new;
            last_sum = new;
            last_sum->link = first_sum;
        } while (s1 != first_1);
    }

    if (s2 != first_2)
    {
        do
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->coe = s2->coe;
            new->exp = s2->exp;
            s2 = s2->link;
            last_sum->link = new;
            last_sum = new;
            last_sum->link = first_sum;
        } while (s2 != first_2);
    }
}
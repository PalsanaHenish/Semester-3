#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

int *t1;
int *t2;
int size1 = 0;
int size2 = 0;
int i = 0;

struct node *insert(struct node *root, int x);
void inOrder1(struct node *root);
void inOrder2(struct node *root);

int main()
{
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    int x;
    int choice = 1;

    while (choice)
    {
        printf("\nFor 1st tree....................\n0. Exit\n1. Insert\n");
        scanf("%d", &choice);
        if (choice)
        {
            printf("Enter Value : ");
            scanf("%d", &x);
            root1 = insert(root1, x);
            size1++;
        }
    }

    choice = 1;

    while (choice)
    {
        printf("\nFor 2nd tree....................\n0. Exit\n1. Insert\n");
        scanf("%d", &choice);
        if (choice)
        {
            printf("Enter Value : ");
            scanf("%d", &x);
            root2 = insert(root2, x);
            size2++;
        }
    }

    if (size1 == size2)
    {
        t1 = (int *)malloc(size1 * sizeof(int));
        inOrder1(root1);
        i = 0;
        t2 = (int *)malloc(size2 * sizeof(int));
        inOrder2(root2);
        for (int i = 0; i < size1; i++)
        {
            if (t1[i] != t2[i]) {
                printf("\nBoth trees are NOT same.");
                return 0;
            }
        }
        printf("\nBoth trees are same.\n");
    }
    else
    {
        printf("Both trees are NOT same.");
    }

    return 0;
}

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->info = x;
        new->left = new->right = NULL;
        return new;
    }

    if (x > root->info)
    {
        root->right = insert(root->right, x);
    }
    else if (x < root->info)
    {
        root->left = insert(root->left, x);
    }

    return root;
}

void inOrder1(struct node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        inOrder1(root->left);
    }

    t1[i++] = root->info;

    if (root->right != NULL)
    {
        inOrder1(root->right);
    }
}

void inOrder2(struct node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        inOrder2(root->left);
    }

    t2[i++] = root->info;

    if (root->right != NULL)
    {
        inOrder2(root->right);
    }
}
#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int x);
int largestValue(struct node *root);
int smallestValue(struct node *root);

int main()
{
    struct node *root = NULL;
    int x;

    while (1)
    {
        printf("Enter Value (-1 for exit):");
        scanf("%d", &x);
        if (x == -1)
        {
            break;
        }
        else
        {
            root = insert(root, x);
        }
    }

    printf("\nLargest Value : %d\n",largestValue(root));
    printf("Smallest Value : %d\n",smallestValue(root));

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

int largestValue(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        if (root->right != NULL)
        {
            return largestValue(root->right);
        }
        else
        {
            return root->info;
        }
    }
}

int smallestValue(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        if (root->left != NULL)
        {
            return smallestValue(root->left);
        }
        else
        {
            return root->info;
        }
    }
}
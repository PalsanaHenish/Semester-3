#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root);
int checkHeight(struct node *root);
int longestPath(struct node *root);

int main()
{
    struct node *root = NULL;

    root = insert(root);

    if (checkHeight(root))
    {
        printf("Height Balanced Tree!");
    }
    else
    {
        printf("NOT a Height Balanced Tree!");
    }

    return 0;
}

struct node *insert(struct node *root)
{
    int x;
    if (root == NULL)
    {
        printf("\nEnter root node value: ");
        scanf("%d", &x);
        struct node *new = malloc(sizeof(struct node));
        new->info = x;
        new->left = new->right = NULL;
        root = new;
    }

    int choice;
    char c;
    struct node *save = root;

    while (1)
    {
        printf("\n0. Exit\n1. Insert\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return root;

        case 1:
            save = root;
            while (save != NULL)
            {
                printf("\nWhere you want to insert below %d (left->l /right->r): ", save->info);
                scanf("%c", &c);
                scanf("%c", &c);
                if (c == 'l' && save->left != NULL)
                {
                    save = save->left;
                }
                else if (c == 'l' && save->left == NULL)
                {
                    printf("\nEnter Value: ");
                    scanf("%d", &x);
                    struct node *new = malloc(sizeof(struct node));
                    new->info = x;
                    new->left = new->right = NULL;
                    save->left = new;
                    save = NULL;
                }
                else if (c == 'r' && save->right != NULL)
                {
                    save = save->right;
                }
                else if (c == 'r' && save->right == NULL)
                {
                    printf("\nEnter Value: ");
                    scanf("%d", &x);
                    struct node *new = malloc(sizeof(struct node));
                    new->info = x;
                    new->left = new->right = NULL;
                    save->right = new;
                    save = NULL;
                }
            }

        default:
            break;
        }
    }
}

int checkHeight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else if (root->left == NULL || root->right == NULL)
    {
        if (root->left != NULL)
        {
            if (root->left->left != NULL || root->left->right != NULL)
            {
                return 0;
            }
            else if (root->right->left != NULL || root->right->right != NULL)
            {
                return 0;
            }
        }
    }

    int ll = longestPath(root->left);
    int rl = longestPath(root->right);

    if ((ll - rl) == 0 || (ll - rl) == 1 || (ll - rl) == -1)
    {
        int ans1 = checkHeight(root->left);
        int ans2 = checkHeight(root->right);

        return (ans1 && ans2);
    }
    else
    {
        return 0;
    }
}

int longestPath(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lpl = longestPath(root->left);
    int lpr = longestPath(root->right);

    int max = (lpl >= lpr) ? lpl : lpr;

    return (max + 1);
}
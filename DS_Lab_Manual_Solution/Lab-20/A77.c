#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root);
void inOrder(struct node *root, int **arr, int *size);
void freeTree(struct node *root);

int main()
{
    struct node *root = NULL;
    root = insert(root);

    int sizeL = 0;
    int *tl = NULL;
    inOrder(root->left, &tl, &sizeL);

    int sizeR = 0;
    int *tr = NULL;
    inOrder(root->right, &tr, &sizeR);

    if (sizeL == sizeR)
    {
        for (int i = 0; i < sizeR / 2; i++)
        {
            int temp = tr[i];
            tr[i] = tr[sizeR - i - 1];
            tr[sizeR - i - 1] = temp;
        }

        for (int i = 0; i < sizeL; i++)
        {
            if (tl[i] != tr[i])
            {
                printf("Not Symmetric!");
                free(tl);
                free(tr);
                freeTree(root);
                return 0;
            }
        }
        printf("Symmetric!");
    }
    else
    {
        printf("Not Symmetric!");
    }
    
    free(tl);
    free(tr);
    freeTree(root);

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

        if (choice != 0 && choice != 1)
        {
            choice = 0;
        }
        
        switch (choice)
        {
        case 0:
            return root;

        case 1:
            save = root;
            while (save != NULL)
            {
                printf("\nWhere you want to insert below %d (left-> '[' /right-> ']'): ", save->info);
                scanf(" %c", &c);
                if (c == '[' && save->left != NULL)
                {
                    save = save->left;
                }
                else if (c == '[' && save->left == NULL)
                {
                    printf("\nEnter Value: ");
                    scanf("%d", &x);
                    struct node *new = malloc(sizeof(struct node));
                    new->info = x;
                    new->left = new->right = NULL;
                    save->left = new;
                    save = NULL;
                }
                else if (c == ']' && save->right != NULL)
                {
                    save = save->right;
                }
                else if (c == ']' && save->right == NULL)
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
            break;

        default:
            break;
        }
    }
}

void inOrder(struct node *root, int **arr, int *size)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, arr, size);

    *arr = realloc(*arr, (*size + 1) * sizeof(int));
    (*arr)[*size] = root->info;
    (*size)++;

    inOrder(root->right, arr, size);
}

void freeTree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
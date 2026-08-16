// Binary Search Tree

#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int x);
struct node *delete(struct node *root, int x);
int search(struct node *root, int x);
void preorderTraversal(struct node *root);
void inorderTraversal(struct node *root);
void postorderTraversal(struct node *root);

int main()
{
    struct node *root = NULL;
    int choice;
    int x;

    while (1)
    {
        printf("\n0.Exit\n1.Insert\n2.Delete\n3.Search\n4.Preorder\n5.Inorder\n6.Postorder\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;

        case 1:
            printf("\nEnter No. : ");
            scanf("%d", &x);
            root = insert(root, x);
            break;

        case 2:
            break;

        case 3:
            printf("\nEnter No. you wanna search: ");
            scanf("%d",&x);
            if (search(root,x))
            {
                printf("\nPresent!\n");
            }
            else
            {
                printf("\nAbsent!\n");
            }
            break;

        case 4:
            printf("\n");
            preorderTraversal(root);
            printf("\n");
            break;
            
        case 5:
            printf("\n");
            inorderTraversal(root);
            printf("\n");
            break;
        
        case 6:
            printf("\n");
            postorderTraversal(root);
            printf("\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
            break;
        }
    }
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

struct node *delete(struct node *root, int x){

}

int search(struct node *root, int x)
{
    if (root == NULL){
        return 0;
    }

    struct node *save = root;
    while (save != NULL && save->info != x)
    {
        if(x > save->info){
            save = save->right;
        }
        else if (x < save->info)
        {
            save = save->left;
        }
    }

    if (save == NULL)
    {
        return 0;
    }
    else{
        return 1;
    }
}

void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->info);
    if (root->left != NULL)
    {
        preorderTraversal(root->left);
    }
    if (root->right != NULL)
    {
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        inorderTraversal(root->left);
    }

    printf("%d ", root->info);

    if (root->right != NULL)
    {
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        postorderTraversal(root->left);
    }

    if (root->right != NULL)
    {
        postorderTraversal(root->right);
    }

    printf("%d ", root->info);
}
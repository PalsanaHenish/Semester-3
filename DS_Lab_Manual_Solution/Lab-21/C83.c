#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

struct node
{
    char name[20];
    long phone_num;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, char name[20], long num);
struct node *delete(struct node *root, char name[20]);
long searchPhoneNum(struct node *root, char name[20]);
void ascOrder(struct node *root);
void descOrder(struct node *root);
void freeTree(struct node *root);

int main()
{
    struct node *root = NULL;
    char name[20];
    long phone_num;
    int choice;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display in Ascending order\n5.Display in Descending order\n");
        printf("\nPress any no. to exit (except 1-5)\nEnter Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter name : ");
            scanf(" %s", name);
            printf("Enter phone number : ");
            scanf("%ld", &phone_num);
            root = insert(root, name, phone_num);
            break;

        case 2:
            printf("\nEnter name you wanna delete : ");
            scanf(" %s", name);
            root = delete(root, name);
            break;

        case 3:
            printf("\nEnter name you wanna search : ");
            scanf(" %s", name);
            printf("Phone No. : %ld\n", searchPhoneNum(root, name));
            break;

        case 4:
            printf("\n");
            ascOrder(root);
            printf("\n");
            break;

        case 5:
            printf("\n");
            descOrder(root);
            printf("\n");
            break;
        
        default:
            freeTree(root);
            return 0;
        }
    }
}

struct node *insert(struct node *root, char name[20], long num)
{
    if (root == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        strcpy(new->name, name);
        new->phone_num = num;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else if (strcmp(name, root->name) < 0)
    {
        root->left = insert(root->left, name, num);
    }
    else if (strcmp(name, root->name) > 0)
    {
        root->right = insert(root->right, name, num);
    }
    else
    {
        printf("\nName already exist!\nTry again with different name.\n");
    }
    return root;
}

struct node *delete(struct node *root, char name[20])
{
    if (root == NULL)
    {
        printf("\nEmpty phone dictionary!\n");
        return NULL;
    }
    else if (strcmp(name, root->name) < 0)
    {
        root->left = delete(root->left, name);
    }
    else if (strcmp(name, root->name) > 0)
    {
        root->right = delete(root->right, name);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            struct node *save = root->left;
            free(root);
            return save;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            struct node *save = root->right;
            free(root);
            return save;
        }
        else
        {
            struct node *save = root->right;

            if (save->left != NULL)
            {
                struct node *temp = save;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
            }
            
            save->left = root->left;
            free(root);
            return save;
        }
    }

    return root;
}

long searchPhoneNum(struct node *root, char name[20])
{
    if (root == NULL)
    {
        printf("\nEmpty phone dictionary!\n");
        return -1;
    }
    else
    {
        struct node *save = root;

        while (save != NULL)
        {
            if (strcmp(name, save->name) < 0)
            {
                save = save->left;
            }
            else if (strcmp(name, save->name) > 0)
            {
                save = save->right;
            }
            else
            {
                return save->phone_num;
            }
        }

        printf("\nPhone number NOT found!\n");
        return -1;
    }
}

void ascOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    ascOrder(root->left);

    printf("\nName : %s ", root->name);
    printf(" Phone no. : %ld", root->phone_num);

    ascOrder(root->right);
}

void descOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    descOrder(root->right);
    
    printf("\nName : %s ", root->name);
    printf(" Phone no. : %ld", root->phone_num);
    
    descOrder(root->left);
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

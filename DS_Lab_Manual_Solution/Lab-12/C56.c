#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct playlist
{
    char music_name[20];
    struct playlist *lptr;
    struct playlist *rptr;
};

struct playlist *first = NULL;
struct playlist *current = NULL;

void insertMusic(char mname[20]);

void displayPlaylist();

void deleteMusic(int mnum);

void playMusic(int);

int main()
{
    int choice;
    char mname[20];
    int mnum;

    while (1)
    {
        printf("\n0. Exit\n1. Insert New Music\n2. Display Playlist\n3. Delete Music\n4. Play Previous Music\n5. Play First Music\n6. Play Next Music\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;

        case 1:
            printf("\nEnter Music Name: ");
            scanf("%s", mname);
            insertMusic(mname);
            break;

        case 2:
            displayPlaylist();
            break;

        case 3:
            printf("\nEnter Music Number: ");
            scanf("%d", &mnum);
            deleteMusic(mnum);
            break;

        case 4:
            playMusic(4);
            break;

        case 5:
            playMusic(5);
            break;

        case 6:
            playMusic(6);
            break;

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void insertMusic(char mname[20])
{
    struct playlist *new = (struct playlist *)malloc(sizeof(struct playlist));
    strcpy(new->music_name, mname);
    new->rptr = NULL;

    if (first == NULL)
    {
        first = new;
        first->lptr = NULL;
    }
    else
    {
        struct playlist *save = first;

        while (save->rptr != NULL)
            save = save->rptr;

        save->rptr = new;
        new->lptr = save;
    }
}

void displayPlaylist()
{
    if (first == NULL)
        printf("\nEmpty Playlist!\n");

    else
    {
        struct playlist *save = first;

        printf("\nPlaylist : \n");
        for (int i = 1; save != NULL; i++)
        {
            printf("%d. %s\n", i, save->music_name);
            save = save->rptr;
        }
        printf("End...!\n");
    }
}

void deleteMusic(int mnum)
{
    if (first == NULL)
        printf("\nEmpty Playlist!\n");

    else
    {
        if (first->rptr == NULL && mnum == 1)
        {
            free(first);
            first = NULL;
            return;
        }

        struct playlist *save = first;

        for (int i = 1; i != mnum && save != NULL; i++)
            save = save->rptr;

        if (save == NULL)
            printf("\n404!Music Not Found!\n");

        else
        {
            if (current->music_name != save->music_name)
            {
                if (save == first)
                {
                    first = first->rptr;
                    first->lptr = NULL;
                    free(save);
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

            else
            {
                printf("\nCurrently playing music can't be deleted!\n");
            }
        }
    }
}

void playMusic(int x)
{
    if (first == NULL)
        printf("\nEmpty Playlist! Can't Play!\n");

    else
    {
        if (x == 5)
        {
            current = first;
            printf("\nCurrently Playing: %s\n", current->music_name);
        }

        else if (x == 4 && current != NULL)
        {
            if (current->lptr == NULL)
                printf("\nThere is no previous music!\n");

            else
            {
                current = current->lptr;
                printf("\nCurrently Playing: %s\n", current->music_name);
            }
        }
        else if (x == 6 && current != NULL)
        {
            if (current->rptr == NULL)
                printf("\nThere is no next music!\n");

            else
            {
                current = current->rptr;
                printf("\nCurrently Playing: %s\n", current->music_name);
            }
        }
        else
        {
            printf("\nInvalid Choice! Start with first...\n");
        }
    }
}
#include "dblList.h"

void dbl_del_alt(struct node *first);

int main()
{
    struct node *first = NULL;
    for (int i = 1; i <= 11; i++)
        first = dbl_ins_end(i, first);

    dbl_display(first);

    dbl_del_alt(first);

    dbl_display(first);

    return 0;
}

void dbl_del_alt(struct node *first)
{
    if (first == NULL && first->rptr == NULL)
        return;

    int count = 0;
    struct node *save = first;
    while (save != NULL)
    {
        count++;
        save = save->rptr;
    }

    save = first;
    struct node *temp;

    for (int i = 1; i <= count; i++)
    {
        temp = save;

        if (i % 2 == 0)
        {
            if (save->rptr == NULL)
            {
                save->lptr->rptr = NULL;
                free(temp);
            }

            else
            {
                save->rptr->lptr = save->lptr;
                save->lptr->rptr = save->rptr;
                save = save->rptr;
                free(temp);
            }
        }

        else
        {
            save = save->rptr;
        }
    }
}
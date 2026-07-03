#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *insend(int x, struct node *first);

struct node *removeDuplicates(struct node *first);

void display(struct node *first);

int main(){
    struct node *first = NULL;

    printf("Enter size: ");
    int size;
    scanf("%d", &size);

    for(int i=0;i<size;i++){
        int x;
        printf("Enter value: ");
        scanf("%d", &x);
        first = insend(x, first);
    }
    display(first);

    first = removeDuplicates(first);
    display(first);

    return 0;
}

struct node *insend(int x, struct node *first){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->link = NULL;

    if(first == NULL){
        first = new;
    }
    else{
        struct node *save = first;
        while(save->link != NULL){
            save = save->link;
        }
        save->link = new;
    }

    return first;
}

struct node *removeDuplicates(struct node *first){
    struct node *save = first;
    struct node *pred = save;

    if(first == NULL){
        return first;
    }
    else{
        while(save != NULL){
            if(pred->info == save->info){
                struct node *temp = save;
                pred->link = save->link;
                save = save->link;
                free(temp);
            }
            else{
                pred = save;
                save = save->link;
            }
        }
    }
    return first;
}

void display(struct node *first){
    if(first == NULL){
        printf("\nempty list!\n");
        return;
    }

    struct node *save = first;
    printf("[");
    while(save != NULL){
        printf("%d,",save->info);
        save = save->link;
    }
    printf("\b]\n");
}
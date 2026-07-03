#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *insend(int x, struct node *first);

int listCompare(struct node *first_1, struct node *first_2);

int main() {
    struct node *first_1 = NULL;
    struct node *first_2 = NULL;

    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    printf("Enter elements for the first linked list:\n");
    for(int i=0; i<size; i++){
        int t;
        printf("Enter info: ");
        scanf("%d", &t);
        first_1 = insend(t, first_1);
    }

    printf("Enter elements for the second linked list:\n");
    for(int i=0; i<size; i++){
        int t;
        printf("Enter info: ");
        scanf("%d", &t);
        first_2 = insend(t, first_2);
    }

    if(listCompare(first_1, first_2)){
        printf("Both linked lists are equal.\n");
    }
    else{
        printf("Both linked lists are not equal.\n");
    }
    
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

int listCompare(struct node *first_1, struct node *first_2){
    struct node *save_1 = first_1;
    struct node *save_2 = first_2;

    while(save_1 != NULL && save_2 != NULL){
        if(save_1->info != save_2->info){
            return 0;
        }
        save_1 = save_1->link;
        save_2 = save_2->link;
    }

    if(save_1 == NULL && save_2 == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

#include "stdio.h"
#include "../A42.h"

//this function copy the first linked list to second linked list and return address of
//first node of second linked list.
struct node *copy_list(struct node *first_1);

int main() {
    struct node *first_1 = NULL;
    
    for(int i=0;i<5;i++){
        first_1 = insend((int)(rand()%100),first_1);
    }

    printf("\nList 1: ");
    display(first_1);

    struct node *first_2 = copy_list(first_1);
    printf("\nList 2: ");
    display(first_2);

    return 0;
}

struct node *copy_list(struct node *first_1){
    struct node *first_2 = (struct node *)malloc(sizeof(struct node));
    first_2->info = first_1->info;

    struct node *save_1 = first_1;    
    struct node *save_2 = first_2;    
    
    while(save_1->link != NULL){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->info = save_1->link->info;
        save_2->link = new;
        save_1 = save_1->link;
        save_2 = save_2->link;
    }
    save_2->link = NULL;

    return first_2;
}

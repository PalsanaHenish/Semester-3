// write a menu driven program to implement following operations on the singly linked list.  
//   insert a node at the front of the linked list. 
//   display all nodes. 
//   delete a first node of the linked list. 
//   insert a node at the end of the linked list. 
//   delete a last node of the linked list. 
//   delete a node from specified position. 
//   count the no. of nodes in the linked list.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
};

//this function add element at first position and return new address of first node.
struct node *insfir(int x, struct node *first);

//this function display all nodes in a list.
void display(struct node *first);

//this function delete first node from the list.
struct node *delfir(struct node *first, int *deleted_value);

//this function insert the node at the end of the singly linked linear list.
struct node *insend(int x, struct node *first);

//this function delete last not from singly linked linear list.
struct node *delend(struct node *first, int *deleted_value);

//this function delete a node from specified position.
struct node *delete(struct node *first, int x, int *deleted_value);

//this function count the number of nodes in the singly linked linear list.
int count(struct node *first);



struct node *insfir(int x, struct node *first){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    new->link = first;
    first = new;
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

struct node *delfir(struct node *first, int *deleted_value){
    if(first == NULL){
        printf("\nempty list!\n");
        return NULL;
    }

    struct node *temp = first;
    *deleted_value = first->info;

    first = first->link;

    free(temp);

    return first;
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

struct node *delend(struct node *first, int *deleted_value){
    if(first == NULL){
        printf("\nempty list!\n");
        return NULL;
    }
    else if(first->link == NULL){
        *deleted_value = first->info;
        free(first);
        return NULL;
    }
    else{
        struct node *save = first;
        while(save->link->link != NULL){
            save = save->link;
        }
        struct node *temp = save->link;
        *deleted_value = temp->info;
        save->link = NULL;
        free(temp);
        return first;
    }
}

struct node *delete(struct node *first, int x, int *deleted_value){
    if(first == NULL){
        printf("\nempty list!\n");
        return NULL;
    }
    else if(first->info == x && first->link == NULL){
        *deleted_value = first->info;
        free(first);
        return NULL;
    }
    else{
        struct node *save = first;
        while(save->link != NULL && save->link->info != x){
            save = save->link;
        }
        struct node *temp = save->link;
        if(temp == NULL){
            printf("\n404! Not found!\n",x);
            return first;
        }
        else{
            *deleted_value = temp->info;
            save->link = temp->link;
            free(temp);
            return first;
        }
    }
}

int count(struct node *first){
    int count = 0;
    struct node *save = first;
    while(save != NULL){
        count++;
        save = save->link;
    }
    return count;
}
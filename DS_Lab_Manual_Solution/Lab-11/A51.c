#include "stdio.h"
#include "stdlib.h"

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

// This function inserts a new node with the given value at the beginning of the circular linked list.
void cir_ins_fir(int x);

// This function deletes a node with the given value from the circular linked list.
void cir_del(int x);

// This function inserts a new node with the given value at the end of the circular linked list.
void cir_ins_end(int x);

// This function displays the elements of the circular linked list.
void cir_disp();

// int main() {
//     int x;
//     int choice;
    
//     while(1){
//         printf("\n1. Insert at beginning\n");
//         printf("2. Delete an element\n");
//         printf("3. Insert at end\n");
//         printf("4. Display the list\n");
//         printf("5. Exit\n");
//         scanf("%d", &choice);
//         switch(choice){
//             case 1:
//                 printf("Enter the element to insert at the beginning: ");
//                 scanf("%d", &x);
//                 cir_ins_fir(x);
//                 break;
//             case 2:
//                 printf("Enter the element to delete: ");
//                 scanf("%d", &x);
//                 cir_del(x);
//                 break;
//             case 3:
//                 printf("Enter the element to insert at the end: ");
//                 scanf("%d", &x);
//                 cir_ins_end(x);
//                 break;
//             case 4:
//                 cir_disp();
//                 break;
//             case 5:
//                 return 0;
//             default:
//                 printf("Invalid choice\n");
//         }
//     }
// }

void cir_ins_fir(int x){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;

    if(first == NULL){
        first = new;
        new->link = first;
        last = new;
    }
    else{
        new->link = first;
        first = new;
        last->link = first;
    }
}

void cir_del(int x){
    if(first == NULL){
        printf("\nList is empty\n");
        return;
    }
    else if(first->info == x){
        if(first->link == first){
            free(first);
            first = NULL;
            last = NULL;
        }
        else{
            struct node *temp = first;
            first = first->link;
            last->link = first;
            free(temp);
        }
    }
    else{
        struct node *save = first;
        struct node *pred = NULL;

        while(save != last && save->info != x){
            pred = save;
            save = save->link;
        }

        if(save->info == x){
            pred->link = save->link;
            if(save == last){
                last = pred;
            }
            free(save);
        }
        else{
            printf("Element not found\n");
        }
    }
}

void cir_ins_end(int x){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;

    if(first == NULL){
        first = new;
        new->link = first;
        last = new;
    }
    else{
        last->link = new;
        new->link = first;
        last = new;
    }
}

void cir_disp(){
    if(first == NULL){
        printf("\nList is empty\n");
        return;
    }
    printf("\n[");
    struct node *save = first;
    do{
        printf("%d, ", save->info);
        save = save->link;
    } while(save != first);
    printf("\b\b]\n");
}
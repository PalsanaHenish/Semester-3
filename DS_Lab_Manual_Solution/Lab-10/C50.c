#include "stdio.h"
#include "../A42.h"

// Function to swap consecutive nodes in a singly linked list
struct node *swap_consecutive_node(struct node *first);

int main() {
    struct node *first = NULL;
    int n;

    for(int i = 1; i <= 8; i++){
        printf("Enter value for node %d: ", i);
        scanf("%d",&n);
        first = insend(n, first);
    }

    printf("\nInitial Linked List:\n");
    display(first);

    first = swap_consecutive_node(first);
    printf("\nLinked List after swapping consecutive nodes:\n");
    display(first);

    return 0;
}

struct node *swap_consecutive_node(struct node *first){
    if(first == NULL || first->link == NULL){
        return first;
    }
    
    struct node *pred = NULL;
    struct node *save = first;
    struct node *next = first->link;

    while(next != NULL){
        if(pred == NULL){   
            save->link = next->link;
            next->link = save;
            first = next;
            pred = save;
            save = save->link;
            next = save->link;
        }

        else{
            pred->link = next;
            save->link = next->link;
            next->link = save;
            if(save->link != NULL){
                pred = save;
                save = save->link;
                next = save->link;
            }
            else{
                break;
            }
        }
    }

    return first;
}
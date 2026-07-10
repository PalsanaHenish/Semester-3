#include "stdio.h"
#include "../A42.h"

//this function reverse the linked list and return address of first node of reversed linked list.
struct node *reverse(struct node *first);

int main(){
    struct node *first_1 = NULL;
    
    for(int i=0;i<5;i++){
        first_1 = insend((int)(rand()%100),first_1);
    }

    printf("\nList: ");
    display(first_1);

    first_1 = reverse(first_1);
    printf("\nReversed List: ");
    display(first_1);

    return 0;
}

struct node *reverse(struct node *first){
    if(first == NULL || first->link == NULL){
        return first;
    }
    else{
        struct node *save = first;
        struct node *pred = first;
        int c = 0;

        while(save->link != NULL){
            pred = save;
            save = save->link;
            c++;
        }

        struct node *temp = save;
        save->link = pred;
        save = pred;

        for(int i=0; i<c-1; i++){
            pred = first;
            while(pred->link != save){
                pred = pred->link;
            }
            save->link = pred;
            save = pred;
        }

        pred->link = NULL;
        first = temp;

        return first;
    }
}
#include "../A42.h"

// Function to swap the Kth node from the beginning with the Kth node from the end in a 
// singly linked list.
struct node *swap_Kth_node(int k, struct node *first);

int main(){
    struct node *first = NULL;
    for(int i = 1; i <= 2; i++){
        first = insend(i, first);
    }
    printf("\nInitial Linked List:\n");
    display(first);
    printf("\nSwapping Kth node from beginning with Kth node from end:\n");
    for(int i = 1; i <= 2; i++){
        first = swap_Kth_node(i, first);
        display(first);
    }
    return 0;
}

struct node *swap_Kth_node(int s, struct node *first){
    if(first == NULL || first->link == NULL || s <= 0){
        return first;
    }
    
    int m = count(first);
    int e = m - s + 1;

    if(s > m){
        printf("\nLinkedListIndexOutOfBound!\n");
        return first;
    }
    else if(s == e){
        return first;
    }

    struct node *save1 = first;
    struct node *pred1 = NULL;

    struct node *save2 = first;
    struct node *pred2 = NULL;

    for(int i = 1; i < s; i++){
        pred1 = save1;
        save1 = save1->link;
    }

    for(int i = 1; i < e; i++){
        pred2 = save2;
        save2 = save2->link;
    }

    if(m == 2 && save1 == first){
        save2->link = save1;
        save1->link = NULL;
        first = save2;
    }
    else if(m == 2 && save2 == first){
        save1->link = save2;
        save2->link = NULL;
        first = save1;
    }
    else if(save1 == first){
        save2->link = save1->link;
        save1->link = NULL;
        pred2->link = save1;
        first = save2;
    }
    else if(save2 == first){
        save1->link = save2->link;
        save2->link = NULL;
        pred1->link = save2;
        first = save1;
    }
    else if(save1->link == save2){
        save1->link = save2->link;
        save2->link = save1;
        pred1->link = save2;
    }   
    else if(save2->link == save1){
        save2->link = save1->link;
        save1->link = save2;
        pred2->link = save1;
    }
    else{
        struct node *temp = save1->link;
        pred1->link = save2;
        save1->link = save2->link;
        pred2->link = save1;
        save2->link = temp;
    }
    return first;
}
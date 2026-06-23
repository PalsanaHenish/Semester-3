// Write a menu driven program to implement following operations on the singly linked list.  
//   Insert a node at the front of the linked list. 
//   Display all nodes. 
//   Delete a first node of the linked list. 
//   Insert a node at the end of the linked list. 
//   Delete a last node of the linked list. 
//   Delete a node from specified position. 
//   Count the no. of nodes in the linked list.

#include<stdio.h>
#include<stdlib.h>

struct NODE {
    int INFO;
    struct NODE *LINK;
};


//this function add element at first position and return new address of first node.
struct NODE *INSFIR(int X, struct NODE *FIRST);

//this function display all nodes in a list.
void DISPLAY(struct NODE *FIRST);

//this function delete first node from the list.
struct NODE *DELFIR(struct NODE *FIRST, int *deleted_value);

int main(){
    struct NODE *FIRST = NULL;

    while(1){
        int choice;
        int popped_value = -1;
        printf("\n0.Exit\n1.Insert at First\n2.Display all Nodes\n3.Delete first node\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value you want to insert: ");
                int X;
                scanf("%d",&X);
                FIRST = INSFIR(X,FIRST);
                break;

            case 2:
                DISPLAY(FIRST);
                break;

            case 3:
                FIRST = DELFIR(FIRST,&popped_value);
                break;

            case 0:
                return 0;

            default:
                printf("\nERROR! Enter valid choice....\n");
        }
    }
}

struct NODE *INSFIR(int X, struct NODE *FIRST){
    struct NODE *NEW = (struct NODE *)malloc(sizeof(struct NODE));
    NEW->INFO = X;
    NEW->LINK = FIRST;
    FIRST = NEW;
    return FIRST;
}

void DISPLAY(struct NODE *FIRST){
    if(FIRST == NULL){
        printf("\nEmpty List!\n");
        return;
    }

    struct NODE *NEXT = FIRST;
    printf("[");
    while(NEXT != NULL){
        printf("%d,",NEXT->INFO);
        NEXT = NEXT->LINK;
    }
    printf("\b]\n");
}

struct NODE *DELFIR(struct NODE *FIRST, int *deleted_value){

    if(FIRST == NULL){
        printf("\nEmpty List!\n");
        return NULL;
    }

    struct NODE *TEMP = FIRST;
    *deleted_value = FIRST->INFO;

    FIRST = FIRST->LINK;

    free(TEMP);

    return FIRST;
}


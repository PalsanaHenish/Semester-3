#include "stdio.h"
#include "A51.c"

// struct node *first = NULL;
// struct node *last = NULL;
struct node *head_1 = NULL;
struct node *tail_1 = NULL;
struct node *head_2 = NULL;
struct node *tail_2 = NULL;

void cir_split();
void cir_disp_head_1();
void cir_disp_head_2();

int main(){
    for(int i=1; i<10; i++){
        cir_ins_end(i);
    }
    cir_disp();
    cir_split();
    cir_disp_head_1();
    cir_disp_head_2();

    return 0;
}

void cir_split(){
    head_1 = first;
    tail_1 = first;
    if(first == NULL || first->link == last){
        return;
    }

    struct node *save = first;

    int count = 0;
    do{
        count++;
        save = save->link;
    } while(save != first);

    int n;
    if(count % 2 == 0) n = count/2;
    else n = ((count/2) + 1);

    save = first;

    for(int i=0; i<n-1; i++){
        save = save->link;
    }

    tail_1 = save;
    head_2 = save->link;
    tail_1->link = head_1;
    tail_2 = last;
    tail_2->link = head_2;

}

void cir_disp_head_1(){
    if(head_1 == NULL){
        printf("\nList is empty\n");
        return;
    }
    printf("\n[");
    struct node *save = head_1;
    do{
        printf("%d, ", save->info);
        save = save->link;
    } while(save != head_1);
    printf("\b\b]\n");
}

void cir_disp_head_2(){
    if(head_2 == NULL){
        printf("\nList is empty\n");
        return;
    }
    printf("\n[");
    struct node *save = head_2;
    do{
        printf("%d, ", save->info);
        save = save->link;
    } while(save != head_2);
    printf("\b\b]\n");
}
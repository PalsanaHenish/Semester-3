#include<stdio.h>
#include "../A42.h"
struct node *sort_list(struct node *first);
int main(){
    struct node *first = NULL;
    for(int i=10; i>0; i--){
        first = insend(i, first);
    }

    display(first);

    first = sort_list(first);

    display(first);

    return 0;
}

struct node *sort_list(struct node *first){
    if(first == NULL || first->link == NULL){
        return first;
    }
    else{
        int n = count(first);
        struct node *pred = NULL;
        struct node *save = first;
        struct node *next = first->link;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1-i; j++){
                if(pred == NULL && (save->info > next->info)){
                    save->link = next->link;
                    next->link = save;
                    first = next;
                    pred = first;
                    next = save->link;
                }
                else if(save->info > next->info){
                    pred->link = next;
                    save->link = next->link;
                    next->link = save;
                    pred = next;
                    next = save->link;
                    
                }
                else{
                    pred = save;
                    save = next;
                    next = next->link;
                }
            }
            pred = NULL;
            save = first;
            next = first->link;
        }
        return first;
    }
}
#include<stdio.h>
#include"../A42.h"

void InsertGcd(struct node *first);

int main(){
    struct node *first = NULL;
    int n;
    for(int i = 1; i <= 4; i++){
        scanf("%d",&n);
        first = insend(n, first);
    }
    printf("\nInitial Linked List:\n");
    display(first);
    InsertGcd(first);
    display(first);

    return 0;
}

void InsertGcd(struct node *first){
    if(first == NULL || first->link == NULL){
        return;
    }
    
    struct node *pred=first;
    struct node *save=first->link;
    int min,gcd;
    
    while(save!=NULL){
        min=(pred->info>save->info)?save->info:pred->info;
        for(int i=min;i>=1;i--){
            if(pred->info%i==0 && save->info%i==0){
                gcd=i;
                break;
            }
        }
        
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->info=gcd;
        new->link=save;
        pred->link=new;
        
        pred=save;
        save=save->link;
    }
}
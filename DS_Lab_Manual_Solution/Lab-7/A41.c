#include<stdio.h>

struct node {
    int info;
    struct node *link;
};

int main() {
    struct node *first = (struct node *)malloc(sizeof(struct node));
    first->info = 10;
    first->link = NULL;

    printf("INFO: %d\n", first->info);
    printf("LINK: %p\n",first->link);
    return 0;
}
    
// Write a program to delete a number from a given location in an array. 

#include<stdio.h>

int main(){
    int size;
    printf("Enter size of an array: ");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++){
        printf("Enter Element: ");
        scanf("%d",&arr[i]);
    }

    printf("Current Array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    printf("\nDo you want to delete any no. in this array? (y/n) : ");
    char c;
    scanf("%c",&c);
    scanf("%c",&c);

    if(c == 'y'){
        int pos;
        printf("Enter position: ");
        scanf("%d",&pos);

        for(int i=pos-1;i<size-1;i++){
            arr[i] = arr[i+1];
        }

        printf("Updated Array: ");
        for(int i=0;i<size-1;i++){
            printf("%d ",arr[i]);
        }
    }

    return 0;
}
// Write a program to insert a number at a given location in an array.

#include<stdio.h>

int main(){
    int size;
    printf("Enter size of an array: ");
    scanf("%d",&size);
    size++;

    int arr[size];
    for(int i=0;i<size-1;i++){
        printf("Enter Element: ");
        scanf("%d",&arr[i]);
    }

    printf("Current Array: ");
    for(int i=0;i<size-1;i++){
        printf("%d ",arr[i]);
    }

    printf("\nDo you want to enter a no. inside the array? (y/n) : ");
    char c;
    scanf("%c",&c);
    scanf("%c",&c);

    if(c == 'y'){
        int n,pos;
        printf("Enter no. and position: ");
        scanf("%d",&n);
        scanf("%d",&pos);

        int i;
        for(i = size - 1; i >= pos - 1; i--){
            arr[i] = arr[i-1];
        }

        arr[pos - 1] = n;

        printf("Updated Array: ");
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
    }

    return 0;
}

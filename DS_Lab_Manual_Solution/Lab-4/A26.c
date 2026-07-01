// Write a program to insert a number in an array that is already sorted in an 
// ascending order.

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
        int n;
        printf("Enter no. and position: ");
        scanf("%d",&n);

        int i;
        for(i = size - 1; arr[i] > n; i--){
            arr[i] = arr[i-1];
        }

        arr[i+1] = n;

        printf("Updated Array: ");
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
    }

    return 0;
}

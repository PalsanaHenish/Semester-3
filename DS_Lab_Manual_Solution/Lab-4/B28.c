// Write a program to delete duplicate numbers from an array.

#include<stdio.h>

int main(){
    int size;
    printf("Enter size of an array: ");
    scanf("%d",&size);
    
    printf("Enter sorted array: \n");
    int arr[size];
    for(int i=0;i<size;i++){
        printf("Enter Element: ");
        scanf("%d",&arr[i]);
    }

    printf("Current Array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] == arr[j]){
                for(int k = j; k < size-1; k++){
                    arr[k] = arr[k+1];
                }
                size--;
                j--;
            }
        }
    }

    printf("\nAfter removing duplicate elements: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
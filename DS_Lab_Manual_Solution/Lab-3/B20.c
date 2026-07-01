// Write a program to find whether the array contains a duplicate number or not. 


#include<stdio.h>

int main(){
    int size;
    printf("Enter Size Of An Array: ");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++){
        printf("Enter Element: ");
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                printf("Duplicate Element Found!!!");
                return 0;
            }
        }
    }

    printf("No duplicate element exists!!!");

    return 1;
}
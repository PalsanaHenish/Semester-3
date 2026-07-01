// Write a program to merge two unsorted arrays.

#include<stdio.h>

int main(){
    int size_1,size_2;
    printf("Enter size of two arrays: ");
    scanf("%d %d",&size_1,&size_2);

    int arr_1[size_1], arr_2[size_2];

    printf("For First Array: \n");
    for(int i=0; i<size_1; i++){
        printf("Enter Element: ");
        scanf("%d",&arr_1[i]);
    }

    printf("For Second Array: \n");
    for(int i=0; i<size_2; i++){
        printf("Enter Element: ");
        scanf("%d",&arr_2[i]);
    }

    int size_3 = size_1 + size_2;
    int arr_3[size_3];
    
    for(int i=0; i<size_1; i++){
        arr_3[i] = arr_1[i]; 
    }

    int x = 0;
    for(int i=size_1; i<size_3; i++){
        arr_3[i] = arr_2[x];
        x++; 
    }

    printf("Merged Array: ");
    for(int i=0; i<size_3; i++){
        printf("%d ",arr_3[i]);
    }

    return 0;
}
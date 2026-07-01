#include<stdio.h>
void main(){
    int arr[5];
    int *ptr;
    ptr=arr;
    for(int i=0;i<5;i++){
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", ptr+i);
    }
    for(int i=0;i<5;i++){
        printf("Value for arr[%d]: %d\n", i, *(ptr+i));
    }
}

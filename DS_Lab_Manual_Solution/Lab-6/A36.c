#include<stdio.h>
#include<string.h>
void main(){
    int arr[5];
    int *ptr;
    ptr=arr;
    int sum=0;
    for(int i=0;i<5;i++){
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", ptr+i);
    }
    for(int i=0;i<5;i++){
        sum=sum+*(ptr+i);
    }
    printf("Sum of array elements: %d\n", sum);
}
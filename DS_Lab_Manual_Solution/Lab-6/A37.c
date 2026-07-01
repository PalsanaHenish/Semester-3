#include<stdio.h>
#include<string.h>
void main(){
    int arr[5];
    int *ptr;
    ptr=arr;
    for(int i=0;i<5;i++){
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", ptr+i);
    }
    int max=*ptr;
    for(int i=0;i<5;i++){
        if(*(ptr+i)>max){
            max=*(ptr+i);
        }
    }
    printf("Maximum value in array: %d\n", max);
}
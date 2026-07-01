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
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(*(ptr+j)>*(ptr+j+1)){
                int temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
            }
        }
    }
    printf("Bubble Sorted array: ");
    for(int i=0;i<5;i++){
        printf("%d ", *(ptr+i));
    }
    printf("\n");
}
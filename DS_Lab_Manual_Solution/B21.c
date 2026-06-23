// Read n numbers in an array then read two different numbers, replace 1st 
// number with 2nd number in an array and print its index and final array. 

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

    int m,n;
    printf("Enter no. to be replaced(m) and replaced by(n): ");
    scanf("%d %d",&m,&n);

    for (int i = 0; i < size; i++){
        if(arr[i] == m){
            arr[i] = n;
            break;
        }
    }

    printf("Updated Array:");
    for(int i=0;i<size;i++){
        printf("  %d",arr[i]);
    }
    
    return 0;
}
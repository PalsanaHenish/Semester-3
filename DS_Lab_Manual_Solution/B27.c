// Write a program to delete a number from an array that is already sorted in an 
// ascending order. 

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

    printf("\nDo you want to delete any no. inside this array? (y/n) : ");
    char c;
    scanf("%c",&c);
    scanf("%c",&c);

    if(c == 'y'){
        int n;
        printf("Enter no. : ");
        scanf("%d",&n);

        int c=0,index;
        for(int i = 0; i < size; i++){
            if (arr[i]==n){
                c++;
                index = i;
            }
        }
        index = index - c + 1;
        
        for(int i = 0; i < c; i++){
            for(int j = index; j < size - 1; j++){
                arr[j] = arr[j+1];
            }
            size--;
        }

        printf("Updated Array: ");
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
    }

    return 0;
}

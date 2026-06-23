// Read two 2x2 matrices and perform addition of matrices into third matrix and 
// print it.

#include<stdio.h>

int main(){
    int a[2][2];
    int b[2][2];

    printf("Matrix 1: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Enter a[%d][%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nMatrix 2: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Enter a[%d][%d]: ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    
    printf("Sum: \n");
    for(int i=0; i<2; i++){
        printf("|");
        for(int j=0; j<2; j++){
            printf(" %d ",a[i][j]+b[i][j]);
        }
        printf("|\n");
    }

    return 0;
}
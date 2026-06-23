// Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
// and store result in third matrix and print it. 

#include<stdio.h>

int main(){
    int a[3][2];
    int b[2][3];

    printf("Enter a: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            printf("a[%d][%d] = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter b: \n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("b[%d][%d] = ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    int c[3][3];
    int sum = 0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                sum += a[i][k]*b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }

    printf("a*b = \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("|%3d|",c[i][j]);
        }
        printf("\n");
    }

}
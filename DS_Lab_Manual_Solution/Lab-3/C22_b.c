// WAP to print Pascal triangle. 

#include<stdio.h>

int main(){
    int row;
    printf("Enter no. of row: ");
    scanf("%d",&row);

    for(int i=0;i<row;i++){
        for(int k=0;k<=row-i;k++){
             printf("  ");
        }

        int t = 1;

        for(int j=0;j<=i;j++){
            printf("%4d",t);
            t = t*(i-j)/(j+1);
        }

        printf("\n");
    }

    return 0;
}
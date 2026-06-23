// WAP to print Pascal triangle. 

#include<stdio.h>

int main(){
    int row;
    printf("Enter no. of row: ");
    scanf("%d",&row);

    int pdt=1,temp=pdt,rem;
    for(int i=0;i<row;i++){
        for(int j=0;j<row-i;j++){
             printf(" ");
        }
        for(;pdt!=0;){
            rem = pdt%10;
            pdt /= 10;
            printf("%d ",rem);
        }
        printf("\n");
        pdt = temp * 11;
        temp = pdt;
    }

    return 0;
}
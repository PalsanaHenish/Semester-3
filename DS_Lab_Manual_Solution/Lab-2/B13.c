#include <stdio.h>

int main() {
    int n,t=1;

    printf("Enter a range: ");
    scanf("%d", &n);

    for(int i=2;i<=n;i++){
        t = 1;
        for(int j=2;j<i;j++){
            if (i % j == 0){
                t = 0;
                break;
            }
        }
        if(t){
            printf("%d is a prime number.\n", i);
        }
    }

    return 0;
}
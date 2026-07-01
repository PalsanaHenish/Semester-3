#include <stdio.h>

int main() {
    int n, i, t = 1;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    
    for(i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            t = 0;
            break;
        }
    }
    
    
    if(t){
        printf("%d is a prime number.", n);
    }
    else{
        printf("%d is not a prime number.", n);
    }
    
    return 0;
}
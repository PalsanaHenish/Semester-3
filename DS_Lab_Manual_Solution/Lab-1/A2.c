#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("even");
    } 
    else {
        printf("odd");
    }
    return 0;
}
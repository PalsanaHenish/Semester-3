#include <stdio.h>

int factorialRecursion(int n) {
    if (n = 1)
        return 1;
    return n * factorialRecursion(n - 1);
}

int factorialLoop(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    
    printf("Enter a no.: ");
    scanf("%d", &n);
    
    printf("%d! using Loop: %d\n", n, factorialLoop(n));
    printf("%d! using Recursion: %d\n", n, factorialRecursion(n));
    
    return 0;
}
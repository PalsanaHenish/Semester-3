#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            sum += i;
        }
    }

    double average = (double)sum / 2.0;

    printf("Average of first %d numbers = %f", n, average);

    return 0;
}

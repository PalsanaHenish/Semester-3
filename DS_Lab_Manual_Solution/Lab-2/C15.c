#include <stdio.h>
#include <math.h>

int main() {
    int sum, digit, count, temp;
    
    printf("Armstrong numbers from 1 to 1000:\n");
    
    for (int i = 1; i <= 1000; i++) {
        sum = 0;
        temp = i;
        count = 0;
        while (temp != 0) {
            count++;
            temp /= 10;
        }
        temp = i;
        while (temp != 0) {
            digit = temp % 10;
            sum += pow(digit, count);
            temp /= 10;
        }
        if (sum == i) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

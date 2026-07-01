#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter two numbers (m and n): ");
    scanf("%d %d", &m, &n);
    

    if (m > n) {
        int temp = m;
        m = n;
        n = temp;
    }

    int sum = 0;
    for(int i = m; i <= n; i++){
        if(i % 2 == 0){
            sum += i;
        }
    }

    printf("%d", sum);

    return 0;
}

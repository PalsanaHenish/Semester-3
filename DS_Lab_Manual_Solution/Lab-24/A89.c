#include "stdio.h"
#include "stdlib.h"

int main()
{
    int size;
    printf("Enter Size: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter element : ");
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter number you wanna search : ");
    scanf("%d", &x);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            printf("%d found at index %d.", x, i);
            return 0;
        }
    }

    printf("404! Not Found.");

    return 0;
}
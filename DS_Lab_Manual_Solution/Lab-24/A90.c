#include "stdio.h"
#include "stdlib.h"

int main()
{
    int size;
    printf("Enter Size: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size!\n");
        return 1;
    }

    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter element : ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int x;
    printf("Enter number you wanna search : ");
    scanf("%d", &x);

    int i = 0;
    int j = size - 1;
    int n = j / 2;

    while (1)
    {
        if (arr[n] == x)
        {
            printf("Present!");
            free(arr);
            return 0;
        }
        else if (arr[n] < x)
        {
            i = n + 1;
            n = (i + j) / 2;
        }
        else if (arr[n] > x)
        {
            j = n - 1;
            n = (i + j) / 2;
        }

        if (i > j)
        {
            printf("404! Not Found.");
            free(arr);
            return 0;
        }
    }
}
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

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
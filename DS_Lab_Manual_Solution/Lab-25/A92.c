#include "stdio.h"
#include "stdlib.h"

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    int min_index;
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
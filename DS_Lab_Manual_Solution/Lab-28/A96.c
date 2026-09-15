#include "stdio.h"
#include "stdlib.h"

int main()
{
    int size;
    printf("Enter no. of objects: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    printf("Enter 0 for red, 1 for white and 2 blue: \n");

    for (int i = 0; i < size; i++)
    {
        printf("Enter object: ");
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Objects after sorting : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
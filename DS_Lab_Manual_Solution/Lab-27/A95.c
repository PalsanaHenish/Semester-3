// Quick Sort

#include "stdio.h"
#include "stdlib.h"

int size;
int *arr;

void quickSort(int lb, int ub);

int main()
{
    printf("Enter size of array : ");
    scanf("%d", &size);

    arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    quickSort(0, size);

    printf("Quick Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void quickSort(int lb, int ub)
{
    if (lb >= ub)
    {
        return;
    }
    int flag = 1;
    int i = lb;
    int j = ub;
    int key = arr[lb];

    while (flag == 1)
    {
        i++;
        while (arr[i] < key)
        {
            i++;
        }
        j--;
        while (arr[j] > key)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            flag = 0;
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[j];
    arr[j] = temp;

    quickSort(lb, j - 1);
    quickSort(j + 1, ub);
}

#include "stdio.h"
#include "stdlib.h"

int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter element: ");
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

    int k;
    printf("Enter integer K: ");
    scanf("%d", &k);

    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (sum + arr[i] <= k)
        {
            sum += arr[i];
        }
        else{
            break;
        }
    }
    
    printf("Length of the longest subarray with sum <= K is %d.", i);

    return 0;
}
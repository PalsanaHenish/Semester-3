#include "stdio.h"
#include "stdlib.h"

int top = -1;
int **stack;
int rows;

void mergeOverlappingIntervals();

int main()
{
    printf("Enter Size: ");
    scanf("%d", &rows);

    stack = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
    {
        stack[i] = (int *)malloc(sizeof(int) * 2);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter Element (%d,%d) : ", i + 1, j + 1);
            scanf("%d", &stack[i][j]);
        }
    }

    mergeOverlappingIntervals();

    return 0;
}

void mergeOverlappingIntervals()
{
    int temp1;
    int temp2;

    for (int i = 0; i < rows - 1; i++)
    {
        if (stack[i][0] > stack[i + 1][0])
        {
            temp1 = stack[i][1];
            temp2 = stack[i][0];

            stack[i][1] = stack[i + 1][1];
            stack[i][0] = stack[i + 1][0];

            stack[i + 1][1] = temp1;
            stack[i + 1][0] = temp2;
        }
    }

    for (int i = 0; i < rows - 1; i++)
    {
        if (stack[i][1] > stack[i + 1][0] && stack[i][1] < stack[i + 1][1])
        {
            temp1 = stack[i][1];
            stack[i][1] = stack[i + 1][1];
            stack[i + 1][1] = temp1;

            for (int j = i+1; j < rows-1; j++)
            {
                stack[j][0] = stack[j+1][0];
                stack[j][1] = stack[j+1][1];
            }
            rows--;
            i--;
        }
        else if(stack[i][1] > stack[i + 1][0] && stack[i][1] > stack[i + 1][1])
        {
            for (int j = i+1; j < rows-1; j++)
            {
                stack[j][0] = stack[j+1][0];
                stack[j][1] = stack[j+1][1];
            }
            rows--;
            i--;
        }
    }

    printf("\n{ ");
    for (int i = 0; i < rows; i++)
    {
        printf("{%d,%d}, ", stack[i][0], stack[i][1]);
    }
    printf("\b\b }\n");

    free(stack);
}

// {{6,8},{1,9},{2,4},{4,7}}
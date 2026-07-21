#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int checkStr_a_b(char str[]);

int main()
{
    char str[20];
    printf("Enter String in the form a^i b^i where i>=1: ");
    scanf("%s", str);

    if (checkStr_a_b == 1)
    {
        printf("No. of 'a' is equal to 'b'. ('_')");
    }

    else{
        printf("No. of 'a' is NOT equal to 'b'! ('.')");
    }    

    return 0;
}

int checkStr_a_b(char str[])
{
    int len = strlen(str);

    int top_1 = -1;
    char *stack_1 = (char *)malloc(sizeof(char) * (len / 2));

    int top_2 = -1;
    char *stack_2 = (char *)malloc(sizeof(char) * (len / 2));

    for (int i = 0;str[i] != '\0'; i++)
    {
        if (str[i] == 'a')
        {
            if (top_1 >= len)
            {
                printf("Stack Overflow!");
                return 0;
            }
            else
            {
                stack_1[++top_1] = 'a';
            }
        }
        else
        {
            if (top_2 >= len)
            {
                printf("Stack Overflow!");
                return 0;
            }
            else
            {
                stack_2[++top_2] = 'b';
            }
        }
    }

    if (top_1 == -1 && top_2 == -1)
    {
        return 0;
    }
    else if (top_1 == top_2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int top = -1;
char *stack;
int size;

int recognizeString(char str[]);

void pushChar(char c);

char popChar();

int main()
{

    stack = (char *)malloc(sizeof(char) * 10);

    char str[20];
    printf("Enter String: ");
    scanf("%s", str);

    if (recognizeString(str) == 1)
    {
        printf("\nRecognized!\n");
    }
    else
    {
        printf("Rejected!");
    }

    free(stack);

    return 0;
}

int recognizeString(char str[])
{
    int len = strlen(str);
    size = len;

    for (int i = 0; i < len / 2; i++)
    {
        pushChar(str[i]);
    }

    if (len % 2 == 0)
    {
        for (int i = len / 2; i < len; i++)
        {
            if (popChar() != str[i])
            {
                return 0;
            }
        }
    }
    else
    {
        for (int i = len / 2 + 1; i < len; i++)
        {
            if (popChar() != str[i])
            {
                return 0;
            }
        }
    }

    return 1;
}

void pushChar(char c)
{
    if (top >= size - 1)
    {
        printf("Stack Overflow!");
        return;
    }
    else
    {
        stack[++top] = c;
    }
}

char popChar()
{
    if (top < 0)
    {
        printf("Stack Underflow!");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}
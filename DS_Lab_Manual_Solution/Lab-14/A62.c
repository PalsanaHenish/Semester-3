#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int top = -1;
char *stack;

void removeStars(char str[]);

void PUSH(int x);

char POP();

int main()
{
    stack = (char *)malloc(sizeof(char) * 20);

    char str[20];
    printf("Enter String Containing stars: ");
    scanf("%s", str);

    removeStars(str);

    return 0;
}

void removeStars(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '*')
        {
            POP();
        }
        else
        {
            PUSH(str[i]);
        }
    }

    if (top != -1)
    {
        int len = top + 2;
        char res[len];
        for (int i = len - 2; i >= 0; i--)
        {
            res[i] = POP();
        }
        res[len-1] = '\0';
        printf("Result : %s", res);
    }
    else
    {
        printf("Empty String...!");
    }
}

void PUSH(int x)
{
    stack[++top] = x;
}

char POP()
{
    if (top < 0)
    {
        printf("Stack Underflow!");
        return '\0';
    }
    return stack[top--];
}
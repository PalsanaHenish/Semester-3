#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int top = -1;
char *stack;

int Braces_Validity(char str[]);

void PUSH(int x);

char POP();

int main()
{
    stack = (char *)malloc(sizeof(char) * 20);

    char str[20];
    printf("Enter String Only Containing Brackets: ");
    scanf("%s",str);

    if (Braces_Validity(str))
    {
        printf("Valid...('_')");
    }
    else
    {
        printf("Invalid...!");
    }

    return 0;
}

int Braces_Validity(char str[])
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            PUSH(str[i]);
        }
        else if ((stack[top] == '[' && str[i] == ']') || (stack[top] == '{' && str[i] == '}') || (stack[top] == '(' && str[i] == ')'))
        {
            POP();
        }
        else
        {
            return 0;
        }
    }

    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
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
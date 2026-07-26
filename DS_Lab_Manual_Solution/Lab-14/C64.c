#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int top = -1;
char *stack;

void vowelAnxiety(char str[]);

void PUSH(int x);

char POP();

int main()
{
    stack = (char *)malloc(sizeof(char) * 20);

    char str[20];
    printf("Enter String: ");
    scanf("%s", str);

    vowelAnxiety(str);

    return 0;
}

void vowelAnxiety(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            char t[20];
            int len = top;
            for (int i = 0; i <= len; i++)
            {
                t[i] = POP();
            }
            for (int i = 0; i <= len; i++)
            {
                PUSH(t[i]);
            }
            PUSH(str[i]);
        }
        else
        {
            PUSH(str[i]);
        }
    }

    int len = top + 2;
    char res[len];
    for (int i = len - 2; i >= 0; i--)
    {
        res[i] = POP();
    }
    res[len-1] = '\0';
    printf("Result : %s", res);
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

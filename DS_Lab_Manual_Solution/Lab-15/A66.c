#include "stdio.h"
#include "string.h"

int top = -1;
char stack[20];
char polish[30];
int rank = 0;

void infixToPrefix(char expression[]);

int inputPrecedence(char c);

int stackPrecedence(char c);

int rankSymbol(char c);

void PUSH(char c);

char POP();

int main()
{
    char expression[30];
    printf("Enter Infix Expression: ");
    scanf("%s", expression);

    infixToPostfix(expression);

    return 0;
}

void infixToPrefix(char expression[])
{

    strrev(expression);
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if(expression[i] == ')'){
            expression[i] = '(';
        }
        else if(expression[i] == '('){
            expression[i] = ')';
        }
    }

    strcat(expression,")");

    top = 0;
    stack[top] = '(';
    char next = expression[0];
    int i = 0;
    int j = 0;

    while (next != '\0')
    {
        if (top < 0)
        {
            printf("\nInvalid...!1\n");
            return;
        }

        while (stackPrecedence(stack[top]) > inputPrecedence(next))
        {
            char temp = POP();
            polish[j++] = temp;
            rank = rank + rankSymbol(temp);
            if (rank < 1)
            {
                printf("\nInvalid...!2\n");
                return;
            }
        }

        if (stackPrecedence(stack[top]) != inputPrecedence(next))
        {
            PUSH(next);
        }
        else
        {
            POP();
        }
        next = expression[++i];
    }

    strrev(polish);

    if (top != -1 || rank != 1)
    {
        printf("\nInvalid...!3\n");
    }
    else
    {
        printf("\n Polish : %s\n", polish);
    }
}

int inputPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;

    case '*':
    case '/':
        return 4;

    case '^':
        return 5;

    case '(':
        return 9;

    case ')':
        return 0;

    default:
        return 7;
    }
}

int stackPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 3;

    case '^':
        return 6;

    case '(':
        return 0;

    default:
        return 8;
    }
}

int rankSymbol(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return 1;
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void PUSH(char c)
{
    stack[++top] = c;
}

char POP()
{
    if (top < 0)
    {
        printf("\nStack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}
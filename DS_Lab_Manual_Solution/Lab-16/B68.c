#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int top = -1;
int stack[20];

int evaluateExpression(char expression[]);
void PUSH(int x);
int POP();
int PerformOperation(char c);

int main()
{
    char expression[30];
    printf("Enter Expression (comma separated): ");
    scanf("%s", expression);

    int ans = evaluateExpression(expression);

    printf("\nAns = %d\n", ans);

    return 0;
}

int evaluateExpression(char expression[])
{
    int num = 0;
    int len = strlen(expression);
    int temp = 1;


    for (int i = len-1; i >= 0; i--)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            num = num + (expression[i] - '0')*temp;
            temp *= 10;
        }
        else if (expression[i] == ',')
        {
            temp = 1;
            if (expression[i + 1] >= '0' && expression[i + 1] <= '9')
            {
                PUSH(num);
                num = 0;
            }
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
        {
            PUSH(PerformOperation(expression[i]));
        }
    }

    return stack[top];
}

void PUSH(int x)
{
    stack[++top] = x;
}

int POP()
{
    if (top <= -1)
    {
        printf("\nStack Underflow!\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int PerformOperation(char c)
{
    int op_1 = POP();
    int op_2 = POP();

    switch (c)
    {
    case '+':
        return op_1 + op_2;
    case '-':
        return op_1 - op_2;
    case '*':
        return op_1 * op_2;
    case '/':
        if (op_2 == 0)
        {
            printf("\nError: Division by zero!\n");
            exit(1);
        }
        return op_1 / op_2;
    case '^':
        return pow(op_1, op_2);
    default:
        printf("Invalid operator");
        return 0;
    }
}
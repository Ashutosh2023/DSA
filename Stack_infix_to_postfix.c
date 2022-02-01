#include<stdio.h>

int top = -1;
char stack[20];
void push(char);
char pop(void);
int priority(char);

int main()
{
    char infix[20], item;
    int i = 0;
    printf("Enter the infix expression:");
    gets(infix);
    printf("The postfix Expression is:");

    while(infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(stack[top] != '(')
            {
                item = pop();
                printf("%c",item);
            }
            top--;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^')
        {
            while( priority(infix[i]) <= priority(stack[top]))
            {
                item = pop();
                printf("%c",item);
            }
            push(infix[i]);
        }
        else
        {
            printf("%c",infix[i]);
        }
        i++;
    }
    while (top != -1)
    {
        printf("%c", stack[top]);
        top--;
    }
}

void push(char c)
{
    top++;
    stack[top] = c;  
}

char pop()
{
    char x;
    x = stack[top];
    top--;
    return x;
}

int priority(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
        return (-1);
}
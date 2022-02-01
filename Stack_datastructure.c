#include<stdio.h>

int stack[100],choice,n,top;

void push(void);
void pop(void);
void peek(void);
void display(void);

int main()
{
    top = -1;
    printf("Enter the size of the stack:");
    scanf("%d", &n);
    
    do
    {
        printf("\n************\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n***********\n");
        printf("\nEnter you choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nexit");
                break;
            default:
                printf ("\n Please Enter a Valid Choice( from:1 to 4)");
                break;
        }
    } 
    while (choice != 5);
    return 0;
}

void push()
{
    int x;
    printf("Enter data:");
    scanf("%d",&x);
    if (top >= n-1)
        printf("overflow condition\n");
    else
    {
        top++;
        stack[top] = x;
    }  
}

void pop()
{
    if (top < 0)
        printf("Stack underflow condition\n");
    else
    {
        printf("\tThe popped element is:%d", stack[top]);
        top--;
    }
}

void peek()
{
    if (top < 0)
        printf("Stack underflow condition\n");
    else
        printf("\tThe top element is:%d", stack[top]);
}

void display()
{
    int i;
    if (top < 0)
        printf("stack underflow condition");
    else
    {
        for(i=top; i>=0; i--)
            printf("%d\n",stack[i]);
    }
}
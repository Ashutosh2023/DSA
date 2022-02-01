#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node *top = NULL;
struct node *push(int);
void pop(void);
void peek (void);
void display (void);

int main()
{
    int choice, data;
    do
    {
        printf("\n**********************\n\t1.push\n\t2.pop\n\t3.peek\n\t4.display\n\t5.exit\n**********************\n");
        printf("\nEnter you choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("\tEnter the data:");
                scanf("%d",&data);
                top = push(data);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                printf("\nexit");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice( from:1 to 4)");
            }
        }
    } while (choice != 5);
    return 0;
}

struct node *push(int data)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    
    if(top == NULL)
    {
        newnode->link = NULL;
        top = newnode;
    }
    else
    {
        newnode->link = top;
        top = newnode;
    }
    return top;
}

void pop()
{
    struct node *ptr = NULL;
    if(top == NULL)
        printf("\n\tUnderFlow condition");
    else
    {
        ptr = top;
        top = top->link;   
    }
    printf("\n\tThe popped Element is:%d", ptr->data);
    free (ptr);
}

void peek()
{
    if(top == NULL)
        printf("UnderFlow condition");
    else
    {
        printf("\n\tThe top element is : %d", top->data);
    }  
}

void display()
{
    struct node *ptr = top;
    if(top == NULL)
        printf("Underflow condition");
    else
    {
        while(ptr != NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->link;
        }
    }
}
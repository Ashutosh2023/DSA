#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
} *Front, *Rear;

void enqueue(int);
void dequeue();
void peek();
void display();

int main()
{
    int x, choice;
    Front = Rear = NULL;
    do
    {
        printf("\n************\n1.Enqueue\n2.Dequeue\n3.peek\n4.display\n5.exit\n***********\n");
        printf("Enter you choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("\tEnter data:");
                scanf("%d", &x);
                enqueue(x);
                break;
            }
            case 2:
            {
                dequeue();
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
                printf("\nBye Bye!!");
                break;
            }
            default:
            {
                printf ("\nPlease Enter a Valid Choice(i.e 1 to 4)");
            }
        }
    } 
    while (choice != 5);
    return 0;
}

void enqueue(int data)
{
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    if(Front == NULL && Rear == NULL)
        Front = Rear = newnode;
    else
    {
        Rear->link = newnode;
        Rear = Rear->link;
        Rear->link = Front;
    }
}

void dequeue()
{
    struct node *temp;
    if(Front == NULL)
    {
        printf("UnderFlow Condition");
    }
    else
    {
        temp = Front;
        printf("The dequeued data is: %d", Front->data);
        if (Front == Rear)
        {
            free(temp);
            temp = NULL;
            Front = Rear = NULL;
        }
        else
        {
            Front = Front->link;
            Rear->link = Front;
            free(temp);
            temp = NULL;
        }
    }
}

void peek()
{
    if (Front == NULL)
        printf("The Queue is empty.");
    else
        printf("The data at the Front is: %d", Front->data);
}

void display()
{
    struct node *ptr = Front;
    if (Front == NULL)
        printf("The Queue is empty.");
    else
    {   do
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        while(ptr != Front);
    }
}

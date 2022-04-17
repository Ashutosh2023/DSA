#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
} *Front, *Rear;

void Enqueue(int);
void Dequeue();
void Peek();
void Display();

int main()
{
    int val, choice;
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
                scanf("%d", &val);
                Enqueue(val);
                break;
            }
            case 2:
            {
                Dequeue();
                break;
            }
            case 3:
            {
                Peek();
                break;
            }
            case 4:
            {
                Display();
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

void Enqueue(int val)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->link = NULL;   
    if(Front == NULL && Rear == NULL)
    {
        Front = Rear = newnode;
    }
    else
    {
        Rear->link = newnode;
        Rear = Rear->link;
    }
}

void Dequeue()
{
    struct node *ptr = Front;

    if(Front == NULL)
    {
        printf("UnderFlow Condition");
    }
    else
    {
        printf("The data dequeued is:%d", Front->data);
        Front = Front->link;
        free(ptr);
        ptr = NULL;
    }
}

void Peek()
{
    if(Front == NULL)
        printf("The Queue is empty.");
    else
        printf("The Front data is:%d", Front->data);
}

void Display()
{
    if(Front == NULL)
        printf("The Queue is empty.");
    else
    {
        struct node *ptr = Front;
        while(ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }   
}
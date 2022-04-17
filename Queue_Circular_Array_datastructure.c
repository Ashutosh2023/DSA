#include<stdio.h>
#include<stdlib.h>
//#define MAX 100
int queue[100];
int Front = -1, Rear = -1, n;

void Enqueue(int);
void Dequeue(void);
void peek(void);
void display(void);
int main()
{
    int x, choice;
    printf("Enter the size of the Queue you prefer:");
    scanf("%d", &n);
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
                Enqueue(x);
                break;
            }
            case 2:
            {
                Dequeue();
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

void Enqueue(int x)
{
    if((Rear+1)%n == Front)
        printf("\tOverFlow condition");

    else if(Front == -1 && Rear == -1)
    {
        Front = Rear = 0;
        queue[Rear] = x;
    } 
    else if(Rear == n-1)
    {
        Rear = 0;
        queue[Rear] = x;
    }   
    else
    {
        Rear++;
        queue[Rear] = x;
    }
}

void Dequeue()
{
    if(Front == -1 && Rear == -1)
        printf("\tUnderFlow Condition");

    else if(Front == n-1)
    {
        printf("\t\tThe Dequeued data is:%d",queue[Front]);
        if (Front == Rear)
            Front = Rear = -1;
        else
            Front = 0;
    }
    else
    {
        printf("\t\tThe Dequeued data is:%d",queue[Front]);
        if (Front == Rear)
            Front = Rear = -1;
        else
            Front++;
    }
}

void peek()
{
    if(Front == -1 && Rear == -1)
        printf("\tThe queue is empty");  
    else
        printf("\tThe Front element is: %d", queue[Front]);
}

void display()
{
    int i;
    if (Front == -1 && Rear == -1)
        printf ("\n QUEUE IS EMPTY");
    else
    {
        if(Front < Rear)
            for(i = Front; i <= Rear; i++)
            {
                printf("%d\t", queue[i]); 
            }
        
        else if(Front == Rear)
        {
            printf("%d\t", queue[Front]);
        }
        else 
        {
            for(i = Front; i <= n-1; i++)
                printf("%d\t", queue[i]);
            for(i = 0; i <= Rear; i++)
                printf("%d\t", queue[i]);         
        }
    }
}

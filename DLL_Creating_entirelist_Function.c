#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
//Function for creating a node for the empty list.
struct node* CreateNode(struct node *head, int data)
{
    struct node *temp = (struct node *) malloc( sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
//Fuction for adding a node at the End of DLL.
struct node* addAtend(struct node *head, int data)
{
    if (head == NULL)
        printf("linked list doesn't exist.");
    else 
    {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;
        struct node *ptr;
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
        return head;
    }
}
//Function for creating an entire list.
struct node* CreateList(struct node *head)
{
    int n, data, i;
    printf("Enter the number of nodes you want to insert in the list: ");
    scanf("%d", &n);

    if(n==0)
        return head;
    printf("Enter the element to be inserted at node 1: ");
    scanf("%d", &data);
    head = CreateNode(head, data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted at node %d: ", i);
        scanf("%d", &data);
        head = addAtend(head, data);
    }
    return head;
}
int main ()
{
    struct node *head = NULL;
    head = CreateList(head);

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
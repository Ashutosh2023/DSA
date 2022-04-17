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
//Function for print the doubly linked list.
void printDLL(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
//Function for the deletion of the first node of the list.
struct node* delFirst(struct node *head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}
//Function for the deletion of the last node of the list.
struct node* delLast(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    temp = NULL;
    return head;
}
//Function for the deletion of an intermediate node of the list.
struct node* delInter(struct node *head, int pos)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    if (pos == 1)
    {
        delFirst(head);
        exit(0);
    }
    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
        head = delLast(head);
    else
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free (temp);
        temp = NULL;
    }
    return head;
}
int main ()
{
    int pos;
    struct node *head = NULL;
    head = CreateList(head);

    printf("The list Before deletion : \n");
    printDLL (head);

    printf("The list after deletion of the first node : \n");
    head = delFirst (head);
    printDLL(head);

    printf("The list after deletion of the last node : \n");
    head = delLast (head);
    printDLL(head);

    printf("The the position of the node you want to delete:");
    scanf("%d", &pos);
    printf("The list after deletion of node at postion %d : \n", pos);
    head = delInter (head, pos);
    printDLL(head);

    return 0;
}
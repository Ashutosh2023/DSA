#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};
//Fuction for adding a node at beggining of the DLL.
struct node* addAtbeg(struct node *head, int data)
{
    if (head==NULL)
        printf("linked list doesn't exist.");
    else {
        struct node *temp = (struct node* ) malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
}
//Fuction for adding a node at the End of DLL.
struct node* addAtend(struct node *head, int data)
{
    if (head==NULL)
        printf("linked list doesn't exist.");
    else {
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
//Function to insert a certain node after any position in DLL.
struct node* addAfterPos(struct node *head, int data, int pos)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    struct node *newN = (struct node*) malloc(sizeof (struct node));
    newN->prev = NULL;
    newN->data = data;
    newN->next = NULL;
    
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        addAtend(head, data);           ///I have commented these lines of code because idk why but the program doesn't
    }                                   ///print anything after including these lines of code.
    else
    {
        temp2 = temp->next;
        temp->next = newN;
        temp2->prev = newN;
        newN->prev = temp;
        newN->next = temp2;
        return head;
    }
}

int main()
{
	struct node *head = (struct node *) malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 34;
    head->next = NULL;
    int pos = 2;
    head = addAtbeg (head, 45);
    head = addAtend (head, 56);
    head = addAfterPos(head, 67, pos);

    struct node *ptr = head;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    return 0;
}

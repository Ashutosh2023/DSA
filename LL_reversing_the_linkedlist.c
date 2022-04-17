#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* add_at_end (struct node *ptr, int data)
{
    if (ptr==NULL)
        printf("Empty List.");
    else
    {
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;

        ptr->link = temp;
        return temp;
    }   
}
//This function is the ITERATIVE method for reversing a linked list.
struct node* reverse_linkedlist (struct node *current)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL){ 
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}
//This function is the RECURSIVE method for reversing a linked list.
struct node *head;
struct node* reverse_recursive (struct node *prev, struct node* curr)
{
    if (curr)
    {
        reverse_recursive (curr, curr->link);
        curr->link = prev;
    }
    else
        head = prev;
    return head; 
}
int main(){
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = 4;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 9);
    ptr = add_at_end(ptr, 6);
    ptr = add_at_end(ptr, 3);
    ptr = add_at_end(ptr, 1);
    ptr = add_at_end(ptr, 7);

    printf("The original list is:");
    ptr = head;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }

    printf("\nThe reversed list is:");
    //head = reverse_linkedlist(head);
    head = reverse_recursive(NULL, head);
    ptr = head;
    while (ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
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

struct node* del_entire_linkedlist (struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free (head);
        head = temp;
    }
    return head;
}

int main(){
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 98);
    ptr = add_at_end(ptr, 56);
    ptr = add_at_end(ptr, 37);

    head = del_entire_linkedlist (head);

    if(head == NULL)
        printf("Entire linked list is deleted successfully.");
    else
    {
        while (ptr != NULL){
            printf("%d\n",ptr->data);
            ptr = ptr->link;
        }
    }  
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_at_beginning(struct node *head, int d){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;

    temp->link = head;
    return temp;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof (struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 23;
    ptr->link = NULL;

    head->link = ptr;

    int d=3;
    head = add_at_beginning(head, d);
    d=3456;
    head = add_at_beginning(head, d);

    ptr = head;
    while (ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
}
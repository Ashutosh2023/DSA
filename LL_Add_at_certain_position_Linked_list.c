#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void add_at_pos (struct node *head, int data, int pos)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    struct node *ptr = head;
    while (pos!=2){
    ptr = ptr->link;
    pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

int main()
{
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = 34;
    head->link = NULL;
    
    struct node *current = (struct node*) malloc (sizeof(struct node));
    current->data = 45;
    current->link = NULL;
    head->link = current;

    current =  (struct node*) malloc(sizeof(struct node));
    current->data = 78;
    current->link = NULL;
    head->link->link = current;

    int data=5567, pos=3;
    add_at_pos(head, data, pos);

    struct node *ptr = head;
    while (ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }   
}
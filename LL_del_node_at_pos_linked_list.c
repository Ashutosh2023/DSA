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

void del_at_pos (struct node **head, int pos)
{
    struct node *temp = *head;
        struct node *temp2 = *head;
    if(*head == NULL)
        printf("List is empty.");
    else if(pos == 1){
            *head = temp->link;
            free(temp);
            temp = NULL;
    }
    else {
        while(pos != 1){
            temp2 = temp;
            temp = temp->link;
            pos--;
        }
        temp2->link = temp->link;
        free(temp);
        temp = NULL;
    }    
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

    int pos = 1;
    del_at_pos (&head, pos);

    ptr = head;
    while (ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
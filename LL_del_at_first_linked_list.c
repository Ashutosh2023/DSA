#include <stdio.h>
#include <stdlib.h>

struct node{
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
struct node* del_at_beg (struct node *head){
    if(head == NULL)
        printf("The linked list is empty.\n");
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
     
}
void del_at_end (struct node *head){
    if(head == NULL)
        printf("The Linked list is empty.\n");
    else if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
    else
        {
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp->link != NULL)
            {
                temp2 = temp;
                temp = temp->link;
            }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
        }
}
int main()
{
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 9);
    ptr = add_at_end(ptr, 6);
    ptr = add_at_end(ptr, 7);
    ptr = add_at_end(ptr, 5);
    ptr = add_at_end(ptr, 3);

    head = del_at_beg(head);
    del_at_end(head);
    
    ptr = head;
    while (ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
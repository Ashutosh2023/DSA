#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
///Fuction to count the nodes in the linked list.
void count_of_nodes (struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("linked list doesn't exist.");
    else {
        struct node *ptr = head;
        while (ptr != NULL){ 
            count++;
            ptr = ptr->link;
        }
        printf("Given Linked List contains %d Nodes.\n\n",count);
        }
}
///Fuction for traversal of the linked list.
void print (struct node *head){
    if (head==NULL)
        printf("Linked list doesn't exist.");
    else {
        struct node *ptr = head;
        while (ptr != NULL){
            printf("%d\n",ptr->data);
            ptr = ptr->link;
        }
    }
}
///Fuction to do a search for a given value in linked list.
void search (struct node *head, int n){
    if (head == NULL)
        printf("The LInked List doesnot exist.");
    else {
        struct node *pos = NULL;
        int i=0;
        struct node *ptr = head;
        while (ptr != NULL){
            if (ptr->data == n){
                pos = ptr;
                break;
            }
            else 
                ptr = ptr->link;
            i++;
        }
        if (pos == NULL)
            printf("\nThe seeked value is not in the Linked list.\n");
        else
            printf("\nThe value is at node: %d.\n",i+1);   //you can also print the adress of the element where it's located.
    }
}
///Function to insert a node at the end of the list.
void add_at_end (struct node *head, int data){
    if (head==NULL)
        printf("Linked list doesn't exist.");
    else {
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*) malloc (sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL)
        ptr = ptr->link;
    
    ptr->link = temp;
    }
}

int main()
{
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node*) malloc(sizeof(struct node));
    current->data = 55;
    current->link = NULL;
    head->link = current;

    current = (struct node*) malloc(sizeof(struct node));
    current->data = 65;
    current->link = NULL;
    head->link->link = current;

    count_of_nodes(head);
    print(head);
    search(head,55);
    printf("\nThe new list is:\n");
    add_at_end(head, 75);
    print(head);

    return 0;
}

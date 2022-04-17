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

void print (struct node *ptr)               //void print (struct node *ptr)
{                                           //{
    if(ptr != NULL)                         //    if(ptr != NULL)
    {                              //or,    //    {        
        print (ptr->link);                  //        printf("%d\t",ptr->data);                   This function is also the recursive method the there is a difference int the code and stack arrangement.
        printf("%d\t",ptr->data);           //        print (ptr->link);                            as a result of which the output of thi s funciton display is in reverse.
    }                                       //    }
}                                           //}
int main()
{
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 98);
    ptr = add_at_end(ptr, 56);
    ptr = add_at_end(ptr, 37);

    ptr = head;
    while (ptr != NULL){
        printf("%d\n",ptr->data);      //This is the itterative method of printing a list.
        ptr = ptr->link;
    }
    //print(ptr);                           //Printing the list through recursive method.
    return 0;
}
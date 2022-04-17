#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node*next;
};
struct node *head,*new_node,*temp;
int count;
void create_node();
void insert_end();
void insert_beginning();
void display();
void insert_in_between();

void main(){
int c;
head=NULL;
do{
      printf("\nOperations\n");
      printf("1-create node\n");
      printf("2-insert  node at the end \n");
      printf("3-insert node at the beginning\n");
      printf("4-Insert in between\n");
      printf("5-Display the elements\n");
      printf("6-exit\n");
     
      printf("\nEnter the operation u want to perform\n");
      scanf("%d",&c);
        switch(c)
        {
            case 1:
            create_node();
            break;
            case 2:
            insert_end()  ;
            break;
            case 3:
            insert_beginning();
		      break;
            case 4:
            insert_in_between();
            break;
            case 5:
            display();
            break;
            case 6:
            printf("EXIT\n");
            exit(1);
            default:
              {
                  printf("Oops operation invalid!\n Enter a valid operation\n");
              }
        }
   }
while(1);
}
void create_node()
     {
      new_node=(struct node*)malloc(sizeof(struct node));
      printf("Enter the value\n");
      scanf("%d",&new_node->data);
      if(head==NULL)
         temp=head=new_node;
      else
          temp->next=new_node;
          temp=new_node;
         // new_node->next=NULL;
     }


void insert_end()
{
new_node=(struct node*)malloc(sizeof(struct node));
printf("Enter the number u want to insert at the end of linked list\n");
scanf("%d",&new_node->data);
new_node->next=NULL;
   temp=head;
while(temp->next!=NULL)
   {
      temp=temp->next;
   }
   temp->next=new_node;
}

void  insert_beginning()
{
new_node=(struct node*)malloc(sizeof(struct node));
printf("Enter the number u want to insert at the beginning of the linked list\n");
scanf("%d",&new_node->data);

new_node->next=head;
head=new_node;
}

void display()
{
count=0;
temp=head;
while(temp!=NULL)
   {
   printf("\n Linked list data is %d",temp->data);
   temp=temp->next;
   count++;
    }
printf("\nNo. of nodes present in the linked list is %d",count);
}

void insert_in_between()
{
int position,i;
new_node=(struct node*)malloc(sizeof(struct node));
printf("Enter the number u want to insert in between  the linked list\n");
scanf("%d",&new_node->data);
printf("Enter the position where u want to insert the element\n");
scanf("%d",&position);
if(position>count)
      printf("\nInsertion not possible \n EXIT !");
else
      {
       temp=head;
       while(i<position-1){
                temp=temp->next;
                i++;
                }
       new_node->next=temp->next;
       temp->next=new_node;
       }
}

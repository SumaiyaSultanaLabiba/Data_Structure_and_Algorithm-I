#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int node_value;
    struct Node* next_node;
}Node;


Node* create_first_node(Node* head, int n)
{
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->node_value=n;
    new_node->next_node=NULL;
    head=new_node;
    return head;
}



void search_in_list(Node* head, int n)
{
  Node* cur;
  cur=head;
  int flag=0, position=0;
  while(cur!=NULL)
  {
    if(cur->node_value==n)  
    {
        printf("Found at %dth position\n", position);
        flag=1;
        break;
    }

    else 
    {position++;
    cur=cur->next_node;}
  }
  if(flag==0) printf("Not found.\n");
}



Node* insert_at_position(Node* head, int position, int value)
{
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->node_value=value;
    new_node->next_node=NULL;

    int current_position=0;
    Node* cur=head;
    for(current_position=0; current_position<position; current_position++)
    {
        cur=cur->next_node;
    }
    new_node->next_node=cur;
    cur=head;
    for(current_position=0; current_position<position-1; current_position++)
    {
        cur=cur->next_node;
    }
    cur->next_node=new_node;
    return head;
}



Node* delete_by_position(Node* head, int position)
{
    Node* cur=head;
    Node* prev=head;
    if(position==0) head=head->next_node;
    else if(head->next_node==NULL) 
    {
        for(int i=0; i<position-1; i++)
        {
            prev=prev->next_node;
        }
        prev->next_node=NULL;
    }
    else
    {
        for(int i=0; i<position-1; i++)
        {
            prev=prev->next_node;
        }

        for(int i=0; i<position; i++)
        {
            cur=cur->next_node;
        }
        prev->next_node=cur->next_node;
        free(cur);
    }
    return head;
}


Node* delete_by_value(Node* head, int value)
{
    Node* cur=head;
    int position=0;
    while(cur->node_value!=value)
    {
        cur=cur->next_node;
        position++;
    }
    head=delete_by_position(head, position);
    return head;
}


void print_list(Node* head)
{
  Node* cur;
  cur=head;
  while(cur!=NULL)
  {
    printf("%d  ", cur->node_value);
    cur=cur->next_node;
  }
  printf("\n");
}


void free_list(Node* head)
{
    Node* cur;
    Node* temp;
    cur=head;
    while(cur!=NULL)
    {
      temp=cur;
      free(cur);
      cur=temp->next_node;
    }
}


int main()
{
  Node* list;
  list=create_first_node(list, 204);
  print_list(list);
  search_in_list(list, 204);
  list=insert_at_position(list, 1, 2000);
  print_list(list);
  list=insert_at_position(list, 1, 500);
  print_list(list);
  list=delete_by_value(list, 2000);
  print_list(list);
  list=delete_by_position(list, 0);
  print_list(list);
  free_list(list);
  return 0;
}
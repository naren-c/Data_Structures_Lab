#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

node *head = NULL;
int no_of_elements = 0;

void insert_at_end(int d)
{
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = d;
  new_node->next = NULL;
  if(head == NULL)
  {
    head = new_node;
    printf("\nNode inserted successfully at front.\n");
    return;
  }
  else
  {
    node *temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = new_node;
    printf("\nNode inserted successfully.\n");
    return;
  }
}

void display()
{
  node *temp = head;
  if(temp != NULL)
  {
    printf("\n");
    while(temp != NULL)
	{
      printf("%d->",temp->data);
      temp = temp->next;
    }
    printf("NULL\n\n");
  }
  else printf("\nList is empty.\n");
}

void swap(int p1,int p2)
{
  if(no_of_elements-1<p1 || no_of_elements-1<p2)
  {
    printf("Not enough elements in linked list\n");
    return;
  }
  else if(p1==p2)
  {
    printf("Swapping node with itself\n");
    return;
  }
  else
  {
	  node* temp,*pos1,*pos2, *prev1,*prev2;
	  int counter = 0;
	  temp = head;
	  
	  while(temp->next!=NULL)
	  {
		  counter++;
		  if(p1 == counter)
			 pos1 = temp;
		  else if (p2 == counter)
			pos2 = temp;
		  else
			temp = temp->next;
	  }
	  temp = pos1;
	  pos1->next = pos2->next;
	  pos2->next = temp->next;
  }
  
  /*if(p1>p2)
  {
    int temp = p1;
    p1 = p2;
    p2 = temp;
  }
  node* first = head, *prev1 = NULL, *prev2 = NULL, *second = head, *temp;
  if(p2-p1 == 1)
  {
		while(p1)
		{
			prev1 = first;
			first = first->next;
			p1--;
		}
		second = first->next;
		temp = first;
		first->next = second ->next;
		second->next = first;
		if(prev1)
			prev1->next = second;
		else head = second;
			return;
  }
  else
  {
        while(p1)
		{
          prev1 = first;
          first = first->next;
          p1--;
        }
        while(p2)
		{
          prev2 = second;
          second = second->next;
          p2--;
        }
        temp = first->next;
        first->next = second->next;
        second->next = temp;
        if(prev1)
          prev1->next = second;
        else head = second;
        if(prev2)
          prev2->next = first;
        return;
  }*/
}

void delete_alternate()
{
  if(!head)
  {
    printf("List is empty.\n\n");
    return;
  }
  node *temp = (node*)malloc(sizeof(node)), *prev = NULL;
  temp = head;
  if(head->next)
  {
    head = head->next;
    free(temp);
    temp = head;
    while(temp->next != NULL)
	{
      prev = temp;
      temp = temp->next;
      prev->next = temp->next;
      free(temp);
      if(prev->next)
        temp = prev->next;
      else temp = prev;
    }
    printf("\nDeleted alternate nodes.\n");
    return;
  }
  else{ 
		head = NULL;
        free(temp);
        printf("\nDeleted alternate nodes.\n");
      }
}

int main()
{
  int choice, dt, p1, p2;;
  while(1)
  {
    printf("1.Insert new node\n2.Display\n3.Swap two nodes\n4.Delete alternate nodes\n5.Exit\n");
    scanf("%d",&choice);
    switch (choice)
	{
      case 1: printf("Enter the node data : ");
              scanf("%d",&dt);
              insert_at_end(dt);
              no_of_elements++;
              printf("\nno_of_elements : %d\n",no_of_elements);
              break;
      case 2: display();
              break;
      case 3: printf("Enter 2 node positions to swap: ");
              scanf("%d %d",&p1,&p2);
              swap(p1,p2);
              break;
      case 4: delete_alternate();
              break;
      case 5: exit(0);
              break;
      default : printf("Invalid choice.\n");
                break;

    }
  }
  return 0;
}

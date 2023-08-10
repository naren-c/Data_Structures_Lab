#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char  name[20], adress[10], area[10];
	long int phno;
	struct node *rlink;
	struct node *llink;
};
typedef struct node* NODE;
NODE first=NULL;
int count=0;
NODE createEmployeeNode()
{
	NODE employee;
	employee=(NODE)malloc(sizeof(struct node));
	if(employee==NULL)
	{
		printf("Out of Memory\n");
		exit(0);
	}
	employee->rlink=NULL;
	employee->llink=NULL;

	char  name[20], adress[10], area[10];
	long int phno;		
	printf("Enter Name: ");
	scanf("%s", name);
	printf("Enter adress: ");
	scanf("%s", adress);
	printf("Enter area: ");
	scanf("%s",area);
	printf("Enter Phone Number: ");
	scanf("%ld", &phno);
	strcpy(employee->name, name);
	strcpy(employee->adress, adress);
	strcpy(employee->area, area);
	employee->phno=phno;
	count++;
	return employee;
}	
NODE insert_end()
{
	NODE cur, temp;
	temp=createEmployeeNode();
	if(first==NULL)
	{
		return temp;
	}
	cur=first;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	cur->rlink=temp;
	temp->llink=cur;
	temp->rlink=NULL;
	return first;
}
void display()
{
	NODE cur;
	cur=first;	
	if(cur==NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		printf("The contents of the list are\n");
		while(cur!=NULL)
		{
			printf(" \nName: %s\nadress: %s\narea: %s\nPhone: %ld \n", cur->name, cur->adress, cur->area, cur->phno);
			cur=cur->rlink;
		}
		printf("\nThe number of users: %d",count);
	}
}	
void main()
{
	int ch,i,n;
	while(1)
	{
		printf("\t---Menu---\n");
		printf("1. Create list for telephone directory\n");
		printf("2. Insert at End\n");
		printf("3. Display the List\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the number of registers!\n");
					scanf("%d",&n);
					for(i=0; i<n; i++)
						first=insert_end();
					break;
			case 2: first=insert_end();
					break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default: printf("Invalid choice\n");
					 break;
		}
	}
}


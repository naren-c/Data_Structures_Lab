#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct contact
{
	char ssn[15];    
	char name[20];
    char dept[20];
    char desg[30];
    float salary;
	char phone[11];
	int age;
    struct contact *rlink;
    struct contact *llink;
} node;

node *start = NULL;
void insert();
void delete_age();
void display();
void dept_display();
void sub_dis(node *);
void main()
{
    int choice;
    do
    {
        printf("\nEnter Your choice:- \n1.Insert Employee Records \n2.Delete Data Whose age is above 58 years:- \n3.Display based on departments\n4.Display all Employee details\n");
        printf("Enter your choice: ");
		scanf("%d",&choice);
        switch (choice)
        {
			case 1 : insert(); 
					 break;
			case 2 : delete_age();
					 break;
			case 3 : dept_display();
					 break;
			case 4 : display();
					 break;
			case 5 : exit(0);
			default:  printf("Enter a valid response");
				   break;
        }
    } while (1);
    
}
void insert()
{
	node *temp=(node *)malloc(sizeof(node));
	if(temp==NULL)
		printf("\n===Memory Overflow===\n");
	else
	{
		printf("Enter SSN:- ");
		scanf("%s",temp->ssn);
		printf("Enter Name:- ");
		scanf("%s",temp->name);
		printf("Enter Dept:- ");
		scanf("%s",temp->dept);
		printf("Enter Designation:- ");
		scanf("%s",temp->desg);
		printf("Enter Salary:- ");
		scanf("%f",&(temp->salary));
		printf("Enter Phone No. :- ");
		scanf("%s",temp->phone);
		printf("Enter Age:- ");
		scanf("%d",&(temp->age));
		temp->rlink=NULL;
		temp->llink=NULL;
		if(start==NULL)
		{
			start=temp;
		}	
		else
		{
			node *trav=start;
			while(trav->rlink!=NULL)
			{
				trav=trav->rlink;
			}		
			temp->llink=trav;
			trav->rlink=temp;
		}
	}
}
void display()
{
    if(start==NULL)
        printf("The contact list is Empty");
    else
    {
        node *trav=start;
        while(trav!=NULL)
        {
            printf("\nSSN:- %s\nName:- %s\nDepartment:- %s\nDesignation:- %s\nSalary:- %0.2f\nPhone No.:- %s\nAge:- %d\n",trav->ssn,trav->name,trav->dept,trav->desg,trav->salary,trav->phone,trav->age);
	trav=trav->rlink;
        }
        printf("\nEnd of the List\n\n");
    }
}
void delete_age()
{
	int found;
	if(start==NULL)
		printf("The List is Empty\n");
	else
	{
		node *trav=start;
		while(trav!=NULL)
		{
			if(trav->age >= 58)
			{
				node *prev=trav->llink;
				node *temp=trav;
				if(prev!=NULL)
					prev->rlink=trav->rlink;
				if(trav->rlink!=NULL)
					trav->rlink->llink=prev;
				if(start==trav)
					start=trav->rlink;
				trav=trav->rlink;
				free(temp);
			}
			else
				trav=trav->rlink;
		}
	printf("Deleted all records of age above 58");
	}
}
void dept_display()
{
	char arr[20];
	printf("Enter the departments:- ");
	scanf("%s",arr);
	if(start==NULL)
		printf("The list is empty.");
	else
	{
		node *trav=start;
		int count=0;
		while(trav!=NULL)
		{
			if(strcmp(arr,trav->dept)==0)
			{			
				sub_dis(trav);
				trav=trav->rlink;
				count++;
			}
			else
				trav=trav->rlink;
							
		}
		if(count==0)
			printf("There No Employes in %s Department\n",arr);
		else
			printf("No of Employes Displayed is %d\n",count);	
	}
	printf("\nEnd of record");	
}
void sub_dis(node *trav)
{
	printf("\nSSN:- %s\nName:- %s\nDepartment:- %s\nDesignation:- %s\nSalary:- %0.2f\nPhone No.:- %s\nAge:- %d\n",trav->ssn,trav->name,trav->dept,trav->desg,trav->salary,trav->phone,trav->age);
}

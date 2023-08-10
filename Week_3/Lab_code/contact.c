#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct contact
{
    char name[20];
    char phone[11];
    char address[100];
    char area[30];
    struct contact *rlink;
    struct contact *llink;
} node;

node *start = NULL;
void insert();
void insert_front(node *);
void insert_rear(node *);
void insert_position(node *,node *);
void display();
int check(char *);
void main()
{
    int choice;
    while(1)
    {
        printf("Enter Your choice:- \n1.Insert New Contact \n2.Display directory based on name\n3.Exit\n");
		printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insert();   
				 break;
        case 2 : display();
				 break;
		case 3 : exit(0);		
				 break;
        default:  printf("Enter a valid response");
            break;
        }
    }   
}
void insert()
{
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
        printf("\n===Memory Overflow===\n");
    else
    {
        retry:
        printf("\nEnter Name:- ");
        scanf("%s",temp->name);
        if(check(temp->name))
        {
            printf("The name %s already exists in your contact list.\nPlease Enter a new name.",temp->name);
            goto retry;
        }
        printf("Enter Phone No.:- ");
        scanf("%s",temp->phone);
        printf("Enter Address:- ");
        scanf("%s",temp->address);
        printf("Enter Area:- ");
        scanf("%s",temp->area);
        temp->rlink=NULL;
        temp->llink=NULL;
        if(start==NULL || strcmp(start->name,temp->name)>0)
            insert_front(temp);
        else
        {
            node *trav=start;
            while(trav->rlink!=NULL && strcmp(temp->name,trav->rlink->name)>0)
                {
                    trav=trav->rlink;
                }
            if(trav->rlink==NULL)
                insert_rear(temp);
            else
                insert_position(trav,temp);
        }
    }
}
void insert_front(node *add)
{
	if(start==NULL)
	{
		start=add;
	}
	else
	{
		add->rlink=start;
		start->llink=add;
		start=add;
	}
}
void insert_rear(node *add)
{
	node *trav=start;
	while(trav->rlink!=NULL)
		{
			trav=trav->rlink;
		}
		add->llink=trav;
		trav->rlink=add;
}
void insert_position(node *after,node *add)
{
    add->rlink=after->rlink;
    add->llink=after;
    after->rlink->llink=add;
    after->rlink=add;
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
            printf("Name:- %s\nPhone No.:- %s\nAddress:- ",trav->name,trav->phone);
            puts(trav->address);
            printf("Area:- ");
            puts(trav->area);
            trav=trav->rlink;
        }
        printf("\nEnd of the List\n\n");
    }
}
int check(char *temp)
{
    int found=0;
    node *trav=start;
    while(trav!=NULL)
    {
        if(strcmp(trav->name,temp)==0)
        {
            found=1;
            break;
        }
        trav=trav->rlink;        
    }
    return found;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
 int key;
 long long int phone;
 char name[100];
 struct node *next;
};
struct hash
{
 struct node *head;
 int count;
};
void display(struct hash *, int);
void insert_to_hash(struct hash *,int,int, char *,long long int);
void delete_from_hash(struct hash*,int,int);
void search_in_hash(struct hash *ht,int size,int key);
int main()
{
 struct hash *hashtable;
 int i,n,ch,key;
 char name[100];
 long long int phone;
 int tablesz; 
 

 tablesz = 10;
 //create hash table
 hashtable=(struct hash*)(malloc(tablesz* sizeof(struct hash)));
 for(i=0;i<tablesz;i++)
 {
 hashtable[i].head=NULL;
 hashtable[i].count=0;
 }
 while(1)
 {
 printf("\n1. Enter the phone number");
 printf("\n2. Delete phone number");
 printf("\n3. Search phone number");
 printf("\n4. Display the table");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: printf("Enter the name\n");
 scanf("%s",name);
 printf("Enter the phone number\n");
 scanf("%lld",&phone);
 key = phone % 10;
 insert_to_hash(hashtable,tablesz,key,name,phone);
 break;
 case 2: printf("Enter the phone number for deletion\n");
 scanf("%lld",&phone);
 key = phone % 10;
 delete_from_hash(hashtable,tablesz,key);
 break;
 case 3: printf("Enter the key to search..\n");
 scanf("%lld",&phone);
 key = phone % 10;
 search_in_hash(hashtable,tablesz,key);
 break;
 case 4:display(hashtable,tablesz);break;
default:exit(0);
 }
 }
}
 
void delete_from_hash(struct hash * ht,int size,int key)
 {
struct node *temp,*prev;
int index;
index = key % size; // hash function
prev=NULL;
 temp=ht[index].head;
 
while((temp!=NULL)&&(temp->key!=key))
{prev=temp;
 temp=temp->next;
}
if(temp!=NULL)//key found
{
if(prev==NULL) // one node exists
 ht[index].head=temp->next;
else
 prev->next=temp->next;
 free(temp);
}
 else printf("Element not found..");
}
void insert_to_hash(struct hash *ht, int size, int key, char* name,long long int phone)
 {
 int index;
 struct node *temp;
 temp=(struct node*)(malloc(sizeof(struct node)));
 temp->key=key;
 strcpy(temp->name,name);
 temp->phone = phone;
 temp->next=NULL;
 
 index=key%size;
 temp->next=ht[index].head;
 ht[index].head=temp;
 ht[index].count++;
}
 
 
void display(struct hash* ht, int size)
{
 int i;
 struct node *temp;
 printf("\n");
 for(i=0;i<size;i++)
 {
 printf("%d : ",i);
 if(ht[i].head != NULL)
 {
 temp=ht[i].head;
 while(temp!=NULL)
 {
 
 printf("%s->",temp->name);
 printf("%lld ",temp->phone);
 temp=temp->next;
 }
 }
 printf("\n");
 } 
}
void search_in_hash(struct hash *ht,int sz,int key)
{
 int i,index;
 struct node *temp,*prev;
 
 index=key%sz;
 
 temp=ht[index].head;
 
 while((temp->key!=key)&&(temp!=NULL))
 temp=temp->next;
 
 if(temp!=NULL)
 {
 printf("\nRECORD FOUND....Details are...");
 printf("phone number: %lld ",temp->phone);
 printf("NAME : %s ",temp->name);
 }
 else 
 printf("RECORD NOT FOUND...");
}
#include<stdio.h>
#include<stdlib.h>

typedef struct Department
{
	char *name;
	int number;
} Department;
typedef struct Node
{
	char *ssn;
	char *name;
	Department *department;
	char *designations;
	int salary;
	int phone_number;
	int age;
	struct Node *next, *prev;
} NODE;

NODE* head = NULL;
void add_empval(head);

int main()
{
	add_empval(head);
}

void add_empval(NODE* head)
{
	
}
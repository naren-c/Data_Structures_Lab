#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char name[50];
	char date[20];
	char time[20];
	char case_name[30];
	struct node *next;
} Node;

typedef struct queue
{
	Node *front, *rear;
	int size;
} Queue;

Queue *queue_initialise();
void enqueue(Queue* q, char *name, char *case_name, char *date, char *time);
Node *create_node(char *name, char *case_name, char *date, char *time);
void display(Queue *);
void dequeue(Queue *);
int main()
{
	int choice;
	Queue *queue = queue_initialise();
	printf("Lawyer's Office\n");
	do 
	{
		printf("1. Make an appointment\n");
		printf("2. Delete appointment\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch (choice) 
		{
			char name[5], date[20], time[20], case_name[30];
			case 1:
			{
				if (queue->size == 3) printf("No more slots available \n");
				else
				{
					printf("Enter client name: ");
					scanf("%s", name);
					printf("Enter case name: ");
					scanf("%s", case_name);
					printf("Enter date: ");
					scanf("%s", date);
					printf("Enter time: ");
					scanf("%s", time);
					enqueue(queue, name, case_name, date, time);
				}
				break;
			}
			case 2: dequeue(queue);
					break;
			case 3:	display(queue);
					break;
			case 4: exit(0); 
		}
	} while (choice != 4);
	return 0;
}
void display(Queue *queue)
{
	Node *traverse = queue->front;
	if (traverse==NULL)
	{
		printf("No appointments\n");
		return;
	}
	while (traverse != NULL)
	{
		printf("%s\n", traverse->name);
		printf("%s\n", traverse->case_name);
		printf("%s\n", traverse->date);
		printf("%s\n", traverse->time);
		traverse = traverse->next;
		printf("\n");
	}
}
void enqueue(Queue* q, char *name, char *case_name, char *date, char *time)
{
	Node* new_node = create_node(name, case_name, date, time);
	if (q->front == NULL)
	{
		q->front = new_node;
		q->rear = new_node;
		++(q->size);
		return;
	}
	++(q->size);
	q->rear->next = new_node;
	q->rear = new_node;
}
void dequeue(Queue* q)
{
	Node *to_del;
	if (q->front == NULL)
	{
		printf("No appointments\n");
		return;
	}
	to_del = q->front;
	--q->size;
	q->front = q->front->next;
	free(to_del);
}
Node* create_node(char *name, char *case_name, char *date, char *time)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->next = NULL;
	strcpy(new_node->name,name);
	strcpy(new_node->case_name,case_name);
	strcpy(new_node->date,date);
	strcpy(new_node->time,time);
	return new_node;
}
Queue* queue_initialise() 
{
	Queue* new_queue = (Queue *) malloc(sizeof(Queue));
	new_queue->front = NULL;
	new_queue->rear = NULL;
	new_queue->size = 0;
	return new_queue;
}
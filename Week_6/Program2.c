#include <stdio.h> 
#include <stdlib.h>

typedef struct node 
{ 
	int data; struct node *next;
} Node;
typedef struct stack 
{ 
	Node *top;
} Stack;
typedef struct node1 
{ 
	int data; 
	struct node1 *next;
} Node_t;
typedef struct queue 
{ 
	Node_t *front, 
	*rear; int size;
} Queue;
void queue_destroy(Queue *); 
Queue *queue_initialise(); 
void enqueue(Queue *, int); 
Node_t *create_node_queue(int); 
void display_queue(Queue *); 
int dequeue(Queue *);
Stack* stack_initialise(); 
void stack_destroy(Stack *); 
Node* create_node(int);
void display(Stack *);
void push(Stack *, int); 
int pop(Stack *);
int peek(Stack *);

int main(int argc, char const *argv[]) 
{ 
	int choice; 
	Stack *stack = stack_initialise(); 
	Queue *queue = queue_initialise();
	int n = 8;
	push(stack, 1); 
	push(stack, 2); 
	push(stack, 3); 
	push(stack, 4); 
	push(stack, 5); 
	push(stack, 6); 
	push(stack, 7); 
	push(stack, 8);
	printf("\nStack: \n"); 
	display(stack);
	int data;
	for(int i = 0; i < n; i ++)
	{ 
		int is_empty = (stack->top == NULL); 
		if (!is_empty) 
		{ 
			data = pop(stack); 
			enqueue(queue, data); 
			printf("The element popped is %d\n", data);
		} 
		else 
		{ 
			printf("The stack is empty");
		} 
		display(stack);
	}
	printf("\n"); 
	printf("Queue: \n"); 
	display_queue(queue);
	int arr[n]; 
	for(int i = 0; i < n; i ++)
	{ 
		int ans = dequeue(queue); 
		printf("Removed: %d\n", ans); 
		arr[i] = ans; 
		display_queue(queue);
	}
	printf("\nArray: \n"); 
	for(int i = 0; i < n; i ++)
	{ 
		printf("%d ", arr[i]);
	} 
	stack_destroy(stack); 
	queue_destroy(queue); 
	return 0;
}
Node* create_node(int data) 
{ 
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = data; 
	return new_node;
}
Stack* stack_initialise() 
{ 
	Stack *stack = (Stack *) malloc(sizeof(Stack)); 
	stack->top = NULL; 
	return stack;
}
void stack_destroy(Stack *stack) 
{ 
	if (stack == NULL) 
	{ 
		return;
	} 
	if (stack->top == NULL) 
	{ 
		return;
	} 
	Node *traverse = stack->top, 
	*to_del = NULL;
	while (traverse->next != NULL) 
	{ 
		to_del = traverse; 
		traverse = traverse->next; 
		free(to_del);
	} 
	stack->top = NULL; 
	free(stack);
}
void push(Stack *stack, int data) 
{
	Node *new_node = create_node(data); 
	new_node->next = stack->top; 
	stack->top = new_node;
}
int pop(Stack *stack) 
{
	if (stack->top == NULL) 
	{ 
		return -1;
	}
	Node *to_del = stack->top; 
	int popped = to_del->data;
	stack->top = stack->top->next; 
	free(to_del); 
	return popped;
}
int peek(Stack *stack) 
{
	if (stack->top == NULL) 
	{ 
		return -1;
	} 
	return stack->top->data;
}
void display(Stack *stack) 
{ 
	Node *traverse = stack->top; 
	while (traverse != NULL) 
	{ 
		printf("%d->", traverse->data); 
		traverse = traverse->next;
	}
	printf("NULL\n");
}
void display_queue(Queue *queue) 
{ 
	Node_t *traverse = queue->front; 
	while (traverse != NULL) 
	{ 
		printf("%d->", traverse->data); 
		traverse = traverse->next;
	} 
	printf("NULL\n");
}
void enqueue(Queue* q, int data) 
{ 
	Node_t* new_node = create_node_queue(data); 
	if (q->front == NULL) 
	{ 
		q->front = new_node; 
		q->rear = new_node; 
		return;
	} 
	q->rear->next = new_node; 
	q->rear = new_node;
}
int dequeue(Queue* q) 
{ 
	Node_t *to_del; 
	int removed;
	if (q->front == NULL) 
		return -1;
	to_del = q->front; 
	q->front = q->front->next; 
	removed = to_del->data; 
	free(to_del); 
	return removed;
}
Node_t* create_node_queue(int data) 
{
	Node_t *new_node = (Node_t*) malloc(sizeof(Node_t));
	new_node->next = NULL; 
	new_node->data = data; 
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
void queue_destroy(Queue *queue) 
{ 
	if (queue == NULL) 
		return; 
	if (queue->front == NULL) 
		return;
	Node_t *traverse = queue->front,*to_del = NULL;
	while (traverse->next != NULL) 
	{ 
		to_del = traverse; traverse = traverse->next; 
		free(to_del);
	} 
	queue->front = NULL; 
	queue->rear = NULL; 
	free(queue);
}




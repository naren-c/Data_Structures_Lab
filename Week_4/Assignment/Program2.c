#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define QUEUESIZE 8

void carpark(int* queue , int* top , int* front,int e);
void cardepark(int* queue,int* top,int* front,int e);
void queuepop(int* queue,int* top , int* front);
void queuepeek(int* queue , int* top , int* front);
void queuedisplay(int* queue , int* top, int* front);

int main()
{
	int queue[QUEUESIZE];
	int top=-1,front=-1;
	printf("Enter number of operations :");
	int n;
	scanf("%d",&n);
	int t=0;
	while(t!=n)
	{
		t++;
		printf("Enter input [A/D LAST 4 DIGITS OF REGISTRATION]: ");
		char op;int num_plate;
		scanf("\t%c %i",&op,&num_plate);
		if(op=='A')
			carpark(queue,&top,&front,num_plate);
		else
			cardepark(queue,&top,&front,num_plate);
	}
}

void carpark(int* queue , int* top , int* front,int e)
{
	if(*top == QUEUESIZE-1)
	{
		printf("CAR %d Entry->Out![No space available]\n",e);
		return;
	}
	else if(*top==-1 && *front==-1)
	{
		*top=0;
		*front=0;
		*(queue+*top)=e;
		printf("CAR%d parked at back!.\n",*(queue+*top));
		printf("Parking order : \n");
		printf("Arrival Gate-i>");
		for(int i=*top;i>=*front;i--)
			printf("CAR %d->",*(queue+i));
		printf("Exit Gate\n");
		return;
	}
	else
	{
		*top=*top+1;
		*(queue+*top)=e;
		printf("CAR%d parked at back!.\n",*(queue+*top));
		printf("Parking order : \n");
		printf("Arrival Gate-i>");
		for(int i=*top;i>=*front;i--)
			printf("CAR %d->",*(queue+i));
		printf("Exit Gate\n");
		return;
	}
}
void cardepark(int* queue,int* top,int* front,int e)
{
	int present_flag=0;
	int i=0;
	for(i=*top;i>=*front;i--)
	{
		if(*(queue+i)==e)
		{
			present_flag=1;
			break;
		}
	}
	if(present_flag==0)
	{
		printf("There no car with such number!\n");
		return;
	}
	int copy=i;
	if(copy>*front)
	{
		printf("Cars to be moved to depark this car : \n");
		for(i=copy-1;i>=*front;i--)
			printf("CAR%d\n",*(queue+i));
		for(int j=copy;j>=*front-1;j--)
			*(queue+j)=*(queue+j-1);
		*front=*front+1;
		printf("Car deparked!\n");
		printf("Parking order : \n");
		printf("Arrival Gate-i>");
		for(int i=*top;i>=*front;i--)
		{
			printf("CAR %d->",*(queue+i));
		}
		printf("Exit Gate\n");
	}
	else
	{
		printf("No need to move any car to depark , CAR%d deparked!\n",e);
		queuepop(queue,top,front);
		printf("Parking order : \n");
		printf("Arrival Gate-i>");
		for(int i=*top;i>=*front;i--)
			printf("CAR %d->",*(queue+i));
		printf("Exit Gate\n");
	}
}
void queuepop(int* queue,int* top , int* front)
{
	if(*top==-1 && *front==-1)
	{
		printf("Queue Underflow!!!\n");
		return;
	}
	else if(*front == *top)
	{
		*top=-1;
		*front=-1;
		return;
	}
	else
	{
		*front=*front+1;
	}
}
void queuepeek(int* queue , int* top , int* front)
{
	printf("Front of queue : %d\n",*(queue+*front));
	printf("Top of queue : %d\n",*(queue+*top));
	return;
}
void queuedisplay(int* queue , int* top, int* front)
{
	int end=*top;
	printf("Start of queue ->");
	for(int i=*front;i<=end;i++)
		printf("%d ->",*(queue+i));
	printf("End of queue\n");
}
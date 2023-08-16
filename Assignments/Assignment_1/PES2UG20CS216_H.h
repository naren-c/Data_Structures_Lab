#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int sparse_matrix[10][10];
int sr,sc,er,ec;
typedef struct Node
{
	int value;
	int row_position;
	int column_postion;
	struct Node *link;
}NODE;
typedef struct Nodemove
{
	int row_position;
	int column_postion;
	struct Nodemove *rlink;
	struct Nodemove *llink;
}NODEM;
typedef struct list
{
    NODE *head;
}LIST;
typedef struct listmove
{
    NODEM *head;
}LISTM;
void initlist(LIST* p);
void initlistm(LISTM* p);
void create_sparsematrix(LIST* spm, int ele,int row, int column);
void create(LISTM* spm,int row, int column);
void display(LISTM* spm);
void read(LIST* spm);
void movement(LIST* spm,LISTM* move);

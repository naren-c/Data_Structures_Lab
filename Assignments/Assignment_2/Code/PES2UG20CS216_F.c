#include<stdio.h>
#include<stdlib.h>
#include"PES2UG20CS216_H.h"

int total_rows = -1;

void init(list **p)
{
    *p = NULL;
}

list* create_row(int row)
{
    list *temp = (list*)malloc(sizeof(list));
    temp->row = row;
    temp->head = NULL;
    temp->next = NULL;
    return temp;
}

void insert_row(list **p)
{
    if(*p == NULL)
        *p = create_row(0);
    else
    {
        list *temp = *p;
        while(temp->next)
            temp = temp->next;
        temp->next  = create_row((temp->row) + 1);
    }
    total_rows++;
}

node* create_node(int row,int col)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->row = row;
    temp->col = col;
    temp->visit = 0;
    temp->right = NULL;
    temp->down = NULL;
    return temp;
}

void insert_node(list **p,int row,int col)
{
    node *temp = create_node(row,col);
    node *temp_node = NULL;
    list *temp_row = *p;

    while(temp_row->next)
        temp_row = temp_row->next;
    temp_node = temp_row->head;

    if(temp_node == NULL)
    {
        temp_row->head = temp;
    }
    else
    {
        while(temp_node->right)
            temp_node = temp_node->right;
        temp_node->right = temp;
    }
}

void insert(list **p,int row,int col)
{
    if(row > total_rows)
        insert_row(p);
    insert_node(p,row,col);
}

void connect_down(list **p)
{
    list *first = *p;
    list *second = first->next;

    while(second)
    {
        node *temp1 = first->head;
        node *temp2 = second->head;
        while(temp1 && temp2)
        {
            if(temp1->col == temp2->col)
            {
                temp1->down = temp2;
                temp1 = temp1->right;
                temp2 = temp2->right;
            }
            else if(temp1->col > temp2->col)
                temp2 = temp2->right;
            else
                temp1 = temp1->right;

        }
        first = first->next;
        second = second->next;
    }
}

int check_presence(list **p,int row,int col)
{
    int status = 0;
    list *temp = *p;
    while(temp->next!=NULL && temp->row!=row)
        temp = temp->next;
    
    node *temp_node = temp->head;
    while(temp_node)
    {
        if(temp_node->col == col)
        {
            status = 1;
            break;
        }
        temp_node = temp_node->right;    
    }
    return status;
}

node *give_node(list **p,int row,int col)
{
    list *temp = *p;
    while(temp->next!=NULL && temp->row!=row)
        temp = temp->next;
    
    node *temp_node = temp->head;
    while(temp_node)
    {
        if(temp_node->col == col)
        {
            break;
        }
        temp_node = temp_node->right;    
    }
    return temp_node;
}

void print_path(node *arr[],int n,int status)
{
    FILE *fp = fopen("output.txt","w");
    if(status)
    {
    printf("The output has been stored in 'output.txt'.");
    fprintf(fp,"The path is to be followed is-\n");
    for(int i=0;i<=n;i++)
    {
        fprintf(fp,"%d %d\n",arr[i]->row,arr[i]->col);
    }
    }
    else
        fprintf(fp,"-1 (Invalid Path)\n");
    fclose(fp);
}

void find_path(list **p,int start_x,int start_y,int end_x,int end_y)
{
    node *arr[1000];
    connect_down(p);

    if(start_x > end_x || start_y > end_y)
        print_path(arr,0,0);
    else if(start_x == end_x && start_y == end_y)
    {
        arr[0] = give_node(p,start_x,start_y);
        print_path(arr,0,1);
    }
    else if(check_presence(p,start_x,start_y) && check_presence(p,end_x,end_y))
    {
        int move = 0;
        int status = 1;
        arr[0] = give_node(p,start_x,start_y);
        while(status)
        {
            if(arr[move]->right != NULL && !arr[move]->right->visit && (arr[move]->right->col - arr[move]->col)==1)
            {
                arr[move + 1] = arr[move]->right;
                arr[move + 1]->visit = 1;
                move++;
                if(arr[move]->row == end_x && arr[move]->col == end_y)
                {
                    status = 0;
                }
            }
            else if(arr[move]->down != NULL && !arr[move]->down->visit)
            {
                arr[move + 1] = arr[move]->down;
                arr[move + 1]->visit = 1;
                move++;
                if(arr[move]->row == end_x && arr[move]->col == end_y)
                {
                    status = 0;
                }
            }
            else
            {
                arr[move] = NULL;
                move--;
            }
            if(arr[0] == NULL)
            {
                status = 0;
            }
        }
        if(arr[0] != NULL)
            print_path(arr,move,1);
        else
            print_path(arr,0,0);
    }

    else
        print_path(arr,0,0);
}
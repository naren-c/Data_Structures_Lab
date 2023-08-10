#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

typedef struct node{
    char SRN[15];
    struct node *left;
    struct node *right; 
}node_t; 

typedef struct tree{         
    node_t *root; 
} tree_t; 

void init(tree_t *t) 
{
    t->root=NULL; 
}

void insert(tree_t *t)
{
    t->root=(node_t*)malloc(sizeof(node_t));
    t->root->left=NULL;
    t->root->right=NULL;
    printf("Enter the first SRN:");
    scanf("%s",t->root->SRN);
    int ch=1;
    do{
        node_t *temp;node_t *q=NULL;
        node_t *p=t->root;
        temp=(node_t*) malloc(sizeof(node_t));
        temp->left=temp->right=NULL;
        printf("Enter the next SRN:");
        scanf("%s",temp->SRN);
        while(p!=NULL)
        {                 
            q=p;
            if(strcmp(temp->SRN,p->SRN)<0)
            {
                p=p->left;
            }
            else 
            {
                p=p->right;
            }                 
        }                 
        if(strcmp(temp->SRN,q->SRN)<0)
        {
            q->left=temp;
        }                 
        else 
        {
            q->right = temp;
        }
        printf("Do you want to continue? Press 1 to continue: ");
        scanf("%d", &ch);
        printf("\n");
    } while (ch);
}

void inord(node_t *pt)
{
    if (pt != NULL)
    {
        inord(pt->left);
        printf("%s\n", pt->SRN);
        inord(pt->right);
    }
}

void rnode(tree_t *t) 
{
    inord(t->root); 
}

void search(tree_t *t, char ele[])
{
    int x = 1;
    node_t *p = t->root;
    node_t *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (strcmp(ele, p->SRN) == 0)
        {
            x = 0;
            break;
        }
        else if (strcmp(ele, p->SRN) < 0)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    if (x == 0)
    {
        printf("\t\tpresent\n");
    }
    else
        printf("\t\tnot found\n");
}

int main()
{
    tree_t t;
    char ele[15];
    init(&t);
    insert(&t);
    rnode(&t);
    printf("Enter the SRN which u want to search:");
    scanf("%s", ele);
    search(&t, ele);
}
typedef struct node
{
    int row;
    int col;
    int visit;
    struct node *right;
    struct node *down;
}node;

typedef struct list
{
    int row;
    node *head;
    struct list *next;

}list;

void init(list **p);
void insert(list **p,int row,int col);
void find_path(list **p,int start_x,int start_y,int end_x,int end_y);
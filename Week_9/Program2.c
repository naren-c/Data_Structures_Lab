#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;
typedef struct tree {
    Node *root;
} Tree;

Node *create_node(int);
Tree *initialise_tree(void);
void destroy_leaves(Node *);
void tree_preorder(Tree *);
void tree_inorder(Tree *);
void tree_postorder(Tree *);
void preorder_leaves(Node *);
void inorder_leaves(Node *);
void postorder_leaves(Node *);
void insert(Tree *, int);
void insert_leaf(Node *, int data);

int main() {
    int choice;
    Tree *binary_tree = initialise_tree();
    do {
        printf("\n\nMAIN MENU\n\n");
        printf("1. Insert an element into BT\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Exit\n");

        printf("\nYour choice: ");

        scanf("%d", &choice);

        switch (choice) {
            int data, priority;
            case 1: {
                printf("Enter data: ");
                scanf("%d", &data);
                insert(binary_tree, data);
                break;
            }
            case 2: {
                tree_preorder(binary_tree);
                break;
            }
            case 3: {
                tree_inorder(binary_tree);
                break;
            }
            case 4: {
                tree_postorder(binary_tree);
                break;
            }
        }

    } while (choice != 5);
	exit(0);
    return 0;
}
void insert(Tree *tree, int data) {
    
    if (tree->root == NULL) {
        Node *new_node = create_node(data);
        tree->root = new_node;
        return;
    }

    insert_leaf(tree->root, data);
}
void insert_leaf(Node *root, int data) {
    if (data < root->data) {
        if (root->left == NULL) {
            Node *new_node = create_node(data);
            root->left = new_node;
        }
        else {
            insert_leaf(root->left, data);
        }
    }
    else {
        if (root->right == NULL) {
            Node *new_node = create_node(data);
            root->right = new_node;
        }
        else {
            insert_leaf(root->right, data);
        }
    }
}
void tree_preorder(Tree *tree) 
{
    preorder_leaves(tree->root);
    printf("\n");
}
void preorder_leaves(Node *root) 
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_leaves(root->left);
        preorder_leaves(root->right);
    }
}
void tree_inorder(Tree *tree) 
{
    inorder_leaves(tree->root);
    printf("\n");
}
void inorder_leaves(Node *root) 
{
    if (root != NULL) {
        inorder_leaves(root->left);
        printf("%d ", root->data);
        inorder_leaves(root->right);
    }
}
void tree_postorder(Tree *tree) 
{
    postorder_leaves(tree->root);
    printf("\n");
}
void postorder_leaves(Node *root) 
{
    if (root != NULL) {
        postorder_leaves(root->left);
        postorder_leaves(root->right);
        printf("%d ", root->data);
    }
}
Node *create_node(int data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
Tree *initialise_tree() 
{
    Tree *new_tree = (Tree *)malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}
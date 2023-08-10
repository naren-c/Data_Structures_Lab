#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}node;
node *head;
void initialize(){
    head=NULL;
}
void freelist(){
    node *temp;
    while(head!=NULL){
        temp=head->link;
        free(head);
        head=temp;
    }
}
void display(){
    node *temp;
    temp=head;
    if(temp==NULL) printf("List is empty\n");
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}
void swap(int n1,int n2){
    if(n1>n2){
        int n=n1;
        n1=n2;
        n2=n;
    }
    int i=1;
    node *prev1=NULL,*temp1=NULL,*prev2=NULL,*temp2=NULL,*temp;
    temp=head;
    while(temp!=NULL&&i<=n2){
        if(i==n1-1) prev1=temp;
        if(i==n1) temp1=temp;
        if(i==n2-1) prev2=temp;
        if(i==n2) temp2=temp;
        temp=temp->link;
        i++;
    }
    if(temp1!=NULL&&temp2!=NULL){
        if(prev1!=NULL) prev1->link=temp2;
        if(prev2!=NULL) prev2->link=temp1;
        temp=temp1->link;
        temp1->link=temp2->link;
        temp2->link=temp;
        if(prev1==NULL) head=temp2;
        if(prev2==NULL) head=temp1;
    }
}
void insert(){
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL) printf("Overflow\n");
    else{
        printf("Enter data:");
        scanf("%d",&ptr->data);
        if(head==NULL){
            head=ptr;
            ptr->link=NULL;
        }
        else{
            temp=head;
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link=ptr;
            ptr->link=NULL;
        }
    }
}
void alternate(int n){
    node *temp=head,*ptr,*temp1;
    while(temp->link!=NULL){
        ptr=temp;
        temp1=temp->link;
        temp=temp1->link;
        ptr->link=temp;
        free(temp1);
    }
}
int main(){
    int n;
    initialize();
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insert();
    }
    printf("The entered list is:\n");
    display();
    printf("\nEnter the nodes to swapped(node1 node2):");
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    swap(n1,n2);
    display();
    printf("\n");
    printf("List after deleting alternate nodes is:\n");
    alternate(n);
    display();
    printf("\n");
    freelist();
    return 0;
}
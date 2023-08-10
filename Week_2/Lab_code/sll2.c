#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coeff;
    int px;
    int py;
    struct node *next;
}node;
void initialize(node **head){
    *head=NULL;
}
void freelist(node *head){
    node *temp;
    while(head!=NULL){
        temp=head->next;
        free(head);
        head=temp;
    }
}
void display(node **head,int flag){
    node *temp;
    temp=*head;
    if(temp==NULL) printf("List is empty\n");
    else{
        while((temp->next)->next!=NULL){
            printf("%dx^%dy^%d + ",temp->coeff,temp->px,temp->py);
            temp=temp->next;
        }
        if(!flag) printf("%dx^%dy^%d + ",temp->coeff,temp->px,temp->py);
        else printf("%dx^%dy^%d ",temp->coeff,temp->px,temp->py);
        temp=temp->next;
        if(!flag) printf("%dx^%dy^%d",temp->coeff,temp->px,temp->py);
    }
}
void insert(node **head){
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL) printf("Overflow\n");
    else{
        printf("Enter the coefficent:");
        scanf("%d",&ptr->coeff);
        printf("Enter the power of x:");
        scanf("%d",&ptr->px);
        printf("Enter the power of y:");
        scanf("%d",&ptr->py);
        if(*head==NULL){
            *head=ptr;
            ptr->next=NULL;
        }
        else{
            temp=*head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
        }
    }
}
void addpoly(node *head1,node *head2,node *sum){
    while(head1!=NULL&&head2!=NULL){
        if(head1->px==head2->px&&head1->py==head2->py){
            sum->coeff=head1->coeff+head2->coeff;
            sum->px=head1->px;
            sum->py=head1->py;
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->px>head2->px||head1->py>head2->py){
            sum->coeff=head1->coeff;
            sum->px=head1->px;
            sum->py=head1->py;
            head1=head1->next;
        }
        else if(head2->px>head1->px||head2->py>head1->py){
            sum->coeff=head2->coeff;
            sum->px=head2->px;
            sum->py=head2->py;
            head2=head2->next;
        }
        sum->next=(node*)malloc(sizeof(node));
        sum=sum->next;
        sum->next=NULL;
    }
    while(head1||head2){
        if(head1){
            sum->coeff=head1->coeff;
            sum->px=head1->px;
            sum->py=head1->py;
            head1=head1->next;
        }
        if(head2){
            sum->coeff=head2->coeff;
            sum->px=head2->px;
            sum->py=head2->py;
            head2=head2->next;
        }
        sum->next=(node*)malloc(sizeof(node));
        sum=sum->next;
        sum->next=NULL;
    }
}
int main(){
    node *head1,*head2,*sumhead;
    int n1,n2;
    initialize(&head1);initialize(&head2);initialize(&sumhead);
    printf("Enter the number of terms of the first polynomial:");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        insert(&head1);
    }
    printf("Enter the number of terms of the second polynomial:");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        insert(&head2);
    }
    printf("Polynomial 1:");
    display(&head1,0);
    printf("\n");
    printf("Polynomial 2:");
    display(&head2,0);
    printf("\n");
    printf("Sum:");
    sumhead=(node*)malloc(sizeof(node));
    addpoly(head1,head2,sumhead);
    printf("\n");
    display(&sumhead,1);
    printf("\n");
    freelist(head1);freelist(head2);freelist(sumhead);
    return 0;
}
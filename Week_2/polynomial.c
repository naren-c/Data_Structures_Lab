#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
  int coeff;
  int power_x;
  int power_y;
  struct NODE *next;
}node;

node *p1 = NULL, *p2 = NULL, *p = NULL;

void insert(int coeff, int px, int py, int flag){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->coeff = coeff;
  new_node->power_x = px;
  new_node->power_y = py;
  new_node->next = NULL;
  if(flag == 3){
    if(p==NULL){
      p = new_node;
      return;
    }
  }
  else if(flag == 2){
    if(p2==NULL){
      p2 = new_node;
      return;
    }
  }
  else if(flag == 1){
    if(p1==NULL){
      p1 = new_node;
      return;
    }
  }
    node *temp;
    if(flag == 1)
      temp = p1;
    else if(flag == 2)
      temp = p2;
    else temp = p;
    while(temp->next)
      temp = temp->next;
    temp->next = new_node;
    return;

}

void polynomial_add(){
  node *temp = p, *temp1 = p1, *temp2 = p2;
  while(temp){
    temp->coeff = temp1->coeff + temp2->coeff;
    temp = temp->next;
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return;
}

void display(int flag){
  node *temp;
  if(flag == 3)
    temp = p;
  else if(flag == 2)
    temp = p2;
  else temp = p1;
  if (!temp)  printf("NULLLL\n");
  while(temp){
    if(temp->coeff){
      if(temp->power_x==2 || temp->power_y==2)
        printf("%dx^%dy^%d + ",temp->coeff, temp->power_x, temp->power_y);
      else printf("%dxy \n",temp->coeff);
    }
    temp = temp->next;
  }
  return;
}

int main(){
  int c;
  printf("\nFor polynomial 1 :\n");
  printf("Enter the coefficients of x^2y^2, x^2y, xy^2, xy : ");
  for(int j=2; j>=1; j--){
    for(int i=2; i>=1; i--){
      scanf("%d",&c);
      insert(c,j,i,1);
    }
  }
  printf("\nFor polynomial 2 :\n");
  printf("Enter the coefficients of x^2y^2, x^2y, xy^2, xy : ");
  for(int j=2; j>=1; j--){
    for(int i=2; i>=1; i--){
      scanf("%d",&c);
      insert(c,j,i,2);
    }
  }
  for(int j=2; j>=1; j--){
    for(int i=2; i>=1; i--){
      insert(0,j,i,3);
    }
  }
  printf("\nPolynomial 1: "); display(1);
  printf("\nPolynomial 2: "); display(2);
  polynomial_add(p1,p2,p);
  printf("\nResultant polynomial: "); display(3);
  return 0;
}

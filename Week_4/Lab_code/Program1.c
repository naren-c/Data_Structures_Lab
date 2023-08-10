#include <stdio.h>
#include <string.h>
#include<ctype.h>

#define STR_LEN 20

void push(char*, char, int*);
char pop(char*, int*);
char peep(char*, int);
int stack_precedence(char);
void convert_postfix(char*, char*);
int eval_postfix(char *postfix);

int main(int argc, char* argv[]) 
{
    int top = -1;
    char postfix[STR_LEN] = "";
    char infix[STR_LEN] = "";
    printf("Enter valid infix expression: ");
    scanf("%s", infix);
    //printf("%s\n", infix);
    convert_postfix(infix, postfix);
    printf("The postfix expression is : %s\n", postfix);
	printf("Value of the postfix expression is  = %d",eval_postfix(postfix)); 
    return 0;

}
int stack_precedence(char sym)
{
    switch (sym) 
	{
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 4;
		case '(':
			return 0;
		case '^':
			return 5;
		case '#':
			return -1;
		default:
			return 8;
    }
}
int input_precedence(char sym) 
{
    switch (sym) 
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 3;
		case '(':
			return 9;
		case ')':
			return 0;
		case '^':
			return 6;
		case '#':
			return -1;
		default:
			return 7;
    }
}
void convert_postfix(char* infix, char* postfix) 
{
    static char stack[STR_LEN];
    int top = 0;
    stack[top] = '#';
    int j = 0, i = 0;
    for (i = 0; infix[i] != '\0'; ++i) 
	{
        while (stack_precedence(peep(stack, top)) > input_precedence(infix[i])) 
		{
            postfix[j++] = pop(stack, &top);
        }
        if (stack_precedence(peep(stack, top)) < input_precedence(infix[i])) 
		{
            push(stack, infix[i], &top);
        }
        else 
		{
            pop(stack, &top);
        }
    }
    while (peep(stack, top) != '#')
	{
        postfix[j++] = pop(stack, &top);
    }
    postfix[j++] = '\0';
}
char peep(char* stack, int top) 
{
    return stack[top];
}
void push(char* stack, char ch, int* ptop) 
{
    if (*ptop == STR_LEN - 1) 
	{
        printf("Expression too long\n");
        return;
    }
    ++(*ptop);
    stack[*ptop] = ch;
}
char pop(char* stack, int* ptop) {
    if (*ptop == -1) {
        return '#';
    }
    char popped = stack[*ptop];
    stack[*ptop] = 0;
    --(*ptop);
    return popped;
}


int eval_postfix(char *postfix) 
{
	char ch;
	int i = 0, op1, op2;
	char stack[STR_LEN];
	int top = -1;
	while((ch = postfix[i++]) != 0) 
	{
		if(isdigit(ch)) 
			stack[++top] = ch-'0';/* Push the operand */
		else 
		{ /* Operator,pop two operands */
			op2 = stack[top--];
			op1 = stack[top--];
			switch(ch) 
			{
				case '+' : stack[++top] = op1+op2;
						   break;
				case '-' : stack[++top] = op1-op2; 
						   break;
				case '*' : stack[++top] = op1*op2;
						   break;
				case '/' : stack[++top] = op1/op2;
						   break;
			}
		}
	}
	return stack[top];
}

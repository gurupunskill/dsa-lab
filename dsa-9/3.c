//Program to construct a tree from a postfix expression
#include<stdio.h>
#include<stdlib.h>

//Stack is needed for construction
long int stack[50];
int top = -1;

//Let the tree be represented in the form of a structure
struct tree{
	int n;
	char c;
	struct tree *right , *left;
}*root = NULL, *temp;

//Function to push into stack
void push(long int n)
{
	stack[++top] = n;
}

//Function to pop
int pop()
{
	return(stack[top--]);
}

//Function to construct the tree
long int tree_construct(char a[])
{
	int i , op1 , op2;
	for(i=0;a[i]!='\0';++i)
	{
		if(a[i] == '/' || a[i] == '*' || a[i] == '-' || a[i] == '+' || a[i] == '^')
		{
			temp = (struct tree*)malloc(sizeof(struct tree));
			op1 = pop();
			op2 = pop();
			temp->c = a[i];
			temp->right = (struct tree*)malloc(sizeof(struct tree));
			temp->left = (struct tree*)malloc(sizeof(struct tree));
			temp->right->n = op1;
			temp->left->n = op2;
			push(temp);
		}	
		else
			push(a[i]);
	}
	return stack[0];
}

//Funtion to display in pre order fashion
void pre_display(struct tree *a)
{
	if(a != NULL)
	{
		if(a->n>=0 && a->n<=9)
			printf("%d" , a->n);
		else
			printf("%c" , a->c);
	}
	else
		return;
	pre_display(a->left);
	pre_display(a->right);
}

//Main begins
void main()
{
	char exp[20];
	printf("\n\n\tCONSTRUCTION OF TREE FROM A POSTFIX EXPRESSION\n");
	printf("\n\nEnter the postfix expression: ");
	scanf("%s" , exp);
	root = tree_construct(exp);
	pre_display(root);
	printf("\n\n");
}

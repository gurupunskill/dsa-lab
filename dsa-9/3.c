#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
 
// An expression tree node
struct et
{
    char value;
    struct et* left, *right;
};

struct et *stack[50];
int tp = -1;

void push (struct et * node)
{
	stack[++tp] = node;
}

void pop()
{
	tp--;
}

struct et* top()
{
	return stack[tp];
}
 
// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}
 
// Utility function to do inorder traversal
void inorder(struct et *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}
 
// A utility function to create a new node
struct et* newNode(int v)
{
    struct et *temp = (struct et*) malloc (sizeof(struct et));
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
 
// Returns root of constructed tree for given
// postfix expression
struct et* constructTree(char postfix[])
{
    struct et *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);
 
            // Pop two top nodes
            t1 = top(); // Store top
            pop();      // Remove top
            t2 = top();
            pop();
 
            //  make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = top();
    pop();
 
    return t;
}
 
// Driver program to test above
int main()
{
    char postfix[100];
    printf ("\n\n\t Enter Postfix Expression ==> ");
    gets(postfix);
    struct et* r = constructTree(postfix);
    printf("\n\t Inorder expression of tree is ");
    inorder(r);
    printf ("\n\n\n");
    return 0;
}

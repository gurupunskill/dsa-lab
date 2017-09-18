# Palindrome program using stack

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
 
struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};
 
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}
 
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
 
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
 
void reverse(char str[])
{
    int n = strlen(str);
    struct Stack* stack = createStack(n);
 
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);
 
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}
 
int main()
{
    char str[100];
	printf ( "\n\n\t Enter a string ==> ");
	gets(str);
    char copy[strlen(str)];
    strcpy (copy,str);
    reverse(copy);
    printf("\n\t Reversed string is %s", copy);

    if ( strcmp (copy,str) == 0 )
    {
		printf ( "\n\t The string is a plaindrome \n\n");
	}
	else
	{
		printf ( "\n\t The string is not a palindrome \n\n");
	}
 
    return 0;
}

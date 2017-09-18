#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* npx;
};

struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void insert(struct Node **head_ref, int data)
{
    struct Node *new_node  = (struct Node *) malloc (sizeof (struct Node) );
    new_node->data = data;
    new_node->npx = XOR(*head_ref, NULL);
    if (*head_ref != NULL)
    {
        struct Node* next = XOR((*head_ref)->npx,  NULL);
        (*head_ref)->npx = XOR(new_node, next);
    }
    *head_ref = new_node;
}
void printList (struct Node *head)
{
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next;
    while (curr != NULL)
    {
        printf ("%d ", curr->data);
        next = XOR (prev, curr->npx);
        prev = curr;
        curr = next;
    }
}
 
int main ()
{
struct Node* head = NULL;
	char ch = 'y';
	while (ch == 'y')
	{
		printf ("\n\n\t Main Menu ");
		printf ("\n 1. Insert a new element \n 2. Print List \n ==> ");
		int k;
		int pos;
		int data;
		scanf ("%d", &k );
		switch(k)
		{
			case 1:
				printf ("\n\n Old XLL: ");
				printList ( head );
	
				printf ( "\n\n Enter data ==> ");
				scanf ( "%d", &data );
				insert (&head, data);
				break;
			case 2:
				printf ("\n\n XLL: ");
				printList ( head );
				break;			
			
			default:
				printf ("\n\n\t Invalid Choice !");
		}
		printf ("\n\n\t Would you like to continue?\n (y/n) ==> ");
		scanf ("%c", &ch );
		scanf ("%c", &ch );
	}
    return (0);
}

#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int n = 0;

void printList(struct Node *start)
{
    struct Node *temp = start;
 
    printf("\n Traversal in forward direction \n ");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
 
    printf("\n Traversal in reverse direction \n ");
    struct Node *last = start->prev;
    temp = last;
    while (temp->prev != last)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

void push(struct Node** start, int value)
{
    struct Node *last = (*start)->prev;
 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); ;
    new_node->data = value;
	
	new_node->next = *start;
    new_node->prev = last;
 
    last->next = (*start)->prev = new_node;
 
    *start = new_node;
}
 
void insertAfter(struct Node* prev_node, int new_data)
{
 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
 
    if (new_node->next != NULL)
      new_node->next->prev = new_node;
}

void append(struct Node** start, int value)
{
    if (*start == NULL)
    {
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    struct Node *last = (*start)->prev;
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void insert ( struct Node **start, int new_data, int pos)
{
    pos--;
    if ( pos > n+1 || pos < 0 )
    {
        printf ("\n\n\t ERROR!");
        return;
    }
		
	
    if ( pos == 0 && (*start != NULL))
        push( start, new_data );
    else if ( pos == n || (*start == NULL))
        append( start, new_data );
    else
    {
        int i = 1;
        struct Node *ptr = *start;
        while ( i < pos)
        {
            i++;
            ptr = ptr -> next;
        }
        insertAfter ( ptr, new_data );
    }
    n++;
	
	printf ("\n\n New DLL: ");
	printList ( *start );
	
}

void delete( struct Node **start, int key )
{
    if (*start == NULL)
        return;
    struct Node *curr = *start, *prev_1 = NULL;
    while (curr -> data != key)
    {
        if (curr->next == *start)
        {
            printf("\nList doesn't have node with value = %d", key);
            return;
        }
 
        prev_1 = curr;
        curr = curr -> next;
    }
 
    if (curr -> next == *start && prev_1 == NULL)
    {
        (*start) = NULL;
        free(curr);
        return;
    }
    if (curr == *start)
    {
        prev_1 = (*start) -> prev;
        *start = (*start) -> next;
        prev_1 -> next = *start;
        (*start) -> prev = prev_1;
        free(curr);
    }
 
    else if (curr->next == *start)
    {
        prev_1 -> next = *start;
        (*start) -> prev = prev_1;
        free(curr);
    }
    else
    {
        struct Node *temp = curr -> next;
        prev_1 -> next = temp;
        temp -> prev = prev_1;
        free(curr);
    }
}

 
int main()
{
    struct Node* head = NULL;

	char ch = 'y';
	
	while (ch == 'y')
	{
		printf ("\n\n\t Main Menu ");
		printf ("\n 1. Insert a new element \n 2. Delete an element \n 3. Print List \n ==> ");
		int k;
		int pos;
		int data;
		scanf ("%d", &k );
		switch(k)
		{
			case 1:
	
				printf ( "\n\n Enter data ==> ");
				scanf ( "%d", &data );
				printf ( "\n Enter Position ==> ");
				scanf ( "%d", &pos );

				insert (&head, data, pos);
				break;
			case 2:
				printf ("\n\n Old DLL: ");
				printList ( head );
	
				printf ( "\n Enter Value ==> ");
				scanf ( "%d", &pos );

				delete (&head, pos);

				break;
			case 3:
				printf ("\n\n DLL: ");
				printList ( head );
				break;			
			
			default:
				printf ("\n\n\t Invalid Choice !");
		}
		printf ("\n\n Would you like to continue?\n (y/n) ==> ");
		scanf ("%c", &ch );
		scanf ("%c", &ch );
	}
    
    
    getchar();
    return 0;
}

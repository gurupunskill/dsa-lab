#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int n = 0;

void printList(struct Node *node)
{
    struct Node *last;
    printf("\n Forward \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\n Reverse \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
    (*head_ref)    = new_node;
}
 
void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
 
    if (new_node->next != NULL)
      new_node->next->prev = new_node;
}

void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    
    last->next = new_node;
    new_node->prev = last;
 
    return;
}

void insert ( struct Node **head_ref, int new_data, int pos)
{
    pos--;
    if ( pos > n+1 || pos < 0 )
    {
        printf ("\n\n\t ERROR!");
        return;
    }

    if ( pos == 0 )
        push( head_ref, new_data );
    else if ( pos == n )
        append( head_ref, new_data );
    else
    {
        int i = 1;
        struct Node *ptr = *head_ref;
        while ( i < pos)
        {
            i++;
            ptr = ptr -> next;
        }
        insertAfter ( ptr, new_data );
    }
    n++;
	
	printf ("\n\n New DLL: ");
	printList ( *head_ref );
	
	
}

void delete( struct Node **head_ref, int pos )
{
    int i = 1;
    
    if ( n == 0 || pos > n || pos < 1 )
    {
        printf ("\n\n\t ERROR!");
        return;
    }
	
		


    if ( pos == 1 )
    {
        *head_ref = (*head_ref)->next;
        (*head_ref)->prev = NULL;
    }
    
    else if ( pos == n )
    {
        struct Node *last = *head_ref;
        while (last->next != NULL)
            last = last->next;
        
        (last->prev)->next = NULL;
    }

    else
    {
        struct Node *ptr = *head_ref;
        while ( i < pos )
        {
            i++;
            ptr = ptr -> next;
        }
        (ptr->prev)->next = ptr->next;
        (ptr->next)->prev = ptr->prev;
    }
    n--;

		
	printf ("\n\n New DLL: ");
	printList ( *head_ref );
	

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
				printf ("\n\n Old DLL: ");
				printList ( head );
	
				printf ( "\n\n Enter data ==> ");
				scanf ( "%d", &data );
				printf ( "\n Enter Position ==> ");
				scanf ( "%d", &pos );

				insert (&head, data, pos);
				break;
			case 2:
				printf ("\n\n Old DLL: ");
				printList ( head );
	
				printf ( "\n Enter Position ==> ");
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
		printf ("\n\n\t Would you like to continue?\n (y/n) ==> ");
		scanf ("%c", &ch );
		scanf ("%c", &ch );
	}
    
    
    getchar();
    return 0;
}

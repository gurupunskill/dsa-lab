//Binary Trees using linked lists
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *left, *right;
} *root;

void push ( struct Node* p, struct Node** current)
{
	if ( *current == NULL )
	{
		*current = p;
		return;
	}
	printf("\n\t Current Node: %d", (*current)-> data);
	printf("\n\t Left or Right? (0/1) ==> ");
	int pos;
	scanf("%d", &pos);
	if (pos == 0)
		push(p, &((*current)->left));
	if (pos == 1)
		push(p, &((*current)->right));
}

void insert(int dat)
{
	struct Node* p = (struct Node*) malloc(sizeof(struct Node));
	p -> data = dat;
	p -> left = NULL;
	p -> right = NULL;
	//printf ("\n\t %d", p->data);
	push (p, &root);
}

void delete(struct Node** current)
{
	if (*current == NULL)
	{
		printf ("\n\t Underflow");
	}	
	printf("\n\t Current Node: %d", (*current)-> data);
	printf("\n\t Delete? (0/1) ==> ");
	int del;
	scanf ("%d", &del);
	if (del) (*current) = NULL;
	else
	{
		printf("\n\t Left or Right? (0/1) ==> ");
		int pos;
		scanf("%d", &pos);
		if (pos == 0)
		{
			if ((*current)->left != NULL)
				delete(&((*current)->left));
			else
			{
				printf ("\n\t Error");	
			}	
		}		
		if (pos == 1)
		{
			if ((*current)->right != NULL)
				delete(&((*current)->right));
			else
			{
				printf ("\n\t Error");	
			}
		}				
	}	
}

void display_1(struct Node* current)
{
	if ( current != NULL)
	{
		printf ("%d ", current->data);
		display_1(current->left);
		display_1(current->right);
	}
	else 
	{
		//printf ("X");
		return;
	}
}

void display_2(struct Node* current)
{
	if ( current != NULL)
	{
		display_2(current->left);
		printf ("%d ", current->data);
		//printf (",");
		display_2(current->right);
		//printf (")");	
	}
	else 
	{
		//printf ("X");
		return;
	}
}

void display_3(struct Node* current)
{
	if ( current != NULL)
	{
		display_3(current->left);
		//printf (",");
		display_3(current->right);	
		printf ("%d ", current->data);
	}
	else 
	{
		//printf ("X");
		return;
	}
}

int isBSTUtil(struct Node* node, int min, int max);
 
int isBST(struct Node* node) 
{ 
  return(isBSTUtil(node, -32768, 32767)); 
} 
 
int isBSTUtil(struct Node* node, int min, int max) 
{ 
  if (node==NULL) 
     return 1;
       
  if (node->data < min || node->data > max) 
     return 0; 
 
  return
    isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->data+1, max); 
} 

void display(struct Node* root)
{
	printf ("\n\n\t Preorder ==> ");
	display_1(root);
	printf ("\n\t Inorder ==> ");
	display_2(root);
	printf ("\n\t Postorder ==> ");
	display_3(root);
}

int search(int dat, struct Node* current)
{	
	if ( current == NULL )
		return 0;
	if (current->data == dat )
		return 1;
	return ( search(dat, current->left) | search(dat, current->right));
}

void main()
{
	int ch = 0, dat;
	while (ch != 6)
	{
		printf ("\n\n\t 1. Insert Node \n\t 2. Display Tree \n\t 3. Delete Node \n\t 4. Search Tree \n\t 5. Is BST? \n\t 6. Exit \n\t ==> ");
		scanf ("%d", &ch);
		switch (ch)
		{
			case 1:
			printf ("\n\n\t Enter element to insert ==> ");
			scanf ("%d", &dat);
			insert(dat);
			break;
			
			case 2:
			display(root);
			break;
			
			case 3:
			delete(&root);			
			break;

			case 4:
			printf ("\n\n\t Enter element to Search ==> ");
			scanf ("%d", &dat);
			int found = search(dat, root);
			if (found) {printf ("\n\t Found!");}
			else printf ("\n\t Not Found!");
			break;						
			
			case 5:
			if (isBST(root))
				printf ("\n\t True");
			else printf ("\n\t False");
			
			case 6:
			break;		

			default:
			printf ("\n\t INVALID CHOICE");
			break;
		}
	}
}

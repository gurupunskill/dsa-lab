//Binary Search Trees using linked lists
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *left, *right, *P;
} *root;

struct Node* newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = temp->P = NULL;
    return temp;
}

struct Node* minimum(struct Node* x)
{
	while (x->left != NULL)
		x = x->left;
	return x;
}

struct Node* maximum(struct Node* x)
{
	while (x->right != NULL)
		x = x->right;
	return x;
}

struct Node* successor(struct Node* x)
{
	if (x->right != NULL)
		return minimum(x->right);
	struct Node* y = x->P;
	
	while ( y != NULL && x == y->right )
	{
		x = y;
		y = y->P;
	}
	
	return y;
}

void insert(struct Node** root, int item)
{
	struct Node* y = NULL;
	struct Node* x = *root;
	struct Node*z = newNode(item);
	while ( x != NULL )
	{
		y = x;
		if (z->data < x->data)
			x = x->left;
		else x = x->right;
	}
	z->P = y;
	if (y == NULL)
		*root = z;
	else if (z->data < y->data)
		y->left = z;
	else
		y->right = z;
}

struct Node* search(int dat, struct Node* current)
{	
	if ( current == NULL || current->data == dat )
		return current;
	if ( dat < current->data )
		return search(dat, current->left);
	return search(dat, current->right);
}

void delete(struct Node** root, int item)
{
	struct Node* z = search(item, *root);
	struct Node* y;
	struct Node* x;
	if (z->left == NULL || z->right == NULL)
		y = z;
	else y = successor(z);
	
	if (y->left != NULL)
		x = y->left;
	else x = y->right;
	
	if (x!=NULL)
		x->P = y->P;
	if (y->P == NULL)
		*root = x;
	else if (y == y->P->left)
		y->P->left = x;
	else y->P->right = x;
	
	if (y != z)
		z->data = y->data;
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

void display(struct Node* root)
{
	printf ("\n\n\t Preorder ==> ");
	display_1(root);
	printf ("\n\t Inorder ==> ");
	display_2(root);
	printf ("\n\t Postorder ==> ");
	display_3(root);
}

void main()
{
	int ch = 0, dat;
	while (ch != 5)
	{
		printf ("\n\n\t 1. Insert Node \n\t 2. Display Tree \n\t 3. Delete Node \n\t 4. Search Tree \n\t 5. Exit \n\t ==> ");
		scanf ("%d", &ch);
		switch (ch)
		{
			case 1:
			printf ("\n\n\t Enter element to insert ==> ");
			scanf ("%d", &dat);
			insert(&root, dat);
			break;
			
			case 2:
			display(root);
			break;
			
			case 3:
			printf ("\n\n\t Enter element to delete ==> ");
			scanf ("%d", &dat); 
			delete(&root, dat);			
			break;

			case 4:
			printf ("\n\n\t Enter element to Search ==> ");
			scanf ("%d", &dat);
			struct Node* found = search(dat, root);
			if (found != NULL)
				printf ("\n\t FOUND!");
			else printf ("\n\t Not FOUND!");
			
			break;						

			case 5:
			break;		

			default:
			printf ("\n\t INVALID CHOICE");
			break;
		}
	}
}

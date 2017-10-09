//Binary Trees using linked lists
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
	int data;
	struct Node *left, *right;
} *root;

unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}

int findHeight(struct Node *node)
{
   int d = 0;
   while (node != NULL)
   {
      d++;
      node = node->left;
   }
   return d;
}

bool isPerfect (struct Node* root, int height, int number_nodes)
{
    return (number_nodes == ((1<<height)-1));
}

bool isComplete (struct Node* root, unsigned int index, unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (true);

    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);

    // Recur for left and right subtrees
    return (isComplete(root->left, 2*index + 1, number_nodes) &&
            isComplete(root->right, 2*index + 2, number_nodes));
}

bool isFull(struct Node* root)
{
    // If empty tree
    if (root == NULL)
        return true;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ((root->left) && (root->right))
        return (isFull(root->left) && isFull(root->right));

    // We reach here when none of the above if conditions work
    return false;
}

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

void display(struct Node* current)
{
	if ( current != NULL)
	{
		printf ("%d(", current->data);
		display(current->left);
		printf (",");
		display(current->right);
		printf (")");
	}
	else
	{
		printf ("X");
		return;
	}
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
		printf ("\n\n\t 1. Insert Node \n\t 2. Display Tree \n\t 3. Delete Node \n\t 4. Search Tree \n\t 5. Tree Properties \n\t 6. Exit \n\t ==> ");
		scanf ("%d", &ch);
		switch (ch)
		{
			case 1:
			printf ("\n\n\t Enter element to insert ==> ");
			scanf ("%d", &dat);
			insert(dat);
			break;

			case 2:
			printf ("\n\n\t ");
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
            printf ("\n\n\t Is Full? %d \n\t Is Complete? %d \n\t Is Perfect? %d \n", isFull(root), isComplete(root, 0, countNodes(root)), isPerfect(root,findHeight(root),countNodes(root)));

			case 6:
			break;

			default:
			printf ("\n\t INVALID CHOICE");
			break;
		}
	}
}

/* program to construct tree using inorder and preorder traversals */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char data;
  struct node* left;
  struct node* right;
};
 
/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
struct node* newNode(char data);
 
struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;
 
  if(inStrt > inEnd)
     return NULL;
 
  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  struct node *tNode = newNode(pre[preIndex++]);
 
  /* If this node has no children then return */
  if(inStrt == inEnd)
    return tNode;
 
  /* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  /* Using index in Inorder traversal, construct left and
     right subtress */
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}
 
int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
 
struct node* newNode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
void display_1(struct node* current)
{
	if ( current != NULL)
	{
		printf ("%c ", current->data);
		display_1(current->left);
		display_1(current->right);
	}
	else 
	{
		//printf ("X");
		return;
	}
}

void display_2(struct node* current)
{
	if ( current != NULL)
	{
		display_2(current->left);
		printf ("%c ", current->data);
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

void display_3(struct node* current)
{
	if ( current != NULL)
	{
		display_3(current->left);
		//printf (",");
		display_3(current->right);	
		printf ("%c ", current->data);
	}
	else 
	{
		//printf ("X");
		return;
	}
}

void display(struct node* root)
{
	printf ("\n\n\t Preorder ==> ");
	display_1(root);
	printf ("\n\t Inorder ==> ");
	display_2(root);
	printf ("\n\t Postorder ==> ");
	display_3(root);
} 
int main()
{
  char in[100], pre[100];
  printf("\n\nEnter preorder traversal of tree ==> ");
  gets(pre);
  printf("\nEnter inorder traversal of tree ==> ");
  gets(in);
  int len = strlen(in);
  
  struct node *root = buildTree(in, pre, 0, len - 1);
  display(root);
  getchar();
}

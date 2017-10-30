//Program to traverse the tree in 3 ways => preorder , inorder and postorder

#include<stdio.h>

//Let the tree array be globally declared

int tree[50];

//Function used to insert node
void insert_node(int pos_root)
{
	int ch;
	//pos_root will hold root index of subtree and '0' represents empty space
	if(tree[pos_root] == 0)
	{
		printf("\n\nEnter value of node: ");
		scanf("%d" , &tree[pos_root]);
		return;
	}
	printf("\n\nWould like to enter a left or right child of node with value %d?(0/1): " , tree[pos_root]);
	scanf("%d" , &ch);
	
	//recursive calls to function based on above said formulae
	if(ch==0)
		insert_node(2*pos_root);
	else
		insert_node((2*pos_root)+1);
	return;
}

//Funtion to display in pre order fashion
void pre_display(int pos_root)
{
	if(tree[pos_root] != 0)
		printf("%d" , tree[pos_root]);
	else
		return;
	pre_display(2*pos_root);
	pre_display(2*pos_root + 1);
}

//Function to display in inorder fashion
void in_display(int pos_root)
{
	if(tree[pos_root] != 0)
		in_display(2*pos_root);
	else
		return;
	printf("%d" , tree[pos_root]);
	in_display(2*pos_root + 1);
}

//Function to display in post order fashion
void post_display(int pos_root)
{
	if(tree[pos_root] != 0)
		post_display(2*pos_root);
	else
		return;
	post_display(2*pos_root + 1);
	printf("%d" , tree[pos_root]);
}

//Main Begins
void main()
{
	int i;
	printf("\n\n\tIMPLEMENTATION OF DIFFERENT TRAVERSAL TECHNIQUES\n");
	printf("\n\n\tEnter the nodes==>\n\n");
	for(i=0;i<7;++i)
		insert_node(1);
	printf("\n\nPre-order ==>\n\t");
	pre_display(1);
	printf("\n\nPost-order ==>\n\t");
	post_display(1);
	printf("\n\nIn-order ==>\n\t");
	in_display(1);
	printf("\n\n");
	//End main
}	
	

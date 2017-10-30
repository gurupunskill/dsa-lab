//Program to construct a tree when its inorder and pre order traversals are given

#include <stdio.h>
#include <stdlib.h>

//Tree is being represented with the help of a structure which is globally declared

struct tree {
    int key;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} *root = NULL;

//Function to create a new node in tree
struct tree* newNode(int key , struct tree* parent){

    struct tree* node = (struct tree*)malloc(sizeof(struct tree));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
}

//Function to construct the tree
struct tree* treeConstruct(int inorder[], int preorder[], int n, struct tree* parent){

    if(n==1)
        return newNode(inorder[0],parent);

    int subtree_root_key = preorder[0];
    struct tree* subtree_root = newNode(subtree_root_key,parent);

    //To find this root in inorder
    int i, temp_inorder[20];
    for(i=0;i<n;++i){

        if(subtree_root_key == inorder[i])
            break;
        temp_inorder[i] = inorder[i];
    }
    //i will be the size of temp_inorder

    int j, temp_preorder[20];
    for(j=0;j<i;++j)
        temp_preorder[j] = preorder[j+1];

    struct tree* child_left = treeConstruct(temp_inorder,temp_preorder,i,subtree_root);

    //Fill in remaining of inorder and preorder

    int k, a;
    for(k=i+1,a=0;k<n;++k,++a)
        temp_inorder[a] = inorder[k];
    for(k=j+2,a=0;k<n;++k,++a)
        temp_preorder[a] = preorder[k];

    struct tree* child_right = treeConstruct(temp_inorder,temp_preorder,(n-i-1),subtree_root);

    parent->left    = child_left;
    parent->right   = child_right;

    return subtree_root;
}

//Funtion to display in pre order fashion
void pre_display(struct tree *a)
{
	if(a != NULL)
			printf("%d" , a->key);
	else
		return;
	pre_display(a->left);
	pre_display(a->right);
}

//Main begins
void main(){

    int n , i , in[20] , pre[20];
    printf("\n\n\tIMPLEMENTATION OF TREE CONSTRUCT FROM INORDER AND PREORDER TRAVERSALS\n\n");
    printf("\nEnter number of nodes: ");
    scanf("%d" , &n);
    printf("\nEnter inorder traversal: ");
    for(i=0;i<n;++i)
        scanf("%d" , &in[i]);
    printf("\nEnter preorder traversal: ");
    for(i=0;i<n;++i)
        scanf("%d" , &pre[i]);
    root = treeConstruct(in,pre,n,root);
    printf("\n\nThe constructed tree is: ");
    pre_display(root);
    //Main ends
}

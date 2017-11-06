#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct tree
{
 int data;
 int height;
 struct tree *left;
 struct tree *right;
};
struct tree *create_node(int n)
{
  struct tree *node = (struct tree *)malloc(sizeof(struct tree));
  node->data = n;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  return node;
}
int search_tree(struct tree *node, int elem)
{
  if(!node)
   return 0;
  printf("%d ",node->data);
  if(node->data==elem)
     return 1;
  else if(elem < node->data)
  search_tree(node->left,elem);
  else if(elem > node->data)
  search_tree(node->right,elem);
}

int find_height(struct tree *node)
{
  if(node == NULL || (node->right == NULL && node->left == NULL))
  return 0;
  if((find_height(node->left))>=(find_height(node->right)))
    return find_height(node->left) + 1;
  else
    return find_height(node->right) + 1;
}

int getbalance(struct tree *root)
{
  return find_height(root->left)-find_height(root->right);
}


struct tree *singlerotateright(struct tree *root) //RR Rotation
{
  struct tree *c = root->right;
  root->right = c->left;
  c->left = root;
  root->height = find_height(root);
  c->height = find_height(c);
  return c;
}


struct tree *singlerotateleft(struct tree *root)  //LL Rotation
{
  struct tree *c = root->left;
  root->left = c->right;
  c->right = root;
  root->height = find_height(root);
  c->height = find_height(c);
  return c;
}

struct tree *doublerotateleft(struct tree *root)  //LR Rotation
{
  root->left = singlerotateright(root->left);
  return singlerotateleft(root);
}


struct tree *doublerotateright(struct tree *root)  //RL Rotation
{
  root->right = singlerotateleft(root->right);
  return singlerotateright(root);
}

struct tree *insert(struct tree *node,int *n)
{
  if(node == NULL)
  {
    return create_node(*n);
  }

  if (*n < node->data)
  {
    node->left = insert(node->left,n);
    if(abs((find_height(node->left))-(find_height(node->right))) == 2)
    {
      if(*n < (node->left->data))
      node = singlerotateleft(node);
      else
      node = doublerotateleft(node);
    }
  }
  if(*n > node->data)
  {
    node->right = insert(node->right,n);
    if(abs(find_height(node->right)-find_height(node->left)) == 2)
    {
      if(*n > (node->right->data))
      node = singlerotateright(node);
      else
      node = doublerotateright(node);
    }
  }
  node->height = find_height(node);
  return node;
}

struct tree *minValueNode(struct tree *node)
{
    struct tree *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct tree *deleteNode(struct tree *root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
     {
         // node with only one child or no child
         if( (root->left == NULL) || (root->right == NULL) )
         {
             struct tree *temp = root->left ? root->left :
                                              root->right;

             // No child case
             if (temp == NULL)
             {
                 temp = root;
                 root = NULL;
             }
             else // One child case
              *root = *temp; // Copy the contents of
                             // the non-empty child
             free(temp);
         }
         else
         {
             // node with two children: Get the inorder
             // successor (smallest in the right subtree)
             struct tree *temp = minValueNode(root->right);

             // Copy the inorder successor's data to this node
             root->data = temp->data;

             // Delete the inorder successor
             root->right = deleteNode(root->right, temp->data);
         }
     }
    if(!root)
    return root;
    root->height = find_height(root);
    int balance = getbalance(root);
    if (balance > 1 && getbalance(root->left) >= 0)
        return singlerotateleft(root);

    // Left Right Case
    if (balance > 1 && getbalance(root->left) < 0)
    {
        return doublerotateleft(root);
    }

    // Right Right Case
    if (balance < -1 && getbalance(root->right) <= 0)
        return singlerotateright(root);

    // Right Left Case
    if (balance < -1 && getbalance(root->right) > 0)
    {
        return doublerotateright(root);
    }
    return root;
}


void print_inorder(struct tree *node)
{
  if(node==NULL)
   return;
  print_inorder(node->left);
  printf("%d ",node->data);
  print_inorder(node->right);
}


main()
{
  int ch,elem;
  struct tree *root = NULL;
  do {
    printf("\nMenu\n0.Print inorder\n1.Insert\n2.Search\n3.Delete\n4.Exit\nEnter your choice: ");
    scanf("%d",&ch);
    switch (ch) {
      case 0:
      printf("The inorder traversal is:\n");
      print_inorder(root);
      break;
      case 1:
      printf("Enter value to insert: ");
      scanf("%d",&elem);
      root = insert(root,&elem);
      break;
      case 2:
      printf("Enter value to search: ");
      scanf("%d",&elem);
      if(search_tree(root,elem))
      printf("Found\n");
      else
      printf("Not Found\n");
      break;
      case 3:
      printf("Enter value to delete: ");
      scanf("%d",&elem);
      root = deleteNode(root,elem);
      break;
    }
  } while(ch!=4);
}

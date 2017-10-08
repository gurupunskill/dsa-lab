// Deque

#include<stdio.h>

struct Node
{
    int data;
    struct Node *next, *prev;
}

void addFirst (struct Node **head_ref, int n)
{
    struct Node *new_Node = (struct Node*) malloc(sizeof(struct Node));
    new_Node->data = n;
    new_Node->next = *head_ref;
    new_node->prev = NULL;
    if((*head_ref) != NULL)
        *head_ref->prev = new_Node;
    *head_ref = new_Node;
}

void addLast (struct Node)
{
    struct Node *new_Node = (struct Node*) malloc(sizeof(struct Node));
    new_Node->data = n;
    new_Node->next = NULL;

    if((*head_ref) == NULL)
    {
        new_Node->prev = NULL;
        (*head_ref) = new_Node;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_Node;
    new_Node->prev = last;
}

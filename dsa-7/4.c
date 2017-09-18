/* Program to implement a queue using two stacks */
#include<stdio.h>
#include<stdlib.h>
 
/* structure of a stack node */
struct sNode
{
    int data;
    struct sNode *next;
};
 
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data);
 
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref);
 
/* structure of queue having two stacks */
struct queue
{
    struct sNode *stack1;
    struct sNode *stack2;
};
 
/* Function to enqueue an item to queue */
void enQueue(struct queue *q, int x, int pos)
{
    if ( pos == 0 )
        push(&q->stack1, x);
    else if ( pos == 1 )
        push(&q->stack2, x);
}
 
/* Function to dequeue an item from queue */
int deQueue(struct queue *q, int pos)
{
    int x;
    /* If both stacks are empty then error */
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }
    
    if ( pos == 1 )
    {
    /* Move elements from satck1 to stack 2 only if
    stack2 is empty */
        if(q->stack2 == NULL)
        {
            while(q->stack1 != NULL)
            {
                x = pop(&q->stack1);
                push(&q->stack2, x);
            }
        }
        x = pop(&q->stack2);
        return x;
    }

    if ( pos == 0 )
    {
        if(q->stack1 == NULL)
        {
            while(q->stack2 != NULL)
            {
                x = pop(&q->stack2);
                push(&q->stack1, x);
         
            }
        }
        x = pop(&q->stack1);
        return x;
    }
}

void push(struct sNode** top_ref, int new_data)
{
    struct sNode* new_node =
        (struct sNode*) malloc(sizeof(struct sNode));
        if(new_node == NULL)
        {
            printf("Stack overflow \n");
            getchar();
            exit(0);
             
        }
new_node->data = new_data;
new_node->next = (*top_ref);
(*top_ref) = new_node;
}

int pop(struct sNode** top_ref)
{
    int res;
    struct sNode *top;
     
    /*If stack is empty then error */
    if(*top_ref == NULL)
    {
        printf("Stack overflow \n");
        getchar();
        exit(0);
         
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
         
    }
}

int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    int ch = 0, data, pos;
    while ( ch != 3 )
    {
        printf ( "\n\n\t\t MAIN MENU ");
        printf ( "\n\n\t 1. Insert an element");
        printf ( "\n\t 2. Delete an element");
        printf ( "\n\t 3. Exit");
        printf ( "\n\n\t ==> ");
        scanf ( "%d", &ch );

        switch (ch)
        {
            case 1: 
            printf ("\n\n\t Enter data ==> ");
            scanf ("%d", &data);
            printf ("\n\t Enter position ( 0 -> Front, 1 -> Rear ) ==> ");
            scanf ("%d", &pos);
            enQueue (q, data, pos);
            break;

            case 2:
            printf ("\n\t Enter position ( 0 -> Front, 1 -> Rear ) ==> ");
            scanf ("%d", &pos);
            printf ("\n\t The element being deleted ==> %d", deQueue (q, pos));
            break;

            case 3:
            break;

            default:
            printf ("\n\t Invalid Choice !");
            break;            
        }
    }    
    getchar();
}

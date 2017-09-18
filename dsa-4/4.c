#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

struct Node *create(int key)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}

int findLoop (struct Node *head)
{
	struct Node *slow = head, *fast = head;
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	struct Node *head = create(50);
    head->next = create(20);
    head->next->next = create(15);
    head->next->next->next = create(4);
    head->next->next->next->next = create(10);

    printf ("\n\n\t Before making a loop.");
    if(findLoop(head) == 1)
    {
        printf ("\n\t Loop exists \n");
    }
    else
    {
        printf ("\n\t Loop does not exist \n");
    }

    // Create a loop for testing
    head->next->next->next->next->next = head->next->next;
    printf ("\n\n\t After making a loop.");
    if(findLoop(head) == 1)
	{
		printf ("\n\t Loop exists \n");
	}
    else
    {
    	printf ("\n\t Loop does not exist \n");
    }

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct linked_list{
	int number;
	struct linked_list *next;
};
typedef struct linked_list node;
void create (node *list)
{
	printf("\n\nInput Number -999 to exit: ");
	scanf("%d" , &list->number);
	if(list->number == -999)
		list->next = NULL;
	else
	{
		list->next = (node*)malloc(sizeof(node));
		create(list->next);
	}
}
void print(node *list)
{
	if(list->next != NULL)
	{
		printf("%d  ->  " , list->number);
		if(list->next->next == NULL)
			printf("%d",list->next->number);
		print(list->next);
	}
	return 0 ;
}
node *insert( node *head)
{
	node *find(node *p,int a);
	node *new;
	node *n1;
	int key;
	int x;
	printf("\n\nValue of new item: ");
	scanf("%d",&x);
	printf("\n\nKey item: (-999 if last) ");
	scanf("%d",&key);
	if(head->number == key)
	{
		new = (node*)malloc(sizeof(node));
		new->number = x;
		new->next = head;
		head = new;
	}
	else
	{
		n1 = find(head,key);
		if(n1 == NULL)
			printf("\n\nKey not found");
		else
		{
			new = (node*)malloc(sizeof(node));
			new->number = x;
			new->next = n1->next;
			n1->next = new;
		}
	}
	return(head);
}
node *find(node *list,int key)
{
	if(list->next->number == key)
		return (list);
	else
	{
		if(list->next->next == NULL)
			return (NULL);
		else
			return(find(list->next,key));
	}
}
node *delete(node *head)
{
	node *find(node *p,int a);
	int key;
	node *n1,*p;
	printf("\n\nEnter item to be deleted: ");
	scanf("%d",&key);
	if(head->number == key)
	{
		p = head -> next;
		free(head);
		head = p;
	}
	else
	{
		n1 = find(head,key);
		if(n1 == NULL)
			printf("\n\nNot Found!!");
		else
		{
			p = n1->next->next;
			free(n1->next);
			n1->next = p;
		}
	}
	return (head);
}
void swap(node *a,node *b)
{
	int temp = a->number;
	a->number = b->number;
	b->number = temp;
}
void sort(node *head)
{
	int swapped;
	node *ptr1;
	node * iptr = NULL;
	do
	{
		swapped = 0;
		ptr1 = head;
		while(ptr1->next != iptr)
		{
			if(ptr1->number > ptr1->next->number)
			{
				swap(ptr1,ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		iptr = ptr1;
	}
	while(swapped);
}
node *del_n(node *head,int n)
{
	int i;
	node *temp = head, *t1;
	for(i=1;i<=n;++i)
		temp = temp->next;
	temp->number = temp->next->number;
	t1 = temp->next->next;
	free(temp->next);
	temp->next = t1;
	return(head);
}
node *reversal(node *head)
{
	node *temp, *iptr = NULL;
	for(;iptr != head;)
	{
		temp = head;
		for(;temp->next != iptr;)
		{
			swap(temp,temp->next);
			temp = temp->next;
		}
		iptr = temp;
	}
	return(head);	
}
void main()
{
	int n;
	node *head;
	printf("\n\nEnter the elements: \n");
	void create(node *p);
	void print(node *p);
	head = (node*)malloc(sizeof(node));
	create(head);
	printf("\n\n");
	printf("\n\nThe Linked List is: \n");
	print(head);
	printf("\n\n");
	printf("\n\nInsert an element: \n");
	head = insert(head);
	printf("\n\n");
	printf("\n\nThe New Linked List is: \n");
	print(head);
	printf("\n\n");
	printf("\n\nREVERSING THE LIST! \n");
	head = reversal(head);
	printf("\n\nThe New Linked List is: \n");
	print(head);
	printf("\n\n");
	printf("\n\nDelete an element: \n");
	head = delete(head);
	printf("\n\nThe New Linked List is: \n");
	print(head);
	printf("\n\n");
	printf("\n\nSORTING!! \n");
	sort(head);
	printf("\n\n");
	printf("\n\nThe New Linked List is: \n");
	print(head);
	printf("\n\n");
	printf("\n\nDelete an element from nth position, Enter n: ");
	scanf("%d",&n);
	head = del_n(head,n);
	printf("\n\nThe New Linked List is: \n");
	print(head);
	printf("\n\n");
}	
	
	
	
	
	
	
	
	
	
	






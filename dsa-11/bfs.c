#include <stdio.h>
#include <stdlib.h>

#define white 0
#define gray 1
#define black 2

struct AdjNode 
{
    int data;
    int color;
    int d;
    struct AdjNode* next;
    struct AdjNode* p;
};

struct QueueNode
{
    struct AdjNode* Node;
    struct QueueNode* next;
    struct QueueNode* prev;
};

struct Queue
{
    struct QueueNode* head;
    struct QueueNode* tail;
    int n;
};

void enqueue(struct Queue* Q, struct AdjNode* item)
{
    struct QueueNode* new_Node = (struct QueueNode*) malloc (sizeof(struct QueueNode));
    new_Node->Node = item;
    new_Node->next = NULL;
    new_Node->prev = NULL;

    if (Q->head == NULL)
    {
        Q->head = new_Node;
        Q->tail = Q->head;
        Q->n = 1;
    }

    else
    {
        new_Node->prev = Q->tail;
        Q->tail->next = new_Node;
        Q->tail = Q->tail->next; 
        Q->n ++;
    }

}

struct AdjNode* dequeue(struct Queue* Q)
{
    if (Q->head == NULL)
    {
        printf ("\n\n\tError: Underflow");
        return NULL;
    }
    struct AdjNode* return_Node = Q->head->Node;
    Q->head = Q->head->next;
    Q->head->prev = NULL;

    if (Q->head == NULL)
    {
        Q->tail == NULL;
    }
    Q->n --;
    return return_Node;
}

int isEmpty(struct Queue* Q)
{
    return (Q->n == 0);
}

struct AdjList
{
    struct AdjNode* head;
};

struct Graph
{
    int V;
    struct AdjList* Edges;
};

struct Graph* createGraph (int v)
{
    struct Graph* graph = (struct Graph*) malloc (sizeof(struct Graph));
    graph->V = v;

    graph->Edges = (struct AdjList*) malloc (v*sizeof(struct AdjList));
    for (int i = 0; i < v; i++ )
    {
        graph->Edges[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjNode* new_Node = (struct AdjNode*) malloc (sizeof(struct AdjNode));
    new_Node->data = dest;
    new_Node->next = graph->Edges[src].head;
    graph->Edges[src].head = new_Node;

    new_Node = (struct AdjNode*) malloc (sizeof(struct AdjNode));
    new_Node->data = src;
    new_Node->next = graph->Edges[dest].head;
    graph->Edges[dest].head = new_Node;    
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjNode* pCrawl = graph->Edges[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void BFS(struct Graph* graph, int s)
{

}

int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    printGraph(graph);
 
    return 0;
}
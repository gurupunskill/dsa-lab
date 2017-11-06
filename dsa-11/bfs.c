#include <stdio.h>
#include <stdlib.h>

#define white 0
#define gray 1
#define black 2
#define INF 32767

struct QNode
{
    int key;
    struct QNode *next;
};
struct Queue
{
    struct QNode *front, *rear;
};
struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp; 
}
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue *q, int k)
{
    struct QNode *temp = newNode(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}
int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    return -1;
    
    struct QNode *temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL)
    q->rear = NULL;
    return temp->key;
}
int isEmpty(struct Queue* Q)
{
    return (Q->front == NULL);
}

struct AdjNode 
{
    int data;
    int color;
    int d;
    struct AdjNode* next;
    struct AdjNode* P;
};
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
        graph->Edges[i].head = (struct AdjNode*) malloc (sizeof(struct AdjNode));
        graph->Edges[i].head->data = i;
        graph->Edges[i].head->next = NULL;        
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjNode* new_Node = (struct AdjNode*) malloc (sizeof(struct AdjNode));
    new_Node->data = dest;
    new_Node->next = graph->Edges[src].head->next;
    graph->Edges[src].head->next = new_Node;

    new_Node = (struct AdjNode*) malloc (sizeof(struct AdjNode));
    new_Node->data = src;
    new_Node->next = graph->Edges[dest].head->next;
    graph->Edges[dest].head->next = new_Node;    
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
    int i;
    for (i = 0; i < graph->V; i++)
    {
        if ( i == s )
            continue;
        graph->Edges[i].head->color = white;
        graph->Edges[i].head->d = INF;
        graph->Edges[i].head->P = NULL;
        
    }
    graph->Edges[s].head->color = gray;
    graph->Edges[s].head->d = 0;
    graph->Edges[s].head->P = NULL;

    struct Queue* Q = createQueue();
    enqueue(Q, s);

    while (!isEmpty(Q))
    {
        //printf ("\nk");
        struct AdjNode *U, *V, *W;
        U = graph->Edges[dequeue(Q)].head;
        printf ("\n\n Dequeued %d %d", U->data, U->d);
        
        W = U->next;
        V = graph->Edges[W->data].head;
        while(W != NULL)
        {
            if (V->color == white)
            {
                V->color = gray;  
                V->d = U->d + 1;
                V->P = U;
                enqueue(Q, V->data);
            }
            W = W->next;
            V = graph->Edges[W->data].head;
        }
    }

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
    BFS(graph, 1);
    printf ("\n\n\n");
    return 0;
}
#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *link;
};

int size;
struct node *adjList;
int *visited;

void initialiseAdjList(int size);
void addVertices(int source, int destination);
void DFStraversel(int vertex);
void BFStraversel(int vertex);

int main()
{
    printf("Enter total no. of nodes: ");
    scanf("%d", &size);

    visited = (int *)malloc(sizeof(int) * size);

    adjList = (struct node *)malloc(sizeof(struct node) * size);

    initialiseAdjList(size);

    while (1)
    {
        int source;
        printf("Enter node source(-1 for exit): ");
        scanf("%d", &source);

        if (source == -1)
        {
            break;
        }

        int destination;
        printf("Enter node destination: ");
        scanf("%d", &destination);

        addVertices(source, destination);
    }

    int startVertex;
    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    printf("Using Depth First Search (DFS) : [");
    DFStraversel(startVertex);
    printf("]\n");

    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    BFStraversel(startVertex);

    return 0;
}

void initialiseAdjList(int size)
{
    for (int i = 0; i < size; i++)
    {
        adjList[i].info = i;
        adjList[i].link = NULL;
    }
}

void addVertices(int source, int destination)
{
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    new1->info = destination;
    new1->link = adjList[source].link;
    adjList[source].link = new1;

    struct node *new2 = (struct node *)malloc(sizeof(struct node));
    new2->info = source;
    new2->link = adjList[destination].link;
    adjList[destination].link = new2;
}

void DFStraversel(int vertex)
{
    visited[vertex] = 1;
    printf("%d ",vertex);

    struct node *save = adjList[vertex].link;

    while (save != NULL)
    {
        if (!visited[save->info])
        {
            DFStraversel(save->info);
        }
        save = save->link;
    }
}

void BFStraversel(int vertex)
{
    int *queue = (int *)malloc(sizeof(int) * size);
    int front = 0, rear = 0;
    visited[vertex] = 1;
    queue[rear++] = vertex;
    printf("Using Breadth First Search (BFS) : [%d ",vertex);

    struct node *save = adjList[vertex].link;

    while (front != rear)
    {
        if (save == NULL)
        {
            vertex = queue[front++];
            save = adjList[vertex].link;
        }
        else if (visited[save->info] == 0)
        {
            visited[save->info] = 1;
            queue[rear++] = save->info;
            printf("%d ",save->info);
            save = save->link;
        }
        else
        {
            save = save->link;
        }
    }
    printf("]\n");
}
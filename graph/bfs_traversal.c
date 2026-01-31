#include <stdio.h>

int n, adj[10][10], visited[10], queue[10];
int front = -1, rear = -1;

void bfs(int start)
{
    int i;
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear)
    {
        start = queue[++front];
        printf("%d ", start);

        for (i = 0; i < n; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}

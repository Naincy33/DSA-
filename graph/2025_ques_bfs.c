#include <stdio.h>

int adj[10][10], visited[10], queue[10];
int n = 4, front = -1, rear = -1;

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
    int i, j;

    /* Adjacency matrix for 4 vertices & 6 edges */
    int matrix[4][4] = {
        {0,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,1,1,0}
    };

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
            adj[i][j] = matrix[i][j];
    }

    printf("BFS Traversal starting from Control Room (0): ");
    bfs(0);

    return 0;
}

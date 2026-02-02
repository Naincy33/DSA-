#include <stdio.h>

int n, adj[10][10], visited[10];

void dfs(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

/* Function to check connected graph */
int isConnected()
{
    int i;

    dfs(0);   // start DFS from vertex 0

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            return 0;   // not connected
    }
    return 1;           // connected
}
int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    if (isConnected())
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    return 0;
}
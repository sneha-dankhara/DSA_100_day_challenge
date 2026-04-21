#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int neigh = temp->data;

        if (!visited[neigh]) {
            dfs(neigh, adj, visited);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m, directed, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Is graph directed? (1 for YES, 0 for NO): ");
    scanf("%d", &directed);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);

        if (!directed)
            addEdge(adj, v, u);
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");

    dfs(start, adj, visited);

    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;

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
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    printf("Enter edges:\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
    }

    int visited[n + 1];

    for (int i = 0; i <= n; i++)
        visited[i] = 0;

    // start DFS from node 1
    dfs(1, adj, visited);

    int isConnected = 1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            isConnected = 0;
            break;
        }
    }

    if (isConnected)
        printf("\nCONNECTED\n");
    else
        printf("\nNOT CONNECTED\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Add edge (u -> v)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m, directed;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Is the graph directed? (1 for YES, 0 for NO): ");
    scanf("%d", &directed);

    // adjacency list array
    struct Node* adj[n];

    // initialize all lists as NULL
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);

        if (!directed) {
            addEdge(adj, v, u);
        }
    }

    printf("\nAdjacency List:\n");

    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);

        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }

    return 0;
}
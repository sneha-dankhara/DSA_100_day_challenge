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

// Queue structure
struct Queue {
    int items[1000];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(struct Queue* q, int val) {
    q->items[q->rear++] = val;
}

int dequeue(struct Queue* q) {
    return q->items[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void bfs(struct Node* adj[], int n, int start) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    struct Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    printf("\nBFS Traversal: ");

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        struct Node* temp = adj[node];

        while (temp != NULL) {
            int neigh = temp->data;

            if (!visited[neigh]) {
                visited[neigh] = 1;
                enqueue(&q, neigh);
            }

            temp = temp->next;
        }
    }

    printf("\n");
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

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}
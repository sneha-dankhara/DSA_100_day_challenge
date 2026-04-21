#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

struct Node {
    int data;
    int weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;

    // undirected graph (remove if directed)
    node = createNode(u, w);
    node->next = adj[v];
    adj[v] = node;
}

// Min Heap (Priority Queue)
struct Pair {
    int node;
    int dist;
};

struct Pair heap[100000];
int size = 0;

void swap(struct Pair* a, struct Pair* b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    int i = size++;
    
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].dist <= heap[i].dist)
            break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

struct Pair pop() {
    struct Pair top = heap[0];
    heap[0] = heap[--size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right < size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return top;
}

int isEmpty() {
    return size == 0;
}

void dijkstra(struct Node* adj[], int n, int src) {
    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    push(src, 0);

    while (!isEmpty()) {
        struct Pair curr = pop();
        int u = curr.node;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->data;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

int main() {
    int n, m, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v w):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);

        addEdge(adj, u, v, w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(adj, n, src);

    return 0;
}
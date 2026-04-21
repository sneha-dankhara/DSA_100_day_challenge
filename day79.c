#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->w = w;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u, w);
    node->next = adj[v];
    adj[v] = node; // undirected graph
}

// Min Heap
struct Pair {
    int node;
    int dist;
};

struct Pair heap[100000];
int size = 0;

void swap(struct Pair* a, struct Pair* b) {
    struct Pair t = *a;
    *a = *b;
    *b = t;
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
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < size && heap[l].dist < heap[smallest].dist)
            smallest = l;

        if (r < size && heap[r].dist < heap[smallest].dist)
            smallest = r;

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

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    int dist[n + 1];

    for (int i = 0; i <= n; i++)
        dist[i] = INF;

    dist[src] = 0;

    push(src, 0);

    while (!isEmpty()) {
        struct Pair curr = pop();
        int u = curr.node;
        int d = curr.dist;

        if (d > dist[u])
            continue;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}
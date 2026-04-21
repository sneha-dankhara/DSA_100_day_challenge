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
    adj[v] = node;
}

// Min Heap
struct Pair {
    int node;
    int weight;
};

struct Pair heap[100000];
int size = 0;

void swap(struct Pair* a, struct Pair* b) {
    struct Pair t = *a;
    *a = *b;
    *b = t;
}

void push(int node, int weight) {
    heap[size].node = node;
    heap[size].weight = weight;

    int i = size++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].weight <= heap[i].weight)
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

        if (l < size && heap[l].weight < heap[smallest].weight)
            smallest = l;

        if (r < size && heap[r].weight < heap[smallest].weight)
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

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v w):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(adj, u, v, w);
    }

    int visited[n + 1];

    for (int i = 0; i <= n; i++)
        visited[i] = 0;

    int mstWeight = 0;

    // start from node 1
    push(1, 0);

    while (!isEmpty()) {
        struct Pair curr = pop();

        int u = curr.node;
        int w = curr.weight;

        if (visited[u])
            continue;

        visited[u] = 1;
        mstWeight += w;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            if (!visited[temp->v]) {
                push(temp->v, temp->w);
            }
            temp = temp->next;
        }
    }

    printf("\nTotal weight of MST: %d\n", mstWeight);

    return 0;
}
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
}

// Queue
int queue[1000];
int front = 0, rear = 0;

void enqueue(int val) {
    queue[rear++] = val;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[n];

    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        indegree[v]++;
    }

    // push all 0 indegree nodes
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("\nTopological Order: ");

    int count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];

        while (temp != NULL) {
            indegree[temp->data]--;

            if (indegree[temp->data] == 0) {
                enqueue(temp->data);
            }

            temp = temp->next;
        }
    }

    printf("\n");

    // optional cycle check
    if (count != n)
        printf("Graph has a cycle (Topological sort not possible)\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    int hd; // horizontal distance
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = node;
    newNode->hd = hd;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

struct QueueNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return temp;
}

// Create new tree node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Free tree
void freeTree(struct Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // We'll use a dynamic array of linked lists for simplicity
    // Find min and max HD first
    int minHD = 0, maxHD = 0;
    struct Queue* q = createQueue();
    enqueue(q, root, 0);

    struct QueueNode* temp;
    while (q->front) {
        temp = dequeue(q);
        struct Node* node = temp->treeNode;
        int hd = temp->hd;
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left) enqueue(q, node->left, hd - 1);
        if (node->right) enqueue(q, node->right, hd + 1);
        free(temp);
    }

    // Prepare array of linked lists for each vertical
    int width = maxHD - minHD + 1;
    struct Node** verticals = (struct Node**)malloc(width * sizeof(struct Node*));
    int* counts = (int*)calloc(width, sizeof(int));
    for (int i = 0; i < width; i++) verticals[i] = NULL;

    // Fill verticals again using level-order traversal
    enqueue(q, root, -minHD); // shift HD to 0-based index
    while (q->front) {
        temp = dequeue(q);
        struct Node* node = temp->treeNode;
        int hd = temp->hd;

        // Add node to vertical
        if (verticals[hd] == NULL) verticals[hd] = (struct Node*)malloc(sizeof(struct Node) * 1000); // max 1000 nodes per vertical
        verticals[hd][counts[hd]++] = *node;

        if (node->left) enqueue(q, node->left, hd - 1);
        if (node->right) enqueue(q, node->right, hd + 1);
        free(temp);
    }

    // Print verticals
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < counts[i]; j++) {
            printf("%d ", verticals[i][j].data);
        }
        printf("\n");
        free(verticals[i]);
    }

    free(verticals);
    free(counts);
    free(q);
}

// ---------------- MAIN ----------------
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tree is empty.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d space-separated node values (-1 for NULL):\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build tree from level-order
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root, 0);
    int i = 1;

    while (i < n) {
        struct Node* parent = dequeue(q)->treeNode;
        if (!parent) continue;

        if (i < n) {
            parent->left = newNode(arr[i++]);
            if (parent->left) enqueue(q, parent->left, 0);
        }
        if (i < n) {
            parent->right = newNode(arr[i++]);
            if (parent->right) enqueue(q, parent->right, 0);
        }
    }

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    freeTree(root);
    free(q);
    return 0;
}
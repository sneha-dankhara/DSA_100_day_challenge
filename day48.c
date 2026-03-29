#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node for level-order construction
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Queue structure
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// ---------------- QUEUE OPERATIONS ----------------
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

// ---------------- TREE OPERATIONS ----------------
struct Node* newNode(int val) {
    if (val == -1) return NULL; // -1 represents NULL
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Count leaf nodes recursively
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Free tree memory
void freeTree(struct Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ---------------- MAIN ----------------
int main() {
    int n;

    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The tree is empty.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d space-separated node values in level-order (-1 for NULL):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Build tree from level-order
    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct Node* parent = dequeue(q);
        if (!parent) continue;

        // Left child
        if (i < n) {
            parent->left = newNode(arr[i++]);
            if (parent->left) enqueue(q, parent->left);
        }

        // Right child
        if (i < n) {
            parent->right = newNode(arr[i++]);
            if (parent->right) enqueue(q, parent->right);
        }
    }

    // Count leaf nodes
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes in the tree: %d\n", leafCount);

    // Free memory
    freeTree(root);
    free(q);

    return 0;
}
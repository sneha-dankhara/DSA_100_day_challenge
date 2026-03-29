#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for level-order construction
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// ---------------- Queue Operations ----------------
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (!q->rear) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

struct Node* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// ---------------- Tree Operations ----------------
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void freeTree(struct Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ---------------- Inorder Traversal ----------------
void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ---------------- Mirror Function ----------------
void mirror(struct Node* root) {
    if (!root) return;
    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
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
    enqueue(q, root);
    int i = 1;

    while (i < n) {
        struct Node* parent = dequeue(q);
        if (!parent) continue;

        if (i < n) {
            parent->left = newNode(arr[i++]);
            if (parent->left) enqueue(q, parent->left);
        }
        if (i < n) {
            parent->right = newNode(arr[i++]);
            if (parent->right) enqueue(q, parent->right);
        }
    }

    // Mirror the tree
    mirror(root);

    printf("Inorder Traversal of Mirrored Tree:\n");
    inorder(root);
    printf("\n");

    freeTree(root);
    free(q);
    return 0;
}
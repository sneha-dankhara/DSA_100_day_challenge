#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new BST node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert value into BST
struct Node* insertBST(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    return root; // duplicates ignored
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (!root) return NULL;

    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    return root; // root is between n1 and n2 → LCA
}

// Free BST memory
void freeTree(struct Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ---------------- MAIN ----------------
int main() {
    int n, val, node1, node2;

    printf("Enter the number of nodes in BST: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("BST is empty.\n");
        return 0;
    }

    struct Node* root = NULL;
    printf("Enter %d space-separated node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertBST(root, val);
    }

    printf("Enter two node values to find LCA: ");
    scanf("%d %d", &node1, &node2);

    struct Node* lca = findLCA(root, node1, node2);
    if (lca)
        printf("Lowest Common Ancestor of %d and %d is: %d\n", node1, node2, lca->data);
    else
        printf("LCA not found (one or both nodes are missing in BST).\n");

    freeTree(root);
    return 0;
}
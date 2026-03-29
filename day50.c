#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new BST node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert a value into BST
struct Node* insertBST(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    // duplicates are ignored
    return root;
}

// Search a value in BST
int searchBST(struct Node* root, int key) {
    if (root == NULL) return 0; // not found
    if (root->data == key) return 1; // found
    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// Inorder traversal of BST
void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    int n, val, key;

    printf("Enter the number of values to insert into BST: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No values to insert.\n");
        return 0;
    }

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        root = insertBST(root, val);
    }

    printf("BST Inorder Traversal (sorted order):\n");
    inorder(root);
    printf("\n");

    printf("Enter the value to search in BST: ");
    scanf("%d", &key);

    if (searchBST(root, key))
        printf("Value %d found in BST.\n", key);
    else
        printf("Value %d NOT found in BST.\n", key);

    // Free memory
    freeTree(root);

    return 0;
}
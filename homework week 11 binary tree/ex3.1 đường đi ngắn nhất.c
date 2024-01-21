#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isLeaf(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 1;
    }

    return 0;
}

void insert(BinaryTree* tree, int data) {
    TreeNode* newNode = makeNode(data);

    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    TreeNode* current = tree->root;
    TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

int getHeight(TreeNode* node) {
    if (node == NULL)
        return 0;
    else {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

int getShortBranch(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (isLeaf(root))
        return 1;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (leftHeight < rightHeight)
        return 1 + getShortBranch(root->left);
    else
        return 1 + getShortBranch(root->right);
}

int main() {
    BinaryTree tree;
    tree.root = NULL;

    // Thêm các node vào cây
    insert(&tree, 5);
    insert(&tree, 3);
    insert(&tree, 8);
    insert(&tree, 1);
    insert(&tree, 4);
    insert(&tree, 7);
    insert(&tree, 299);
    insert(&tree, 6);

    int soluong = getShortBranch(tree.root);
    printf("Số phần tử trên nhánh có số phần tử ít nhất: %d\n", soluong);

    return 0;
}
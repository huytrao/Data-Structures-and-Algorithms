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

int sum_Node_1_leaf(TreeNode* root) {
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right != NULL)
        return root->data + sum_Node_1_leaf(root->right);
    
    if (root->right == NULL && root->left != NULL)
        return root->data + sum_Node_1_leaf(root->left);
    
    return sum_Node_1_leaf(root->left) + sum_Node_1_leaf(root->right);
}

int sum_Node_1_leaf_left(TreeNode* root) {
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right != NULL)
        return root->data + sum_Node_1_leaf_left(root->right);
    
    return sum_Node_1_leaf_left(root->left) + sum_Node_1_leaf_left(root->right);
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
    insert(&tree, 2);

    int sum_1_leaf = sum_Node_1_leaf(tree.root);
    int sum_1_leaf_right = sum_Node_1_leaf_left(tree.root);
    printf("Tổng giá trị các nút có một nút con: %d\n", sum_1_leaf -  sum_1_leaf_right);
    
    return 0;
}
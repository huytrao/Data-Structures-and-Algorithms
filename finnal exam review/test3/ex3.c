
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
void delete(BinaryTree* tree, int val) {
    // search the val
    TreeNode* curr = tree->root;
    TreeNode* prev = NULL;
    while (1) {
        if (curr == NULL)    // not found
            return;
        if (curr->data == val) {    // found
            // xóa nút hiện tại

            // case 1: không leaf
            if (curr->left == NULL && curr->right == NULL) {
                free(curr);
                if (prev == NULL) {
                    tree->root = NULL;
                }
                else {
                    if (prev->data > val) {
                        prev->left = NULL;
                    }
                    else {
                        prev->right = NULL;
                    }
                }
                return;
            }
            // case 2: one child
            if (curr->left == NULL) {
                if (prev == NULL) {
                    printf("\nDelete at root");
                    tree->root = curr->right;
                }
                else {
                    if (prev->data > val) {
                        prev->left = curr->right;
                    }
                    else {
                        prev->right = curr->right;
                    }
                }
                free(curr);
                return;
            } 
            if (curr->right == NULL) {
                if (prev == NULL) {
                    printf("\nDelete at root");
                    tree->root = curr->left;
                }
                else {
                    if (prev->data > val) {
                        prev->left = curr->left;
                    }
                    else {
                        prev->right = curr->left;
                    }
                }
                free(curr);
                return;
            }

            // case 3: 2 children (leafs)
            if (isLeaf(curr->left) && isLeaf(curr->right)) {
                // copy data from the right
                curr->data = curr->right->data;
                free(curr->right);
                curr->right = NULL;
                return;
            }
            // case 4: nếu bên phải không có leaf
            if (!isLeaf(curr->right)) {
                TreeNode* leftMost = curr->right;
                TreeNode* parent = NULL;
                while (!isLeaf(leftMost)) {
                    parent = leftMost;
                    leftMost = leftMost->left;
                }
                printf("\nLeaf data %d", leftMost->data);
                curr->data = leftMost->data;
                free(leftMost);
                parent->left = NULL;
                return;
            }
        }
        prev = curr;
        if (curr->data > val) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}





void deleteNegNumbers(BinaryTree* tree, TreeNode* node) {
    if (node == NULL) {
        return;
    }

    deleteNegNumbers(tree, node->left);
    deleteNegNumbers(tree, node->right);

    if (node->data < 0) {
        delete(tree, node->data);
    }
}
void print(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("\n%d", node->data);
    print(node->left);
    print(node->right);
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
      insert(&tree, -1);
      insert(&tree, -99);
       insert(&tree, -34);
        insert(&tree, -4);
        insert(&tree, -8);
   
    deleteNegNumbers(&tree,tree.root);
    print(tree.root);

}
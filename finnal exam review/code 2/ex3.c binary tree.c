
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

int maxBranchSum(TreeNode* node, int currentSum) {
    if (node == NULL) {
        return currentSum;
    }

    int newSum = currentSum + node->data;

    if (isLeaf(node)) {
        return newSum;
    }

    int leftSum = maxBranchSum(node->left, newSum);
    int rightSum = maxBranchSum(node->right, newSum);

    return (leftSum > rightSum) ? leftSum : rightSum;
}

int getMaxBranchSum(BinaryTree* tree) {
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }

    return maxBranchSum(tree->root, 0);
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

int getMaxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = getMaxDepth(root->left);
    int rightDepth = getMaxDepth(root->right);
    
    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
}

void getAllMaxBranchSums(TreeNode* node, int currentSum, int currentDepth, int maxDepth, int* maxSums) {
    if (node == NULL) {
        return;
    }

    currentSum += node->data;

    if (isLeaf(node) || currentDepth > maxDepth) {
        maxSums[currentDepth] += currentSum;
        return;
    }

    getAllMaxBranchSums(node->left, currentSum, currentDepth + 1, maxDepth, maxSums);
    getAllMaxBranchSums(node->right, currentSum, currentDepth + 1, maxDepth, maxSums);
}

int getMaxBranchSums(TreeNode* root) {
    int maxDepth = getMaxDepth(root);
    int* maxSums = (int*)malloc(sizeof(int) * maxDepth);

    
    int maxBranchSum = 0;
    
    
    
    free(maxSums);
    
    return maxBranchSum;
}
// in chiều cao của node này
int getHeight(TreeNode* node) {
    if (node == NULL)
        return 0;
    else {
        // thwucj hiện lấy chiều cao bên phải
        //lấy chiều cao bên trái
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        // kiểm tra cái nào cao hơn để r=trả về kết quả hợp lí 
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}


int getLongBranch(TreeNode* root, int* sum, int high) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    
    if (root->left == NULL) {
        return root->data + getLongBranch(root->right, sum, high - 1);
    }
    
    if (root->right == NULL) {
        return root->data + getLongBranch(root->left, sum, high - 1);
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if (leftHeight > rightHeight) {
        return root->data + getLongBranch(root->left, sum, high - 1);
    } else {
        return root->data + getLongBranch(root->right, sum, high - 1);
    }
}
void deleteOddNumbers(BinaryTree* tree, TreeNode* node) {
    if (node == NULL) {
        return;
    }

    deleteOddNumbers(tree, node->left);
    deleteOddNumbers(tree, node->right);

    if (node->data != 0 && node->data % 2 != 0) {
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
    
    int maxSum = getMaxBranchSum(&tree); 
    int high;
    int sum;
    int maxlongsum = getLongBranch(tree.root,&sum,high);
    deleteOddNumbers(&tree,tree.root);
    print(tree.root);
    printf("Tong du lieu tren nhanh co tong: %d\n", maxSum);
    printf("Tong du lieu tren nhanh dai nhat tat ca cac : %d\n", maxlongsum);
}
//Câu 1 trong file nhị phân tìm kiếm thì nó sai bởi vì số 7 liên kết bị sai số bảy 
// số 8 phải trỏ tới bên trái là số 7 
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType* left;
    struct NodeType* right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode* s = (TreeNode*)malloc(sizeof(TreeNode));
    s->data = data;
    s->left = NULL;
    s->right = NULL;
    return s;
}

void print(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    print(node->left);
    print(node->right);
}

void init(BinaryTree* tree) {
    tree->root = NULL;
}

void insert(BinaryTree* tree, int data) {
    TreeNode* temp = tree->root;
    TreeNode* pre = NULL;
    TreeNode* temp2 = makeNode(data);

    if (tree->root == NULL) {
        tree->root = temp2;
        return;
    }

    while (temp != NULL) {
        pre = temp;
        if (data < temp->data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    if (pre->data < data) {
        pre->right = temp2;
    }
    else {
        pre->left = temp2;
    }
}

void delete(TreeNode* node, int value) {
    if (node == NULL) {
        return;
    }

    TreeNode* parent = NULL;
    TreeNode* current = node;

    // Tìm node cần xoá và node cha của nó
    while (current != NULL && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    // Nếu không tìm thấy node cần xoá
    if (current == NULL) {
        printf("Khong tim thay gia tri %d trong cay.\n", value);
        return;
    }

    // Xoá node lá
    if (current->left == NULL && current->right == NULL) {
        if (parent->left == current) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
        free(current);
    }
    // Xoá node có một con
    else if (current->left == NULL || current->right == NULL) {
        TreeNode* child;
        if (current->left != NULL) {
            child = current->left;
        }
        else {
            child = current->right;
        }

        if (parent->left == current) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
        free(current);
    }
    // Xoá node có hai con
    else {
        TreeNode* successor = current->right;
        TreeNode* successorParent = current;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        if (successorParent != current) {
            successorParent->left = successor->right;
            successor->right = current->right;
        }

        successor->left = current->left;

        if (parent->left == current) {
            parent->left = successor;
        }
        else {
            parent->right = successor;
        }

        free(current);
    }
}

int main() {
    BinaryTree tree;
    init(&tree);

    int arr[12] = { 34, 10, 75, 8, 29, 65, 19, 50, 70, 7, 26, 55 };
    int i;

    for (i = 0; i < 12; i++) {
        insert(&tree, arr[i]);
    }

    printf("Cay nhi phan sau khi nhap: ");
    print(tree.root);
    printf("\n");

    delete(tree.root, 7);
    printf("Cay nhi phan sau khi xoa 7: ");
    print(tree.root);
    printf("\n");

    delete(tree.root, 50);
    printf("Cay nhi phan sau khi xoa 50: ");
    print(tree.root);
    printf("\n");

    delete(tree.root, 65);
    printf("Cay nhi phan sau khi xoa 65: ");
    print(tree.root);
    printf("\n");

    return 0;
}
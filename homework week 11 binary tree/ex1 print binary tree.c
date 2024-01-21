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
    TreeNode *s =  (TreeNode*)malloc(sizeof(TreeNode));
    // ham data 
    s->data = data;
    s->right = NULL;
    s->right = NULL;
    return s;
}

void print(TreeNode* node) {
    if(node == NULL )
    {
        return;
    }
    printf("\n %d",node->data);
    print(node->left);
    print(node->right);
 }

void init(BinaryTree* tree) {
    tree->root = NULL;
}
// hàm tìm kiếm cây nhị phân
TreeNode* search(TreeNode* node, int val) {
   
//    while (1) {
        if (node == NULL || node->data == val)
            return node;
        else if (val < node->data)
            return search(node->left, val);
        else if (val > node->data)
            return search(node->right, val);
//    }
}

// hàm insert
void insert(BinaryTree* tree, int data) { 
    TreeNode * temp = tree->root;
    TreeNode * pre = NULL;
    TreeNode * temp2 = makeNode(data);
    // trường hợp insert ở đầu
    if(tree->root == NULL)
    {
        // kiểm tra 
        tree->root = temp2;
        return;
    }
    // di chuyển về vị trí lá thích hợp
    while(temp != NULL)
    {
        pre = temp;
        if(data < temp->data)
        {
            temp = temp->left;
        }
        else{
            temp= temp->right;
        }
    }
    // thực hiện lệnh chèn
    if(pre->data < data)
    {
        pre->right = temp2;
    }else 
    {
        pre->left = temp2;
    }
}
// hàm xóa nút binary tree tìm và xóa giá trị 
void delete(BinaryTree* tree, int val) {
    // search the val
    TreeNode* curr = tree->root;
    TreeNode* prev = NULL;
    while (1) {
        if (curr == NULL)    // not found
            return;
        if (curr->data == val) {    // found
            // delete the curr node

            // case 1: no child / leaf
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
            // case 4: curr->right is not a leaf
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

int main() {
    BinaryTree tree,tree3,tree2,tree4;
    TreeNode *node,*node2, *node3,*node4;
    init(&tree);
    int value = 25;
    //In 1.1 các cây ở câu 1.1
    printf("\ncâu 1.1\n");
    for(int i=1;i<=15;i++)
    {
        insert(&tree,i);
    }
    // search 1.1
    node = search(tree.root,value);
    if(node == NULL)
    {
        printf("\n 1.1 NOT FOUND! %d\n",value);
    }
    else{
         printf("Value %d found at address %p\n", node->data, (void*)node);
    }

   
   
    // in câu 1.2
     init(&tree2);
    
    int arr22[11] = {50,17,76,9,23,54,14,19,72,12,67};
    for(int i=0;i<11;i++)
    {
        insert(&tree2,arr22[i]);
    }
     // search 1.2
    node2 = search(tree2.root,value);
    if(node2 == NULL)
    {
        printf("\n 1.2 NOT FOUND! %d\n",value);
    }
    else{
         printf("\nValue %d found at address %p\n", node2->data, (void*)node2);
    }
    // print(tree2.root);


     // in câu 1.3
    printf("\n Câu 1.3");
    init(&tree3);
    int arr33[11] = {15,11,26,8,12,20,30,6,9,14,35};
    for(int i=0;i<11;i++)
    {
        insert(&tree3,arr33[i]);
    }
         // search 1.3
    node3 = search(tree3.root,value);
    if(node3 == NULL)
    {
        printf("\n 1.3 NOT FOUND! %d\n",value);
    }
    else{
         printf("\nValue %d found at address %p\n", node3->data, (void*)node3);
    }
    // in câu 1.4
    printf("\n Câu 1.4");
    init(&tree4);
    int arr44[13] = {3,1,10,13,5,11,16,6,15,2,9,4};
    for(int i=0;i<12;i++)
    {
        insert(&tree4,arr44[i]);
    }
    node4 = search(tree4.root,value);
    if(node4 == NULL)
    {
        printf("\n 1.4 NOT FOUND! %d\n",value);
    }
    else{
         printf("\nValue %d found at address %p\n", node4->data, (void*)node4);
    }
    return 0;
}
